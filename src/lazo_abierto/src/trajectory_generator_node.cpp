#include <ros/ros.h>
#include <robmovil_msgs/Trajectory.h>
#include <robmovil_msgs/TrajectoryPoint.h>
#include <nav_msgs/Path.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PoseArray.h>
#include <tf/tf.h>
#include <XmlRpcValue.h>
#include <vector>

void build_sin_trajectory(double, double, double, double, robmovil_msgs::Trajectory&, nav_msgs::Path&);

int main(int argc, char** argv)
{
  ros::init(argc, argv, "trajectory_generator");
  ros::NodeHandle nh;
  ros::NodeHandle nhp("~");

  ros::Publisher trajectory_publisher = nh.advertise<robmovil_msgs::Trajectory>("/robot/trajectory", 1, true);
  
  // Path descripto en poses para visualizacion en RViz
  ros::Publisher path_publisher = nh.advertise<nav_msgs::Path>("/ground_truth/target_path", 1, true);

  robmovil_msgs::Trajectory trajectory_msg;
  nav_msgs::Path path_msg;

  trajectory_msg.header.seq = 0;
  trajectory_msg.header.stamp = ros::Time::now();
  trajectory_msg.header.frame_id = "odom";

  path_msg.header.stamp = ros::Time::now();
  path_msg.header.frame_id = "odom";
  
  double stepping;
  double total_time;
  double amplitude;
  double cycles;
  
  nhp.param<double>("stepping", stepping, 0.1);
  nhp.param<double>("total_time", total_time, 50); // 20: da masomenos, 50: lo sigue muy bien el pioneer

  
  build_sin_trajectory(stepping, total_time, amplitude, cycles, trajectory_msg, path_msg);

  trajectory_publisher.publish( trajectory_msg );
  path_publisher.publish( path_msg );

  ros::spin();

  return 0;
}

void build_sin_trajectory(double stepping, double total_time, double amplitude, double cycles, robmovil_msgs::Trajectory& trajectory_msg, nav_msgs::Path& path_msg)
{
  robmovil_msgs::TrajectoryPoint point_msg;
  geometry_msgs::PoseStamped stamped_pose_msg;

  double x = 0; //amplitude * sin( x );
  double y; //cycles * 2*M_PI * t * 1/total_time;
  for (double t = 0; t < 4.1; t = t + stepping)
  {
    // X se extiende lo suficiente para dar varias vueltas en el tiempo determinado
    // Y funcion seno con determinada amplitud
    y = -t;

    
    // calculo del angulo en cada momento y la derivada del angulo
    double a = atan2( y - 4.1, x + 4.1);

    // double va = (vvy*vx-vvx*vy)/(vx*vx+vy*vy);

    // se crean los waypoints de la trajectoria

    point_msg.time_from_start = ros::Duration( t );

    point_msg.transform.translation.x = x;
    point_msg.transform.translation.y = y;
    point_msg.transform.translation.z = 0;

    point_msg.transform.rotation = tf::createQuaternionMsgFromYaw( a );

    trajectory_msg.points.push_back( point_msg );
    
    stamped_pose_msg.pose.position.x = x;
    stamped_pose_msg.pose.position.y = y;
    stamped_pose_msg.pose.position.z = 0;
    
    stamped_pose_msg.pose.orientation = tf::createQuaternionMsgFromYaw(a );
    
    path_msg.poses.push_back(stamped_pose_msg);
  }
  for (double t = 0; t < 4.1; t = t + stepping)
  {
    x = -t;
    double a = atan2( y - 4.1, x - 4.1);
    point_msg.time_from_start = ros::Duration( t );

    point_msg.transform.translation.x = x;
    point_msg.transform.translation.y = y;
    point_msg.transform.translation.z = 0;

    point_msg.transform.rotation = tf::createQuaternionMsgFromYaw( a );

    trajectory_msg.points.push_back( point_msg );
    
    stamped_pose_msg.pose.position.x = x;
    stamped_pose_msg.pose.position.y = y;
    stamped_pose_msg.pose.position.z = 0;
    
    stamped_pose_msg.pose.orientation = tf::createQuaternionMsgFromYaw(a);
    
    path_msg.poses.push_back(stamped_pose_msg);
  }
  for (double t = 0; t < 4.1 ; t = t + stepping)
  {
    y = t - 4;
    double a = atan2( y+4.1,x - 4.1);
    

    point_msg.time_from_start = ros::Duration( t );

    point_msg.transform.translation.x = x;
    point_msg.transform.translation.y = y;
    point_msg.transform.translation.z = 0;

    point_msg.transform.rotation = tf::createQuaternionMsgFromYaw( a);

    trajectory_msg.points.push_back( point_msg );
    
    stamped_pose_msg.pose.position.x = x;
    stamped_pose_msg.pose.position.y = y;
    stamped_pose_msg.pose.position.z = 0;
    
    stamped_pose_msg.pose.orientation = tf::createQuaternionMsgFromYaw(a);
    
    path_msg.poses.push_back(stamped_pose_msg);
  }
  for (double t = 0; t < 4.1; t = t + stepping)
  {
    x = t - 4;
    double a = atan2(y+4.1,x+4.1);
    point_msg.time_from_start = ros::Duration( t );

    point_msg.transform.translation.x = x;
    point_msg.transform.translation.y = y;
    point_msg.transform.translation.z = 0;

    point_msg.transform.rotation = tf::createQuaternionMsgFromYaw( a );

    trajectory_msg.points.push_back( point_msg );
    
    stamped_pose_msg.pose.position.x = x;
    stamped_pose_msg.pose.position.y = y;
    stamped_pose_msg.pose.position.z = 0;
    
    stamped_pose_msg.pose.orientation = tf::createQuaternionMsgFromYaw(a);
    
    path_msg.poses.push_back(stamped_pose_msg);
  }
}
