# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yzchen/work/ClionProjects/testopengl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yzchen/work/ClionProjects/testopengl

# Include any dependencies generated for this target.
include CMakeFiles/testopengl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testopengl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testopengl.dir/flags.make

CMakeFiles/testopengl.dir/main.cpp.o: CMakeFiles/testopengl.dir/flags.make
CMakeFiles/testopengl.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yzchen/work/ClionProjects/testopengl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testopengl.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testopengl.dir/main.cpp.o -c /home/yzchen/work/ClionProjects/testopengl/main.cpp

CMakeFiles/testopengl.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testopengl.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yzchen/work/ClionProjects/testopengl/main.cpp > CMakeFiles/testopengl.dir/main.cpp.i

CMakeFiles/testopengl.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testopengl.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yzchen/work/ClionProjects/testopengl/main.cpp -o CMakeFiles/testopengl.dir/main.cpp.s

CMakeFiles/testopengl.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/testopengl.dir/main.cpp.o.requires

CMakeFiles/testopengl.dir/main.cpp.o.provides: CMakeFiles/testopengl.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/testopengl.dir/build.make CMakeFiles/testopengl.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/testopengl.dir/main.cpp.o.provides

CMakeFiles/testopengl.dir/main.cpp.o.provides.build: CMakeFiles/testopengl.dir/main.cpp.o


CMakeFiles/testopengl.dir/openglviewer.cpp.o: CMakeFiles/testopengl.dir/flags.make
CMakeFiles/testopengl.dir/openglviewer.cpp.o: openglviewer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yzchen/work/ClionProjects/testopengl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/testopengl.dir/openglviewer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testopengl.dir/openglviewer.cpp.o -c /home/yzchen/work/ClionProjects/testopengl/openglviewer.cpp

CMakeFiles/testopengl.dir/openglviewer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testopengl.dir/openglviewer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yzchen/work/ClionProjects/testopengl/openglviewer.cpp > CMakeFiles/testopengl.dir/openglviewer.cpp.i

CMakeFiles/testopengl.dir/openglviewer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testopengl.dir/openglviewer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yzchen/work/ClionProjects/testopengl/openglviewer.cpp -o CMakeFiles/testopengl.dir/openglviewer.cpp.s

CMakeFiles/testopengl.dir/openglviewer.cpp.o.requires:

.PHONY : CMakeFiles/testopengl.dir/openglviewer.cpp.o.requires

CMakeFiles/testopengl.dir/openglviewer.cpp.o.provides: CMakeFiles/testopengl.dir/openglviewer.cpp.o.requires
	$(MAKE) -f CMakeFiles/testopengl.dir/build.make CMakeFiles/testopengl.dir/openglviewer.cpp.o.provides.build
.PHONY : CMakeFiles/testopengl.dir/openglviewer.cpp.o.provides

CMakeFiles/testopengl.dir/openglviewer.cpp.o.provides.build: CMakeFiles/testopengl.dir/openglviewer.cpp.o


# Object files for target testopengl
testopengl_OBJECTS = \
"CMakeFiles/testopengl.dir/main.cpp.o" \
"CMakeFiles/testopengl.dir/openglviewer.cpp.o"

# External object files for target testopengl
testopengl_EXTERNAL_OBJECTS =

testopengl: CMakeFiles/testopengl.dir/main.cpp.o
testopengl: CMakeFiles/testopengl.dir/openglviewer.cpp.o
testopengl: CMakeFiles/testopengl.dir/build.make
testopengl: /usr/lib/x86_64-linux-gnu/libGLU.so
testopengl: /usr/lib/x86_64-linux-gnu/libGL.so
testopengl: /usr/lib/x86_64-linux-gnu/libglut.so
testopengl: /usr/lib/x86_64-linux-gnu/libXmu.so
testopengl: /usr/lib/x86_64-linux-gnu/libXi.so
testopengl: CMakeFiles/testopengl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yzchen/work/ClionProjects/testopengl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable testopengl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testopengl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testopengl.dir/build: testopengl

.PHONY : CMakeFiles/testopengl.dir/build

CMakeFiles/testopengl.dir/requires: CMakeFiles/testopengl.dir/main.cpp.o.requires
CMakeFiles/testopengl.dir/requires: CMakeFiles/testopengl.dir/openglviewer.cpp.o.requires

.PHONY : CMakeFiles/testopengl.dir/requires

CMakeFiles/testopengl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testopengl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testopengl.dir/clean

CMakeFiles/testopengl.dir/depend:
	cd /home/yzchen/work/ClionProjects/testopengl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yzchen/work/ClionProjects/testopengl /home/yzchen/work/ClionProjects/testopengl /home/yzchen/work/ClionProjects/testopengl /home/yzchen/work/ClionProjects/testopengl /home/yzchen/work/ClionProjects/testopengl/CMakeFiles/testopengl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testopengl.dir/depend

