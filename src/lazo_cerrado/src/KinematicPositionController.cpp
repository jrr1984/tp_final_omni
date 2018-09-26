#include <angles/angles.h>
#include "KinematicPositionController.h"
#include "tf_utils.hpp"
#include <tf/tf.h>
#include <nav_msgs/Odometry.h>

KinematicPositionController::KinematicPositionController(ros::NodeHandle& nh) :
  TrajectoryFollower(nh), transform_listener_( tfBuffer_ ), vel_real_start_(false)
{
    expected_position_pub = nh.advertise<geometry_msgs::PoseStamped>("/goal_pose", 1);
    ground_truth_position_pub = nh.advertise<nav_msgs::Odometry>("/robot/ground_truth", 1);
    base_link_ekf_position_pub = nh.advertise<nav_msgs::Odometry>("/robot/base_link_ekf_pose", 1);
    //real_velocity_sub = nh.subscribe("/robot/ground_truth",1,&KinematicPositionController::getRealVelocity,this);
    real_velocity_pub = nh.advertise<nav_msgs::Odometry>("/robot/real_velocity", 1); 
    ros::NodeHandle nhp("~");
    
    std::string goal_selection;
    nhp.param<std::string>("goal_selection", goal_selection, "FIXED_GOAL");
    nhp.param<double>("fixed_goal_x", fixed_goal_x_, 3);     
    nhp.param<double>("fixed_goal_y", fixed_goal_y_, 0);     
    nhp.param<double>("fixed_goal_a", fixed_goal_a_, -M_PI_2);     
    
    if(goal_selection == "TIME_BASED")
      goal_selection_ = TIME_BASED;
    else if(goal_selection == "PURSUIT_BASED")
      goal_selection_ = PURSUIT_BASED;
    else if(goal_selection == "FIXED_GOAL")
      goal_selection_ = FIXED_GOAL;
    else
      goal_selection_ = TIME_BASED; // default
}

/**
 * System is stable if:
 * - 0 < K_RHO
 * - K_RHO < K_ALPHA
 * - K_BETA < 0
 */
#define K_X 0.1
#define K_Y 0.1
#define K_A 0.1

double lineal_interp(const ros::Time& t0, const ros::Time& t1, double y0, double y1, const ros::Time& t)
{
  return y0 + (t - t0).toSec() * (y1 - y0) / (t1 - t0).toSec();
}

bool KinematicPositionController::control(const ros::Time& t, double& v_x, double& v_y, double& w_z)
{
  //    Kinematic Position Control.
  // src: http://cs.gmu.edu/~kosecka/cs485/lec04-control.pdf

  // get vehicle pose from TF (as estimated by odometry) at time 't'.
  double current_x, current_y, current_a;
  if( not getCurrentPose(t, current_x, current_y, current_a) )
    return true;

  // get expected pose at time 't'.
  double goal_x, goal_y, goal_a;

  if( not getCurrentGoal(t, goal_x, goal_y, goal_a) )
    return false;

  publishCurrentGoal(t, goal_x, goal_y, goal_a);

  // compute position differences with expected pose.
  double dx = goal_x - current_x;		
  double dy = goal_y - current_y;
  double da = angles::shortest_angular_distance ( current_a, goal_a);//goal_a - current_a;

  // compute dx,dy,theta in goal reference frame
  double dx_rot = cos(-current_a) * dx - sin(-current_a) * dy;
  double dy_rot = sin(-current_a) * dx + cos(-current_a) * dy;

  // transform error data to polar coordinates.
  // use the control law to compute velocity commands.
  v_x = K_X * dx_rot;
  v_y = K_Y * dy_rot;
  w_z = K_A * da; 

  //ROS_INFO_STREAM("current_x: " << current_x << " current_y: " << current_y << " current_a: " << current_a << " v_x: " << v_x << " v_y: " << v_y << " w_z: " << w_z);
  getGroundTruthPoseAndVel(t);
  getBaseLinkEKFPose(t);
  return true;
}

void KinematicPositionController::getBaseLinkEKFPose(const ros::Time& t)
{ 
  tf2::Transform odom_to_robot_ekf;
  if (not lookupTransformSafe(tfBuffer_, "odom", "base_link_ekf", t, odom_to_robot_ekf))
    return;
  double x,y;
  x = odom_to_robot_ekf.getOrigin().getX();
  y = odom_to_robot_ekf.getOrigin().getY();

  nav_msgs::Odometry msg; 
  msg.pose.pose.position.x = x;
  msg.pose.pose.position.y = y;
  msg.pose.pose.position.z = 0;
  msg.header.stamp = t;
  base_link_ekf_position_pub.publish( msg );
}


bool KinematicPositionController::getCurrentPose(const ros::Time& t, double& x, double& y, double& a)
{
  tf2::Transform odom_to_robot;
  if (not lookupTransformSafe(tfBuffer_, "odom", "base_link_ekf", t, odom_to_robot))
    return false;

  x = odom_to_robot.getOrigin().getX();
  y = odom_to_robot.getOrigin().getY();

  a = tf2::getYaw(odom_to_robot.getRotation());
  return true;
}

void KinematicPositionController::getGroundTruthPoseAndVel(const ros::Time& t)
      {
          tf2::Transform odom_to_robot_ground_truth;
          if (not lookupTransformSafe(tfBuffer_, "odom", "base_link_gt", t, odom_to_robot_ground_truth))
              return;
          
             

            if(not vel_real_start_){
              vel_real_start_ = true;
              x_gt_prev = odom_to_robot_ground_truth.getOrigin().getX();
              y_gt_prev = odom_to_robot_ground_truth.getOrigin().getY();
              prev_time = t;//odom_to_robot_ground_truth.header.stamp; //dame el tiempo en que llegaron las x,y previas
              return;
            }
            
            double delta_x = odom_to_robot_ground_truth.getOrigin().getX() - x_gt_prev;
            double delta_y = odom_to_robot_ground_truth.getOrigin().getY() - y_gt_prev;

            double delta_t = (t - prev_time).toSec(); 

            double v_x_real = delta_x/delta_t;
            double v_y_real = delta_y/delta_t;

            ROS_INFO_STREAM("--- delta t: " << delta_t << " previous: " << prev_time << std::endl);      
            
            nav_msgs::Odometry msg; 
            msg.pose.pose.position.x = x_gt_prev;
            msg.pose.pose.position.y = y_gt_prev;
            msg.pose.pose.position.z = 0;
            msg.twist.twist.linear.x = v_x_real;
            msg.twist.twist.linear.y = v_y_real;
            msg.twist.twist.linear.z = 0;
            msg.pose.pose.orientation = tf::createQuaternionMsgFromYaw(tf2::getYaw(odom_to_robot_ground_truth.getRotation()));
            msg.header.stamp = prev_time;
            msg.header.frame_id = "odom";
            msg.child_frame_id = "base_link_gt";
            ground_truth_position_pub.publish( msg );

            x_gt_prev = odom_to_robot_ground_truth.getOrigin().getX();
            y_gt_prev = odom_to_robot_ground_truth.getOrigin().getY();
            prev_time = t;  
      }



double dist2(double x0, double y0, double x1, double y1)
{ return sqrt((x1-x0)*(x1-x0) + (y1-y0)*(y1-y0));}



bool KinematicPositionController::getPursuitBasedGoal(const ros::Time& t, double& x, double& y, double& a)
{
  // Los obtienen los valores de la posicion y orientacion actual.
  double current_x, current_y, current_a;
  if( not getCurrentPose(t, current_x, current_y, current_a) )
    return true;
    
  // Se obtiene la trayectoria requerida.
  const robmovil_msgs::Trajectory& trajectory = getTrajectory();
  
  /** EJERCICIO 3:
   * Se recomienda encontrar el waypoint de la trayectoria más cercano al robot en términos de x,y
   * y luego buscar el primer waypoint que se encuentre a una distancia predefinida de lookahead en x,y */

   double lookahead_distance = 0.1;
   double distancia_minima = 1000;
   robmovil_msgs::TrajectoryPoint punto_cercano;
   unsigned int i_min;

  /* NOTA: De esta manera les es posible recorrer la trayectoria requerida */  
  for(unsigned int i = 0; i < trajectory.points.size(); i++)
  {
    // Recorren cada waypoint definido
    const robmovil_msgs::TrajectoryPoint& wpoint = trajectory.points[i];
    
    // Y de esta manera puede acceder a la informacion de la posicion y orientacion requerida en el waypoint
    double wpoint_x = wpoint.transform.translation.x;
    double wpoint_y = wpoint.transform.translation.y;
    double wpoint_a = tf2::getYaw(wpoint.transform.rotation);

    if (dist2(current_x, current_y, wpoint_x, wpoint_y) < distancia_minima) {
      punto_cercano = wpoint;
      i_min = i;
      distancia_minima = dist2(current_x, current_y, wpoint_x, wpoint_y);
    }
    
    //...

  }

  robmovil_msgs::TrajectoryPoint next_goal = punto_cercano;
  for(unsigned int i = i_min; i < trajectory.points.size(); i++) {
    next_goal = trajectory.points[i];
    const robmovil_msgs::TrajectoryPoint& wpoint = trajectory.points[i];
    double wpoint_x = wpoint.transform.translation.x;
    double wpoint_y = wpoint.transform.translation.y;
    if (dist2(current_x, current_y, wpoint_x, wpoint_y) > lookahead_distance) {
      break;
    }
  }
   
  x = next_goal.transform.translation.x;
  y = next_goal.transform.translation.y;
  a = tf2::getYaw(next_goal.transform.rotation);

  
  /* retorna true si es posible definir un goal, false si se termino la trayectoria y no quedan goals. */
  return true;
}

bool KinematicPositionController::getTimeBasedGoal(const ros::Time& t, double& x, double& y, double& a)
{
  size_t next_point_idx;

  if( not nextPointIndex(t, next_point_idx ) )
    return false;
    
  ROS_INFO_STREAM("processing index: " << next_point_idx);

  const robmovil_msgs::TrajectoryPoint& prev_point = getTrajectory().points[ next_point_idx-1 ];
  const robmovil_msgs::TrajectoryPoint& next_point = getTrajectory().points[ next_point_idx ];

  const ros::Time& t0 = getInitialTime() + prev_point.time_from_start;
  const ros::Time& t1 = getInitialTime() + next_point.time_from_start;

  assert(t0 <= t);
  assert(t < t1);

  double x0 = prev_point.transform.translation.x;
  double x1 = next_point.transform.translation.x;

  double y0 = prev_point.transform.translation.y;
  double y1 = next_point.transform.translation.y;

  double a0 = tf2::getYaw(prev_point.transform.rotation);
  double a1 = tf2::getYaw(next_point.transform.rotation);

  x = lineal_interp(t0, t1, x0, x1, t);
  y = lineal_interp(t0, t1, y0, y1, t);
  a = lineal_interp(t0, t1, a0, a1, t);

  return true;
}
