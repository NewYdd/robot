# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dtrobot/robot/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dtrobot/robot/build

# Include any dependencies generated for this target.
include communication/CMakeFiles/test_node.dir/depend.make

# Include the progress variables for this target.
include communication/CMakeFiles/test_node.dir/progress.make

# Include the compile flags for this target's objects.
include communication/CMakeFiles/test_node.dir/flags.make

communication/CMakeFiles/test_node.dir/src/test.cpp.o: communication/CMakeFiles/test_node.dir/flags.make
communication/CMakeFiles/test_node.dir/src/test.cpp.o: /home/dtrobot/robot/src/communication/src/test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dtrobot/robot/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object communication/CMakeFiles/test_node.dir/src/test.cpp.o"
	cd /home/dtrobot/robot/build/communication && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_node.dir/src/test.cpp.o -c /home/dtrobot/robot/src/communication/src/test.cpp

communication/CMakeFiles/test_node.dir/src/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_node.dir/src/test.cpp.i"
	cd /home/dtrobot/robot/build/communication && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dtrobot/robot/src/communication/src/test.cpp > CMakeFiles/test_node.dir/src/test.cpp.i

communication/CMakeFiles/test_node.dir/src/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_node.dir/src/test.cpp.s"
	cd /home/dtrobot/robot/build/communication && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dtrobot/robot/src/communication/src/test.cpp -o CMakeFiles/test_node.dir/src/test.cpp.s

communication/CMakeFiles/test_node.dir/src/test.cpp.o.requires:
.PHONY : communication/CMakeFiles/test_node.dir/src/test.cpp.o.requires

communication/CMakeFiles/test_node.dir/src/test.cpp.o.provides: communication/CMakeFiles/test_node.dir/src/test.cpp.o.requires
	$(MAKE) -f communication/CMakeFiles/test_node.dir/build.make communication/CMakeFiles/test_node.dir/src/test.cpp.o.provides.build
.PHONY : communication/CMakeFiles/test_node.dir/src/test.cpp.o.provides

communication/CMakeFiles/test_node.dir/src/test.cpp.o.provides.build: communication/CMakeFiles/test_node.dir/src/test.cpp.o

communication/CMakeFiles/test_node.dir/src/udpServer.cpp.o: communication/CMakeFiles/test_node.dir/flags.make
communication/CMakeFiles/test_node.dir/src/udpServer.cpp.o: /home/dtrobot/robot/src/communication/src/udpServer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dtrobot/robot/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object communication/CMakeFiles/test_node.dir/src/udpServer.cpp.o"
	cd /home/dtrobot/robot/build/communication && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_node.dir/src/udpServer.cpp.o -c /home/dtrobot/robot/src/communication/src/udpServer.cpp

communication/CMakeFiles/test_node.dir/src/udpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_node.dir/src/udpServer.cpp.i"
	cd /home/dtrobot/robot/build/communication && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dtrobot/robot/src/communication/src/udpServer.cpp > CMakeFiles/test_node.dir/src/udpServer.cpp.i

communication/CMakeFiles/test_node.dir/src/udpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_node.dir/src/udpServer.cpp.s"
	cd /home/dtrobot/robot/build/communication && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dtrobot/robot/src/communication/src/udpServer.cpp -o CMakeFiles/test_node.dir/src/udpServer.cpp.s

communication/CMakeFiles/test_node.dir/src/udpServer.cpp.o.requires:
.PHONY : communication/CMakeFiles/test_node.dir/src/udpServer.cpp.o.requires

communication/CMakeFiles/test_node.dir/src/udpServer.cpp.o.provides: communication/CMakeFiles/test_node.dir/src/udpServer.cpp.o.requires
	$(MAKE) -f communication/CMakeFiles/test_node.dir/build.make communication/CMakeFiles/test_node.dir/src/udpServer.cpp.o.provides.build
.PHONY : communication/CMakeFiles/test_node.dir/src/udpServer.cpp.o.provides

communication/CMakeFiles/test_node.dir/src/udpServer.cpp.o.provides.build: communication/CMakeFiles/test_node.dir/src/udpServer.cpp.o

# Object files for target test_node
test_node_OBJECTS = \
"CMakeFiles/test_node.dir/src/test.cpp.o" \
"CMakeFiles/test_node.dir/src/udpServer.cpp.o"

# External object files for target test_node
test_node_EXTERNAL_OBJECTS =

/home/dtrobot/robot/devel/lib/communication/test_node: communication/CMakeFiles/test_node.dir/src/test.cpp.o
/home/dtrobot/robot/devel/lib/communication/test_node: communication/CMakeFiles/test_node.dir/src/udpServer.cpp.o
/home/dtrobot/robot/devel/lib/communication/test_node: communication/CMakeFiles/test_node.dir/build.make
/home/dtrobot/robot/devel/lib/communication/test_node: /opt/ros/indigo/lib/libroscpp.so
/home/dtrobot/robot/devel/lib/communication/test_node: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/dtrobot/robot/devel/lib/communication/test_node: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/dtrobot/robot/devel/lib/communication/test_node: /opt/ros/indigo/lib/librosconsole.so
/home/dtrobot/robot/devel/lib/communication/test_node: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/dtrobot/robot/devel/lib/communication/test_node: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/dtrobot/robot/devel/lib/communication/test_node: /usr/lib/liblog4cxx.so
/home/dtrobot/robot/devel/lib/communication/test_node: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/dtrobot/robot/devel/lib/communication/test_node: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/dtrobot/robot/devel/lib/communication/test_node: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/dtrobot/robot/devel/lib/communication/test_node: /opt/ros/indigo/lib/librostime.so
/home/dtrobot/robot/devel/lib/communication/test_node: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/dtrobot/robot/devel/lib/communication/test_node: /opt/ros/indigo/lib/libcpp_common.so
/home/dtrobot/robot/devel/lib/communication/test_node: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/dtrobot/robot/devel/lib/communication/test_node: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/dtrobot/robot/devel/lib/communication/test_node: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/dtrobot/robot/devel/lib/communication/test_node: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/dtrobot/robot/devel/lib/communication/test_node: communication/CMakeFiles/test_node.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/dtrobot/robot/devel/lib/communication/test_node"
	cd /home/dtrobot/robot/build/communication && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_node.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
communication/CMakeFiles/test_node.dir/build: /home/dtrobot/robot/devel/lib/communication/test_node
.PHONY : communication/CMakeFiles/test_node.dir/build

communication/CMakeFiles/test_node.dir/requires: communication/CMakeFiles/test_node.dir/src/test.cpp.o.requires
communication/CMakeFiles/test_node.dir/requires: communication/CMakeFiles/test_node.dir/src/udpServer.cpp.o.requires
.PHONY : communication/CMakeFiles/test_node.dir/requires

communication/CMakeFiles/test_node.dir/clean:
	cd /home/dtrobot/robot/build/communication && $(CMAKE_COMMAND) -P CMakeFiles/test_node.dir/cmake_clean.cmake
.PHONY : communication/CMakeFiles/test_node.dir/clean

communication/CMakeFiles/test_node.dir/depend:
	cd /home/dtrobot/robot/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dtrobot/robot/src /home/dtrobot/robot/src/communication /home/dtrobot/robot/build /home/dtrobot/robot/build/communication /home/dtrobot/robot/build/communication/CMakeFiles/test_node.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : communication/CMakeFiles/test_node.dir/depend

