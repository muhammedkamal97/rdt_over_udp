# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /home/muhammed/Downloads/CLion-2018.2.4/clion-2018.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/muhammed/Downloads/CLion-2018.2.4/clion-2018.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/muhammed/CLionProjects/TCP_client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/muhammed/CLionProjects/TCP_client/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TCP_client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TCP_client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TCP_client.dir/flags.make

CMakeFiles/TCP_client.dir/main.cpp.o: CMakeFiles/TCP_client.dir/flags.make
CMakeFiles/TCP_client.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muhammed/CLionProjects/TCP_client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TCP_client.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TCP_client.dir/main.cpp.o -c /home/muhammed/CLionProjects/TCP_client/main.cpp

CMakeFiles/TCP_client.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TCP_client.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muhammed/CLionProjects/TCP_client/main.cpp > CMakeFiles/TCP_client.dir/main.cpp.i

CMakeFiles/TCP_client.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TCP_client.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muhammed/CLionProjects/TCP_client/main.cpp -o CMakeFiles/TCP_client.dir/main.cpp.s

CMakeFiles/TCP_client.dir/Client.cpp.o: CMakeFiles/TCP_client.dir/flags.make
CMakeFiles/TCP_client.dir/Client.cpp.o: ../Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muhammed/CLionProjects/TCP_client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TCP_client.dir/Client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TCP_client.dir/Client.cpp.o -c /home/muhammed/CLionProjects/TCP_client/Client.cpp

CMakeFiles/TCP_client.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TCP_client.dir/Client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muhammed/CLionProjects/TCP_client/Client.cpp > CMakeFiles/TCP_client.dir/Client.cpp.i

CMakeFiles/TCP_client.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TCP_client.dir/Client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muhammed/CLionProjects/TCP_client/Client.cpp -o CMakeFiles/TCP_client.dir/Client.cpp.s

CMakeFiles/TCP_client.dir/reliable_portocols/Reliable_abstract.cpp.o: CMakeFiles/TCP_client.dir/flags.make
CMakeFiles/TCP_client.dir/reliable_portocols/Reliable_abstract.cpp.o: ../reliable_portocols/Reliable_abstract.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muhammed/CLionProjects/TCP_client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TCP_client.dir/reliable_portocols/Reliable_abstract.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TCP_client.dir/reliable_portocols/Reliable_abstract.cpp.o -c /home/muhammed/CLionProjects/TCP_client/reliable_portocols/Reliable_abstract.cpp

CMakeFiles/TCP_client.dir/reliable_portocols/Reliable_abstract.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TCP_client.dir/reliable_portocols/Reliable_abstract.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muhammed/CLionProjects/TCP_client/reliable_portocols/Reliable_abstract.cpp > CMakeFiles/TCP_client.dir/reliable_portocols/Reliable_abstract.cpp.i

CMakeFiles/TCP_client.dir/reliable_portocols/Reliable_abstract.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TCP_client.dir/reliable_portocols/Reliable_abstract.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muhammed/CLionProjects/TCP_client/reliable_portocols/Reliable_abstract.cpp -o CMakeFiles/TCP_client.dir/reliable_portocols/Reliable_abstract.cpp.s

CMakeFiles/TCP_client.dir/reliable_portocols/Stop_wait.cpp.o: CMakeFiles/TCP_client.dir/flags.make
CMakeFiles/TCP_client.dir/reliable_portocols/Stop_wait.cpp.o: ../reliable_portocols/Stop_wait.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muhammed/CLionProjects/TCP_client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TCP_client.dir/reliable_portocols/Stop_wait.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TCP_client.dir/reliable_portocols/Stop_wait.cpp.o -c /home/muhammed/CLionProjects/TCP_client/reliable_portocols/Stop_wait.cpp

CMakeFiles/TCP_client.dir/reliable_portocols/Stop_wait.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TCP_client.dir/reliable_portocols/Stop_wait.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muhammed/CLionProjects/TCP_client/reliable_portocols/Stop_wait.cpp > CMakeFiles/TCP_client.dir/reliable_portocols/Stop_wait.cpp.i

CMakeFiles/TCP_client.dir/reliable_portocols/Stop_wait.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TCP_client.dir/reliable_portocols/Stop_wait.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muhammed/CLionProjects/TCP_client/reliable_portocols/Stop_wait.cpp -o CMakeFiles/TCP_client.dir/reliable_portocols/Stop_wait.cpp.s

CMakeFiles/TCP_client.dir/reliable_portocols/Selective_repeat.cpp.o: CMakeFiles/TCP_client.dir/flags.make
CMakeFiles/TCP_client.dir/reliable_portocols/Selective_repeat.cpp.o: ../reliable_portocols/Selective_repeat.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muhammed/CLionProjects/TCP_client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TCP_client.dir/reliable_portocols/Selective_repeat.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TCP_client.dir/reliable_portocols/Selective_repeat.cpp.o -c /home/muhammed/CLionProjects/TCP_client/reliable_portocols/Selective_repeat.cpp

CMakeFiles/TCP_client.dir/reliable_portocols/Selective_repeat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TCP_client.dir/reliable_portocols/Selective_repeat.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muhammed/CLionProjects/TCP_client/reliable_portocols/Selective_repeat.cpp > CMakeFiles/TCP_client.dir/reliable_portocols/Selective_repeat.cpp.i

CMakeFiles/TCP_client.dir/reliable_portocols/Selective_repeat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TCP_client.dir/reliable_portocols/Selective_repeat.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muhammed/CLionProjects/TCP_client/reliable_portocols/Selective_repeat.cpp -o CMakeFiles/TCP_client.dir/reliable_portocols/Selective_repeat.cpp.s

# Object files for target TCP_client
TCP_client_OBJECTS = \
"CMakeFiles/TCP_client.dir/main.cpp.o" \
"CMakeFiles/TCP_client.dir/Client.cpp.o" \
"CMakeFiles/TCP_client.dir/reliable_portocols/Reliable_abstract.cpp.o" \
"CMakeFiles/TCP_client.dir/reliable_portocols/Stop_wait.cpp.o" \
"CMakeFiles/TCP_client.dir/reliable_portocols/Selective_repeat.cpp.o"

# External object files for target TCP_client
TCP_client_EXTERNAL_OBJECTS =

TCP_client: CMakeFiles/TCP_client.dir/main.cpp.o
TCP_client: CMakeFiles/TCP_client.dir/Client.cpp.o
TCP_client: CMakeFiles/TCP_client.dir/reliable_portocols/Reliable_abstract.cpp.o
TCP_client: CMakeFiles/TCP_client.dir/reliable_portocols/Stop_wait.cpp.o
TCP_client: CMakeFiles/TCP_client.dir/reliable_portocols/Selective_repeat.cpp.o
TCP_client: CMakeFiles/TCP_client.dir/build.make
TCP_client: CMakeFiles/TCP_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/muhammed/CLionProjects/TCP_client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable TCP_client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TCP_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TCP_client.dir/build: TCP_client

.PHONY : CMakeFiles/TCP_client.dir/build

CMakeFiles/TCP_client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TCP_client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TCP_client.dir/clean

CMakeFiles/TCP_client.dir/depend:
	cd /home/muhammed/CLionProjects/TCP_client/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/muhammed/CLionProjects/TCP_client /home/muhammed/CLionProjects/TCP_client /home/muhammed/CLionProjects/TCP_client/cmake-build-debug /home/muhammed/CLionProjects/TCP_client/cmake-build-debug /home/muhammed/CLionProjects/TCP_client/cmake-build-debug/CMakeFiles/TCP_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TCP_client.dir/depend

