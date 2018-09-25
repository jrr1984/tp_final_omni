#include <fstream>
#include <ros/ros.h>
#include <tf2/utils.h>
#include <nav_msgs/Odometry.h>
#include <boost/date_time/posix_time/posix_time.hpp>

std::string formatTime(const boost::posix_time::ptime& time, const char* format)
{
  boost::posix_time::time_facet* facet = new boost::posix_time::time_facet();
  facet->format( format );

  std::stringstream stream;
  stream.str("");
  stream.imbue(std::locale(std::locale::classic(), facet));
  stream << time;

  return stream.str();
}

std::string timestamp()
{
  return formatTime(boost::posix_time::second_clock::local_time(), "%Y-%m-%d_%H:%M:%S");
}

class Logger
{
  public:

    Logger(ros::NodeHandle& nh);

  private:

    ros::Subscriber robot_pose_sub_, ground_truth_sub_, goal_poses_sub_,vel_real_pub,desired_vel_;

    std::ofstream robot_logfile_, ground_truth_logfile_, goal_poses_logfile_,real_vel_logfile_,desired_vel_logfile_;

  // funciones auxiliares

    void handleRobotPose(const nav_msgs::Odometry& msg);

    void handleGroundTruthPose(const nav_msgs::Odometry& msg);

    void handleGoalPose(const geometry_msgs::PoseStamped& msg);
    //void handleVelReal(const nav_msgs::Odometry& msg);
    void handleDesiredVel(const geometry_msgs::Twist& cmd);
};

Logger::Logger(ros::NodeHandle& nh)
  : robot_logfile_( timestamp() + "_poses.log" ), ground_truth_logfile_( timestamp() + "_ground-truth.log" ), goal_poses_logfile_( timestamp() + "_goals.log" ), desired_vel_logfile_(timestamp() + "_desired_vel.log" )
{
  robot_pose_sub_ = nh.subscribe("/robot/odometry", 1, &Logger::handleRobotPose, this);
  ground_truth_sub_ = nh.subscribe("/robot/ground_truth", 1, &Logger::handleGroundTruthPose, this);
  goal_poses_sub_ = nh.subscribe("/goal_pose", 1, &Logger::handleGoalPose, this);
  //vel_real_pub = nh.subscribe("/robot/real_velocity",1,&Logger::handleVelReal,this);
   desired_vel_ = nh.subscribe("/robot/cmd_vel",1,&Logger::handleDesiredVel,this);
}


void Logger::handleDesiredVel(const geometry_msgs::Twist& cmd)
{
  desired_vel_logfile_ << ros::Time::now() << " " << cmd.linear.x << " " << cmd.linear.y << " " << std::endl;
}



void Logger::handleRobotPose(const nav_msgs::Odometry& msg)
{
  robot_logfile_ << msg.header.stamp.toSec() << " " << msg.pose.pose.position.x << " " << msg.pose.pose.position.y << " " << tf2::getYaw( msg.pose.pose.orientation )  << std::endl;
}

/*void Logger::handleVelReal(const nav_msgs::Odometry& msg)
{
  real_vel_logfile_ << msg.header.stamp.toSec() << " " << msg.twist.twist.linear.x << " " << msg.twist.twist.linear.y << " " << std::endl;
}*/

/*void Logger::handleDesiredVel(const nav_msgs::Odometry& msg)
{
  real_vel_logfile_ << msg.header.stamp.toSec() << " " << msg.twist.twist.linear.x << " " << msg.twist.twist.linear.y << " " << std::endl;
}*/

void Logger::handleGroundTruthPose(const nav_msgs::Odometry& msg)
{
  ground_truth_logfile_ << msg.header.stamp.toSec() << " " << msg.pose.pose.position.x << " " << msg.pose.pose.position.y << " " << tf2::getYaw( msg.pose.pose.orientation )<< " " << msg.twist.twist.linear.x << " " << msg.twist.twist.linear.y  << std::endl;
}

void Logger::handleGoalPose(const geometry_msgs::PoseStamped& msg)
{
  goal_poses_logfile_ << msg.header.stamp.toSec() << " " << msg.pose.position.x << " " << msg.pose.position.y << " " << tf2::getYaw( msg.pose.orientation ) << std::endl;
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "logger");
  ros::NodeHandle nh;

  Logger logger( nh );

  ros::spin();

  return 0;
}
