// Generated by gencpp from file robmovil_msgs/TrajectoryPoint.msg
// DO NOT EDIT!


#ifndef ROBMOVIL_MSGS_MESSAGE_TRAJECTORYPOINT_H
#define ROBMOVIL_MSGS_MESSAGE_TRAJECTORYPOINT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Transform.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Twist.h>

namespace robmovil_msgs
{
template <class ContainerAllocator>
struct TrajectoryPoint_
{
  typedef TrajectoryPoint_<ContainerAllocator> Type;

  TrajectoryPoint_()
    : transform()
    , velocity()
    , acceleration()
    , time_from_start()  {
    }
  TrajectoryPoint_(const ContainerAllocator& _alloc)
    : transform(_alloc)
    , velocity(_alloc)
    , acceleration(_alloc)
    , time_from_start()  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::Transform_<ContainerAllocator>  _transform_type;
  _transform_type transform;

   typedef  ::geometry_msgs::Twist_<ContainerAllocator>  _velocity_type;
  _velocity_type velocity;

   typedef  ::geometry_msgs::Twist_<ContainerAllocator>  _acceleration_type;
  _acceleration_type acceleration;

   typedef ros::Duration _time_from_start_type;
  _time_from_start_type time_from_start;





  typedef boost::shared_ptr< ::robmovil_msgs::TrajectoryPoint_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robmovil_msgs::TrajectoryPoint_<ContainerAllocator> const> ConstPtr;

}; // struct TrajectoryPoint_

typedef ::robmovil_msgs::TrajectoryPoint_<std::allocator<void> > TrajectoryPoint;

typedef boost::shared_ptr< ::robmovil_msgs::TrajectoryPoint > TrajectoryPointPtr;
typedef boost::shared_ptr< ::robmovil_msgs::TrajectoryPoint const> TrajectoryPointConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robmovil_msgs::TrajectoryPoint_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robmovil_msgs::TrajectoryPoint_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace robmovil_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'robmovil_msgs': ['/home/juan/catkin_ws/src/robmovil_msgs/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::robmovil_msgs::TrajectoryPoint_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robmovil_msgs::TrajectoryPoint_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robmovil_msgs::TrajectoryPoint_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robmovil_msgs::TrajectoryPoint_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robmovil_msgs::TrajectoryPoint_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robmovil_msgs::TrajectoryPoint_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robmovil_msgs::TrajectoryPoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "382e189245ac5ab9808aef582801e5c4";
  }

  static const char* value(const ::robmovil_msgs::TrajectoryPoint_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x382e189245ac5ab9ULL;
  static const uint64_t static_value2 = 0x808aef582801e5c4ULL;
};

template<class ContainerAllocator>
struct DataType< ::robmovil_msgs::TrajectoryPoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robmovil_msgs/TrajectoryPoint";
  }

  static const char* value(const ::robmovil_msgs::TrajectoryPoint_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robmovil_msgs::TrajectoryPoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Each multi-dof joint can specify a transform (up to 6 DOF)\n\
geometry_msgs/Transform transform\n\
\n\
# There can be a velocity specified for the origin of the joint \n\
geometry_msgs/Twist velocity\n\
\n\
# There can be an acceleration specified for the origin of the joint \n\
geometry_msgs/Twist acceleration\n\
\n\
duration time_from_start\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Transform\n\
# This represents the transform between two coordinate frames in free space.\n\
\n\
Vector3 translation\n\
Quaternion rotation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
# It is only meant to represent a direction. Therefore, it does not\n\
# make sense to apply a translation to it (e.g., when applying a \n\
# generic rigid transformation to a Vector3, tf2 will only apply the\n\
# rotation). If you want your data to be translatable too, use the\n\
# geometry_msgs/Point message instead.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Twist\n\
# This expresses velocity in free space broken into its linear and angular parts.\n\
Vector3  linear\n\
Vector3  angular\n\
";
  }

  static const char* value(const ::robmovil_msgs::TrajectoryPoint_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robmovil_msgs::TrajectoryPoint_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.transform);
      stream.next(m.velocity);
      stream.next(m.acceleration);
      stream.next(m.time_from_start);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TrajectoryPoint_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robmovil_msgs::TrajectoryPoint_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robmovil_msgs::TrajectoryPoint_<ContainerAllocator>& v)
  {
    s << indent << "transform: ";
    s << std::endl;
    Printer< ::geometry_msgs::Transform_<ContainerAllocator> >::stream(s, indent + "  ", v.transform);
    s << indent << "velocity: ";
    s << std::endl;
    Printer< ::geometry_msgs::Twist_<ContainerAllocator> >::stream(s, indent + "  ", v.velocity);
    s << indent << "acceleration: ";
    s << std::endl;
    Printer< ::geometry_msgs::Twist_<ContainerAllocator> >::stream(s, indent + "  ", v.acceleration);
    s << indent << "time_from_start: ";
    Printer<ros::Duration>::stream(s, indent + "  ", v.time_from_start);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBMOVIL_MSGS_MESSAGE_TRAJECTORYPOINT_H
