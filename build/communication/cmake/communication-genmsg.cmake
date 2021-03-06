# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "communication: 1 messages, 0 services")

set(MSG_I_FLAGS "-Icommunication:/home/dtrobot/robot/src/communication/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(communication_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/dtrobot/robot/src/communication/msg/command.msg" NAME_WE)
add_custom_target(_communication_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "communication" "/home/dtrobot/robot/src/communication/msg/command.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(communication
  "/home/dtrobot/robot/src/communication/msg/command.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/communication
)

### Generating Services

### Generating Module File
_generate_module_cpp(communication
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/communication
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(communication_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(communication_generate_messages communication_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dtrobot/robot/src/communication/msg/command.msg" NAME_WE)
add_dependencies(communication_generate_messages_cpp _communication_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(communication_gencpp)
add_dependencies(communication_gencpp communication_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS communication_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(communication
  "/home/dtrobot/robot/src/communication/msg/command.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/communication
)

### Generating Services

### Generating Module File
_generate_module_lisp(communication
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/communication
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(communication_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(communication_generate_messages communication_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dtrobot/robot/src/communication/msg/command.msg" NAME_WE)
add_dependencies(communication_generate_messages_lisp _communication_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(communication_genlisp)
add_dependencies(communication_genlisp communication_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS communication_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(communication
  "/home/dtrobot/robot/src/communication/msg/command.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/communication
)

### Generating Services

### Generating Module File
_generate_module_py(communication
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/communication
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(communication_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(communication_generate_messages communication_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dtrobot/robot/src/communication/msg/command.msg" NAME_WE)
add_dependencies(communication_generate_messages_py _communication_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(communication_genpy)
add_dependencies(communication_genpy communication_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS communication_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/communication)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/communication
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/communication)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/communication
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/communication)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/communication\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/communication
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
