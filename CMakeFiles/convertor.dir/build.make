# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rustyboy/CLionProjects/convertor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rustyboy/CLionProjects/convertor

# Include any dependencies generated for this target.
include CMakeFiles/convertor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/convertor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/convertor.dir/flags.make

CMakeFiles/convertor.dir/main.cpp.o: CMakeFiles/convertor.dir/flags.make
CMakeFiles/convertor.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rustyboy/CLionProjects/convertor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/convertor.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/convertor.dir/main.cpp.o -c /home/rustyboy/CLionProjects/convertor/main.cpp

CMakeFiles/convertor.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/convertor.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rustyboy/CLionProjects/convertor/main.cpp > CMakeFiles/convertor.dir/main.cpp.i

CMakeFiles/convertor.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/convertor.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rustyboy/CLionProjects/convertor/main.cpp -o CMakeFiles/convertor.dir/main.cpp.s

CMakeFiles/convertor.dir/UserInterface.cpp.o: CMakeFiles/convertor.dir/flags.make
CMakeFiles/convertor.dir/UserInterface.cpp.o: UserInterface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rustyboy/CLionProjects/convertor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/convertor.dir/UserInterface.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/convertor.dir/UserInterface.cpp.o -c /home/rustyboy/CLionProjects/convertor/UserInterface.cpp

CMakeFiles/convertor.dir/UserInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/convertor.dir/UserInterface.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rustyboy/CLionProjects/convertor/UserInterface.cpp > CMakeFiles/convertor.dir/UserInterface.cpp.i

CMakeFiles/convertor.dir/UserInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/convertor.dir/UserInterface.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rustyboy/CLionProjects/convertor/UserInterface.cpp -o CMakeFiles/convertor.dir/UserInterface.cpp.s

# Object files for target convertor
convertor_OBJECTS = \
"CMakeFiles/convertor.dir/main.cpp.o" \
"CMakeFiles/convertor.dir/UserInterface.cpp.o"

# External object files for target convertor
convertor_EXTERNAL_OBJECTS =

convertor: CMakeFiles/convertor.dir/main.cpp.o
convertor: CMakeFiles/convertor.dir/UserInterface.cpp.o
convertor: CMakeFiles/convertor.dir/build.make
convertor: lib/libsfml-graphics.so.2.5.1
convertor: lib/libsfml-window.so.2.5.1
convertor: lib/libsfml-audio.so.2.5.1
convertor: lib/libsfml-system.so.2.5.1
convertor: CMakeFiles/convertor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rustyboy/CLionProjects/convertor/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable convertor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/convertor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/convertor.dir/build: convertor

.PHONY : CMakeFiles/convertor.dir/build

CMakeFiles/convertor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/convertor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/convertor.dir/clean

CMakeFiles/convertor.dir/depend:
	cd /home/rustyboy/CLionProjects/convertor && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rustyboy/CLionProjects/convertor /home/rustyboy/CLionProjects/convertor /home/rustyboy/CLionProjects/convertor /home/rustyboy/CLionProjects/convertor /home/rustyboy/CLionProjects/convertor/CMakeFiles/convertor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/convertor.dir/depend

