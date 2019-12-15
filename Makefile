# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/rustyboy/CLionProjects/convertor/CMakeFiles /home/rustyboy/CLionProjects/convertor/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/rustyboy/CLionProjects/convertor/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named play

# Build rule for target.
play: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 play
.PHONY : play

# fast build rule for target.
play/fast:
	$(MAKE) -f CMakeFiles/play.dir/build.make CMakeFiles/play.dir/build
.PHONY : play/fast

#=============================================================================
# Target rules for targets named convertor

# Build rule for target.
convertor: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 convertor
.PHONY : convertor

# fast build rule for target.
convertor/fast:
	$(MAKE) -f CMakeFiles/convertor.dir/build.make CMakeFiles/convertor.dir/build
.PHONY : convertor/fast

UserInterface.o: UserInterface.cpp.o

.PHONY : UserInterface.o

# target to build an object file
UserInterface.cpp.o:
	$(MAKE) -f CMakeFiles/convertor.dir/build.make CMakeFiles/convertor.dir/UserInterface.cpp.o
.PHONY : UserInterface.cpp.o

UserInterface.i: UserInterface.cpp.i

.PHONY : UserInterface.i

# target to preprocess a source file
UserInterface.cpp.i:
	$(MAKE) -f CMakeFiles/convertor.dir/build.make CMakeFiles/convertor.dir/UserInterface.cpp.i
.PHONY : UserInterface.cpp.i

UserInterface.s: UserInterface.cpp.s

.PHONY : UserInterface.s

# target to generate assembly for a file
UserInterface.cpp.s:
	$(MAKE) -f CMakeFiles/convertor.dir/build.make CMakeFiles/convertor.dir/UserInterface.cpp.s
.PHONY : UserInterface.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/convertor.dir/build.make CMakeFiles/convertor.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/convertor.dir/build.make CMakeFiles/convertor.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/convertor.dir/build.make CMakeFiles/convertor.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... play"
	@echo "... convertor"
	@echo "... UserInterface.o"
	@echo "... UserInterface.i"
	@echo "... UserInterface.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

