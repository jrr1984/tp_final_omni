// Generated by gencpp from file universal_teleop/Control.msg
// DO NOT EDIT!


#ifndef UNIVERSAL_TELEOP_MESSAGE_CONTROL_H
#define UNIVERSAL_TELEOP_MESSAGE_CONTROL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace universal_teleop
{
template <class ContainerAllocator>
struct Control_
{
  typedef Control_<ContainerAllocator> Type;

  Control_()
    : header()
    , controls()
    , values()  {
    }
  Control_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , controls(_alloc)
    , values(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _controls_type;
  _controls_type controls;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _values_type;
  _values_type values;





  typedef boost::shared_ptr< ::universal_teleop::Control_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::universal_teleop::Control_<ContainerAllocator> const> ConstPtr;

}; // struct Control_

typedef ::universal_teleop::Control_<std::allocator<void> > Control;

typedef boost::shared_ptr< ::universal_teleop::Control > ControlPtr;
typedef boost::shared_ptr< ::universal_teleop::Control const> ControlConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::universal_teleop::Control_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::universal_teleop::Control_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace universal_teleop

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'universal_teleop': ['/home/juan/catkin_ws/src/ros-universal-teleop/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::universal_teleop::Control_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::universal_teleop::Control_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::universal_teleop::Control_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::universal_teleop::Control_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::universal_teleop::Control_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::universal_teleop::Control_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::universal_teleop::Control_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dab96ca8530e6a319a58ba491577719b";
  }

  static const char* value(const ::universal_teleop::Control_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xdab96ca8530e6a31ULL;
  static const uint64_t static_value2 = 0x9a58ba491577719bULL;
};

template<class ContainerAllocator>
struct DataType< ::universal_teleop::Control_<ContainerAllocator> >
{
  static const char* value()
  {
    return "universal_teleop/Control";
  }

  static const char* value(const ::universal_teleop::Control_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::universal_teleop::Control_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
string[] controls\n\
float32[] values\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::universal_teleop::Control_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::universal_teleop::Control_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.controls);
      stream.next(m.values);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Control_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::universal_teleop::Control_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::universal_teleop::Control_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "controls[]" << std::endl;
    for (size_t i = 0; i < v.controls.size(); ++i)
    {
      s << indent << "  controls[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.controls[i]);
    }
    s << indent << "values[]" << std::endl;
    for (size_t i = 0; i < v.values.size(); ++i)
    {
      s << indent << "  values[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.values[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // UNIVERSAL_TELEOP_MESSAGE_CONTROL_H
