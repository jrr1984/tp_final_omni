#include "pioneer_odometry.h"
#include <tf/tf.h>
#include <std_msgs/Float64.h>
#include <nav_msgs/Odometry.h>

using namespace robmovil;

#define WHEEL_RADIUS 0.05
#define ENCODER_TICKS 500.0
#define l 0.175

inline double wrapAngle( double angle )
{
  double twoPi = 2.0 * M_PI;
  return angle - twoPi * floor( angle / twoPi );
}

PioneerOdometry::PioneerOdometry(ros::NodeHandle& nh)
  : nh_(nh), x_(0), y_(0), theta_(0), ticks_initialized_(false)
{
  // Nos suscribimos a los comandos de velocidad en el tópico "/robot/cmd_vel" de tipo geometry_msgs::Twist
  twist_sub_ = nh.subscribe("/robot/cmd_vel", 1, &PioneerOdometry::on_velocity_cmd, this);

  vel_pub_front_left_wheel_ = nh.advertise<std_msgs::Float64>("/robot/front_left_wheel/cmd_vel", 1);
  vel_pub_front_right_wheel_ = nh.advertise<std_msgs::Float64>("/robot/front_right_wheel/cmd_vel", 1);
  vel_pub_rear_left_wheel_ = nh.advertise<std_msgs::Float64>("/robot/rear_left_wheel/cmd_vel", 1);
  vel_pub_rear_right_wheel_ = nh.advertise<std_msgs::Float64>("/robot/rear_right_wheel/cmd_vel", 1);

  encoder_sub_ = nh.subscribe("/robot/encoders", 1, &PioneerOdometry::on_encoder_ticks, this);

  pub_odometry_ = nh.advertise<nav_msgs::Odometry>("/robot/odometry", 1);

  tf_broadcaster = boost::make_shared<tf::TransformBroadcaster>();
}

void PioneerOdometry::on_velocity_cmd(const geometry_msgs::Twist& twist)
{
  double vel_front_right = 0;
  double vel_front_left = 0;
  double vel_rear_right = 0;
  double vel_rear_left = 0;
 
 // publish left front velocity RUEDA ASOCIADA A W1
  {
    std_msgs::Float64 msg;
    vel_front_left = (twist.linear.x - twist.linear.y - twist.angular.z * 2 * l) / WHEEL_RADIUS;
    msg.data = vel_front_left;
    

    vel_pub_front_left_wheel_.publish( msg );
  }

  // publish right front velocity RUEDA ASOCIADA A W2
  {
    std_msgs::Float64 msg;
    vel_front_right = (twist.linear.x + twist.linear.y + twist.angular.z * 2 * l) / WHEEL_RADIUS;
    msg.data = vel_front_right;
    

    vel_pub_front_right_wheel_.publish( msg );
  }

  // publish left rear velocity RUEDA ASOCIADA A W3
  {
    std_msgs::Float64 msg;
    vel_rear_left = (twist.linear.x + twist.linear.y - twist.angular.z * 2 * l) / WHEEL_RADIUS;
    msg.data = vel_rear_left;
    

    vel_pub_rear_left_wheel_.publish( msg );
  }

  // publish right rear velocity RUEDA ASOCIADA A W4
  {
    std_msgs::Float64 msg;
    vel_rear_right = (twist.linear.x - twist.linear.y + twist.angular.z * 2 * l) / WHEEL_RADIUS;
    msg.data = vel_rear_right;
    

    vel_pub_rear_right_wheel_.publish( msg );
  }

}

void PioneerOdometry::on_encoder_ticks(const robmovil_msgs::MultiEncoderTicks& encoder)
{
  // La primera vez que llega un mensaje de encoders
  // inicializo las variables de estado.
if (not ticks_initialized_) {
    ticks_initialized_ = true;
    last_ticks_front_left_ = encoder.ticks[0].data;
    last_ticks_front_right_ = encoder.ticks[1].data;
    last_ticks_rear_left_ = encoder.ticks[2].data;
    last_ticks_rear_right_ = encoder.ticks[3].data;
    last_ticks_time = encoder.header.stamp;
    return;
  }

  int32_t delta_ticks_front_left_ = encoder.ticks[0].data - last_ticks_front_left_;
  int32_t delta_ticks_front_right_ = encoder.ticks[1].data - last_ticks_front_right_;
  int32_t delta_ticks_rear_left_ = encoder.ticks[2].data - last_ticks_rear_left_;
  int32_t delta_ticks_rear_right_ = encoder.ticks[3].data - last_ticks_rear_right_;

  // calcular el desplazamiento relativo

  /* Utilizar este delta de tiempo entre momentos */
  double delta_t = (encoder.header.stamp - last_ticks_time).toSec();

  /** Utilizar variables globales x_, y_, theta_ definidas en el .h */
  w_1 = 2 * M_PI * (delta_ticks_front_left_ / ENCODER_TICKS) / delta_t; 
  w_2 = 2 * M_PI * (delta_ticks_front_right_ / ENCODER_TICKS) / delta_t; 
  w_3 = 2 * M_PI * (delta_ticks_rear_left_ / ENCODER_TICKS) / delta_t; 
  w_4 = 2 * M_PI * (delta_ticks_rear_right_ / ENCODER_TICKS) / delta_t; 
  
  v_x = (w_1 + w_2 + w_3 + w_4) * WHEEL_RADIUS / 4;
  v_y = (-w_1 + w_2 + w_3 - w_4) * WHEEL_RADIUS / 4;


  w_z = (-w_1 + w_2 - w_3 + w_4) * WHEEL_RADIUS / (4 * 2 * l);
  delta_theta = w_z * delta_t;
  theta_ += delta_theta;

  delta_x = v_x * delta_t*cos(theta_) - v_y * sin(theta_) * delta_t; //vel respecto del mundo ahora, antes era respecto del robot
  delta_y = v_x * delta_t*sin(theta_) + v_y * cos(theta_) * delta_t;

  x_ += delta_x;
  y_ += delta_y;


  // Construir el mensaje odometry utilizando el esqueleto siguiente:
  nav_msgs::Odometry msg;

  msg.header.stamp = encoder.header.stamp;
  msg.header.frame_id = "odom";
  msg.child_frame_id = "base_link";

  msg.pose.pose.position.x = x_;
  msg.pose.pose.position.y = y_;
  msg.pose.pose.position.z = 0;

  msg.pose.pose.orientation = tf::createQuaternionMsgFromYaw(theta_);

  msg.twist.twist.linear.x = v_x;
  msg.twist.twist.linear.y = v_y;
  msg.twist.twist.linear.z = 0;

  msg.twist.twist.angular.x = 0;
  msg.twist.twist.angular.y = 0;
  msg.twist.twist.angular.z = w_z;

  pub_odometry_.publish( msg );

  // Actualizo las variables de estado

  last_ticks_front_left_ = encoder.ticks[0].data;
  last_ticks_front_right_ = encoder.ticks[1].data;
  last_ticks_rear_left_ = encoder.ticks[2].data;
  last_ticks_rear_right_ = encoder.ticks[3].data;
  last_ticks_time = encoder.header.stamp;

  /* Mando tambien un transform usando TF */
  tf::Transform t;
  tf::poseMsgToTF(msg.pose.pose, t);
  tf_broadcaster->sendTransform(tf::StampedTransform(t, encoder.header.stamp, "odom", "base_link"));

}
