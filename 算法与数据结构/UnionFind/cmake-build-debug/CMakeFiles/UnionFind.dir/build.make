# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ahojcn/Code/my-leet-code/算法与数据结构/UnionFind

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ahojcn/Code/my-leet-code/算法与数据结构/UnionFind/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/UnionFind.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/UnionFind.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UnionFind.dir/flags.make

CMakeFiles/UnionFind.dir/main.cpp.o: CMakeFiles/UnionFind.dir/flags.make
CMakeFiles/UnionFind.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ahojcn/Code/my-leet-code/算法与数据结构/UnionFind/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/UnionFind.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UnionFind.dir/main.cpp.o -c /Users/ahojcn/Code/my-leet-code/算法与数据结构/UnionFind/main.cpp

CMakeFiles/UnionFind.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UnionFind.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ahojcn/Code/my-leet-code/算法与数据结构/UnionFind/main.cpp > CMakeFiles/UnionFind.dir/main.cpp.i

CMakeFiles/UnionFind.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UnionFind.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ahojcn/Code/my-leet-code/算法与数据结构/UnionFind/main.cpp -o CMakeFiles/UnionFind.dir/main.cpp.s

# Object files for target UnionFind
UnionFind_OBJECTS = \
"CMakeFiles/UnionFind.dir/main.cpp.o"

# External object files for target UnionFind
UnionFind_EXTERNAL_OBJECTS =

UnionFind: CMakeFiles/UnionFind.dir/main.cpp.o
UnionFind: CMakeFiles/UnionFind.dir/build.make
UnionFind: CMakeFiles/UnionFind.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ahojcn/Code/my-leet-code/算法与数据结构/UnionFind/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable UnionFind"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UnionFind.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UnionFind.dir/build: UnionFind

.PHONY : CMakeFiles/UnionFind.dir/build

CMakeFiles/UnionFind.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UnionFind.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UnionFind.dir/clean

CMakeFiles/UnionFind.dir/depend:
	cd /Users/ahojcn/Code/my-leet-code/算法与数据结构/UnionFind/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ahojcn/Code/my-leet-code/算法与数据结构/UnionFind /Users/ahojcn/Code/my-leet-code/算法与数据结构/UnionFind /Users/ahojcn/Code/my-leet-code/算法与数据结构/UnionFind/cmake-build-debug /Users/ahojcn/Code/my-leet-code/算法与数据结构/UnionFind/cmake-build-debug /Users/ahojcn/Code/my-leet-code/算法与数据结构/UnionFind/cmake-build-debug/CMakeFiles/UnionFind.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UnionFind.dir/depend

