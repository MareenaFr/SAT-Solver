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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/m22franc/ece650/m22franc/pa2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/m22franc/ece650/m22franc/pa2/build

# Include any dependencies generated for this target.
include CMakeFiles/tests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests.dir/flags.make

CMakeFiles/tests.dir/test.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m22franc/ece650/m22franc/pa2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tests.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/test.cpp.o -c /home/m22franc/ece650/m22franc/pa2/test.cpp

CMakeFiles/tests.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m22franc/ece650/m22franc/pa2/test.cpp > CMakeFiles/tests.dir/test.cpp.i

CMakeFiles/tests.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m22franc/ece650/m22franc/pa2/test.cpp -o CMakeFiles/tests.dir/test.cpp.s

CMakeFiles/tests.dir/tseitinTransformer.cc.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/tseitinTransformer.cc.o: ../tseitinTransformer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m22franc/ece650/m22franc/pa2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tests.dir/tseitinTransformer.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/tseitinTransformer.cc.o -c /home/m22franc/ece650/m22franc/pa2/tseitinTransformer.cc

CMakeFiles/tests.dir/tseitinTransformer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/tseitinTransformer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m22franc/ece650/m22franc/pa2/tseitinTransformer.cc > CMakeFiles/tests.dir/tseitinTransformer.cc.i

CMakeFiles/tests.dir/tseitinTransformer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/tseitinTransformer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m22franc/ece650/m22franc/pa2/tseitinTransformer.cc -o CMakeFiles/tests.dir/tseitinTransformer.cc.s

CMakeFiles/tests.dir/satSolver.cc.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/satSolver.cc.o: ../satSolver.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m22franc/ece650/m22franc/pa2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tests.dir/satSolver.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/satSolver.cc.o -c /home/m22franc/ece650/m22franc/pa2/satSolver.cc

CMakeFiles/tests.dir/satSolver.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/satSolver.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m22franc/ece650/m22franc/pa2/satSolver.cc > CMakeFiles/tests.dir/satSolver.cc.i

CMakeFiles/tests.dir/satSolver.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/satSolver.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m22franc/ece650/m22franc/pa2/satSolver.cc -o CMakeFiles/tests.dir/satSolver.cc.s

CMakeFiles/tests.dir/parser.cc.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/parser.cc.o: ../parser.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m22franc/ece650/m22franc/pa2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tests.dir/parser.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/parser.cc.o -c /home/m22franc/ece650/m22franc/pa2/parser.cc

CMakeFiles/tests.dir/parser.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/parser.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m22franc/ece650/m22franc/pa2/parser.cc > CMakeFiles/tests.dir/parser.cc.i

CMakeFiles/tests.dir/parser.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/parser.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m22franc/ece650/m22franc/pa2/parser.cc -o CMakeFiles/tests.dir/parser.cc.s

CMakeFiles/tests.dir/tokenizer.cc.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/tokenizer.cc.o: ../tokenizer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m22franc/ece650/m22franc/pa2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tests.dir/tokenizer.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/tokenizer.cc.o -c /home/m22franc/ece650/m22franc/pa2/tokenizer.cc

CMakeFiles/tests.dir/tokenizer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/tokenizer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m22franc/ece650/m22franc/pa2/tokenizer.cc > CMakeFiles/tests.dir/tokenizer.cc.i

CMakeFiles/tests.dir/tokenizer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/tokenizer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m22franc/ece650/m22franc/pa2/tokenizer.cc -o CMakeFiles/tests.dir/tokenizer.cc.s

CMakeFiles/tests.dir/treeNode.cc.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/treeNode.cc.o: ../treeNode.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m22franc/ece650/m22franc/pa2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/tests.dir/treeNode.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/treeNode.cc.o -c /home/m22franc/ece650/m22franc/pa2/treeNode.cc

CMakeFiles/tests.dir/treeNode.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/treeNode.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m22franc/ece650/m22franc/pa2/treeNode.cc > CMakeFiles/tests.dir/treeNode.cc.i

CMakeFiles/tests.dir/treeNode.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/treeNode.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m22franc/ece650/m22franc/pa2/treeNode.cc -o CMakeFiles/tests.dir/treeNode.cc.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/test.cpp.o" \
"CMakeFiles/tests.dir/tseitinTransformer.cc.o" \
"CMakeFiles/tests.dir/satSolver.cc.o" \
"CMakeFiles/tests.dir/parser.cc.o" \
"CMakeFiles/tests.dir/tokenizer.cc.o" \
"CMakeFiles/tests.dir/treeNode.cc.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

tests: CMakeFiles/tests.dir/test.cpp.o
tests: CMakeFiles/tests.dir/tseitinTransformer.cc.o
tests: CMakeFiles/tests.dir/satSolver.cc.o
tests: CMakeFiles/tests.dir/parser.cc.o
tests: CMakeFiles/tests.dir/tokenizer.cc.o
tests: CMakeFiles/tests.dir/treeNode.cc.o
tests: CMakeFiles/tests.dir/build.make
tests: minisat/libminisat.a
tests: /usr/lib/x86_64-linux-gnu/libz.so
tests: CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/m22franc/ece650/m22franc/pa2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests.dir/build: tests

.PHONY : CMakeFiles/tests.dir/build

CMakeFiles/tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tests.dir/clean

CMakeFiles/tests.dir/depend:
	cd /home/m22franc/ece650/m22franc/pa2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/m22franc/ece650/m22franc/pa2 /home/m22franc/ece650/m22franc/pa2 /home/m22franc/ece650/m22franc/pa2/build /home/m22franc/ece650/m22franc/pa2/build /home/m22franc/ece650/m22franc/pa2/build/CMakeFiles/tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tests.dir/depend

