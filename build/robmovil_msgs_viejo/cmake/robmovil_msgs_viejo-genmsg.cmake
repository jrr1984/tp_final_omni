# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "robmovil_msgs_viejo: 5 messages, 0 services")

set(MSG_I_FLAGS "-Irobmovil_msgs_viejo:/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(robmovil_msgs_viejo_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/TrajectoryPoint.msg" NAME_WE)
add_custom_target(_robmovil_msgs_viejo_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robmovil_msgs_viejo" "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/TrajectoryPoint.msg" "geometry_msgs/Quaternion:geometry_msgs/Twist:geometry_msgs/Transform:geometry_msgs/Vector3"
)

get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/EncoderTicks.msg" NAME_WE)
add_custom_target(_robmovil_msgs_viejo_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robmovil_msgs_viejo" "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/EncoderTicks.msg" "std_msgs/Header:std_msgs/Int32"
)

get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Trajectory.msg" NAME_WE)
add_custom_target(_robmovil_msgs_viejo_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robmovil_msgs_viejo" "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Trajectory.msg" "std_msgs/Header:geometry_msgs/Quaternion:geometry_msgs/Vector3:robmovil_msgs_viejo/TrajectoryPoint:geometry_msgs/Transform:geometry_msgs/Twist"
)

get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Landmark.msg" NAME_WE)
add_custom_target(_robmovil_msgs_viejo_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robmovil_msgs_viejo" "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Landmark.msg" ""
)

get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/LandmarkArray.msg" NAME_WE)
add_custom_target(_robmovil_msgs_viejo_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robmovil_msgs_viejo" "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/LandmarkArray.msg" "robmovil_msgs_viejo/Landmark:std_msgs/Header"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/TrajectoryPoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Transform.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robmovil_msgs_viejo
)
_generate_msg_cpp(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/EncoderTicks.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Int32.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robmovil_msgs_viejo
)
_generate_msg_cpp(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Trajectory.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/TrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Transform.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robmovil_msgs_viejo
)
_generate_msg_cpp(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Landmark.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robmovil_msgs_viejo
)
_generate_msg_cpp(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/LandmarkArray.msg"
  "${MSG_I_FLAGS}"
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Landmark.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robmovil_msgs_viejo
)

### Generating Services

### Generating Module File
_generate_module_cpp(robmovil_msgs_viejo
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robmovil_msgs_viejo
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(robmovil_msgs_viejo_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(robmovil_msgs_viejo_generate_messages robmovil_msgs_viejo_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/TrajectoryPoint.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_cpp _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/EncoderTicks.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_cpp _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Trajectory.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_cpp _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Landmark.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_cpp _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/LandmarkArray.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_cpp _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robmovil_msgs_viejo_gencpp)
add_dependencies(robmovil_msgs_viejo_gencpp robmovil_msgs_viejo_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robmovil_msgs_viejo_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/TrajectoryPoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Transform.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robmovil_msgs_viejo
)
_generate_msg_eus(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/EncoderTicks.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Int32.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robmovil_msgs_viejo
)
_generate_msg_eus(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Trajectory.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/TrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Transform.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robmovil_msgs_viejo
)
_generate_msg_eus(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Landmark.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robmovil_msgs_viejo
)
_generate_msg_eus(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/LandmarkArray.msg"
  "${MSG_I_FLAGS}"
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Landmark.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robmovil_msgs_viejo
)

### Generating Services

### Generating Module File
_generate_module_eus(robmovil_msgs_viejo
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robmovil_msgs_viejo
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(robmovil_msgs_viejo_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(robmovil_msgs_viejo_generate_messages robmovil_msgs_viejo_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/TrajectoryPoint.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_eus _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/EncoderTicks.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_eus _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Trajectory.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_eus _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Landmark.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_eus _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/LandmarkArray.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_eus _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robmovil_msgs_viejo_geneus)
add_dependencies(robmovil_msgs_viejo_geneus robmovil_msgs_viejo_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robmovil_msgs_viejo_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/TrajectoryPoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Transform.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robmovil_msgs_viejo
)
_generate_msg_lisp(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/EncoderTicks.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Int32.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robmovil_msgs_viejo
)
_generate_msg_lisp(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Trajectory.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/TrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Transform.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robmovil_msgs_viejo
)
_generate_msg_lisp(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Landmark.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robmovil_msgs_viejo
)
_generate_msg_lisp(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/LandmarkArray.msg"
  "${MSG_I_FLAGS}"
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Landmark.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robmovil_msgs_viejo
)

### Generating Services

### Generating Module File
_generate_module_lisp(robmovil_msgs_viejo
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robmovil_msgs_viejo
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(robmovil_msgs_viejo_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(robmovil_msgs_viejo_generate_messages robmovil_msgs_viejo_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/TrajectoryPoint.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_lisp _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/EncoderTicks.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_lisp _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Trajectory.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_lisp _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Landmark.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_lisp _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/LandmarkArray.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_lisp _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robmovil_msgs_viejo_genlisp)
add_dependencies(robmovil_msgs_viejo_genlisp robmovil_msgs_viejo_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robmovil_msgs_viejo_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/TrajectoryPoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Transform.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robmovil_msgs_viejo
)
_generate_msg_nodejs(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/EncoderTicks.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Int32.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robmovil_msgs_viejo
)
_generate_msg_nodejs(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Trajectory.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/TrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Transform.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robmovil_msgs_viejo
)
_generate_msg_nodejs(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Landmark.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robmovil_msgs_viejo
)
_generate_msg_nodejs(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/LandmarkArray.msg"
  "${MSG_I_FLAGS}"
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Landmark.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robmovil_msgs_viejo
)

### Generating Services

### Generating Module File
_generate_module_nodejs(robmovil_msgs_viejo
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robmovil_msgs_viejo
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(robmovil_msgs_viejo_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(robmovil_msgs_viejo_generate_messages robmovil_msgs_viejo_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/TrajectoryPoint.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_nodejs _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/EncoderTicks.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_nodejs _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Trajectory.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_nodejs _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Landmark.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_nodejs _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/LandmarkArray.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_nodejs _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robmovil_msgs_viejo_gennodejs)
add_dependencies(robmovil_msgs_viejo_gennodejs robmovil_msgs_viejo_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robmovil_msgs_viejo_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/TrajectoryPoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Transform.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robmovil_msgs_viejo
)
_generate_msg_py(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/EncoderTicks.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Int32.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robmovil_msgs_viejo
)
_generate_msg_py(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Trajectory.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/TrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Transform.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robmovil_msgs_viejo
)
_generate_msg_py(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Landmark.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robmovil_msgs_viejo
)
_generate_msg_py(robmovil_msgs_viejo
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/LandmarkArray.msg"
  "${MSG_I_FLAGS}"
  "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Landmark.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robmovil_msgs_viejo
)

### Generating Services

### Generating Module File
_generate_module_py(robmovil_msgs_viejo
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robmovil_msgs_viejo
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(robmovil_msgs_viejo_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(robmovil_msgs_viejo_generate_messages robmovil_msgs_viejo_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/TrajectoryPoint.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_py _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/EncoderTicks.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_py _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Trajectory.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_py _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/Landmark.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_py _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/juan/catkin_ws/src/robmovil_msgs_viejo/msg/LandmarkArray.msg" NAME_WE)
add_dependencies(robmovil_msgs_viejo_generate_messages_py _robmovil_msgs_viejo_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robmovil_msgs_viejo_genpy)
add_dependencies(robmovil_msgs_viejo_genpy robmovil_msgs_viejo_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robmovil_msgs_viejo_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robmovil_msgs_viejo)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robmovil_msgs_viejo
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(robmovil_msgs_viejo_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(robmovil_msgs_viejo_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robmovil_msgs_viejo)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robmovil_msgs_viejo
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(robmovil_msgs_viejo_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(robmovil_msgs_viejo_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robmovil_msgs_viejo)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robmovil_msgs_viejo
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(robmovil_msgs_viejo_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(robmovil_msgs_viejo_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robmovil_msgs_viejo)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robmovil_msgs_viejo
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(robmovil_msgs_viejo_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(robmovil_msgs_viejo_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robmovil_msgs_viejo)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robmovil_msgs_viejo\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robmovil_msgs_viejo
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(robmovil_msgs_viejo_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(robmovil_msgs_viejo_generate_messages_py geometry_msgs_generate_messages_py)
endif()
