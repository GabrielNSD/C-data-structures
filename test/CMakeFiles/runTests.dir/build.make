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
CMAKE_SOURCE_DIR = /home/gabrielnsd/Documents/UFRN/EDI/C-data-structures/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gabrielnsd/Documents/UFRN/EDI/C-data-structures/test

# Include any dependencies generated for this target.
include CMakeFiles/runTests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/runTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runTests.dir/flags.make

CMakeFiles/runTests.dir/testDoublyLinkedList2.cpp.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/testDoublyLinkedList2.cpp.o: testDoublyLinkedList2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabrielnsd/Documents/UFRN/EDI/C-data-structures/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runTests.dir/testDoublyLinkedList2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTests.dir/testDoublyLinkedList2.cpp.o -c /home/gabrielnsd/Documents/UFRN/EDI/C-data-structures/test/testDoublyLinkedList2.cpp

CMakeFiles/runTests.dir/testDoublyLinkedList2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/testDoublyLinkedList2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabrielnsd/Documents/UFRN/EDI/C-data-structures/test/testDoublyLinkedList2.cpp > CMakeFiles/runTests.dir/testDoublyLinkedList2.cpp.i

CMakeFiles/runTests.dir/testDoublyLinkedList2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/testDoublyLinkedList2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabrielnsd/Documents/UFRN/EDI/C-data-structures/test/testDoublyLinkedList2.cpp -o CMakeFiles/runTests.dir/testDoublyLinkedList2.cpp.s

# Object files for target runTests
runTests_OBJECTS = \
"CMakeFiles/runTests.dir/testDoublyLinkedList2.cpp.o"

# External object files for target runTests
runTests_EXTERNAL_OBJECTS =

runTests: CMakeFiles/runTests.dir/testDoublyLinkedList2.cpp.o
runTests: CMakeFiles/runTests.dir/build.make
runTests: /usr/lib/x86_64-linux-gnu/libgtest.a
runTests: CMakeFiles/runTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gabrielnsd/Documents/UFRN/EDI/C-data-structures/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable runTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runTests.dir/build: runTests

.PHONY : CMakeFiles/runTests.dir/build

CMakeFiles/runTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/runTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/runTests.dir/clean

CMakeFiles/runTests.dir/depend:
	cd /home/gabrielnsd/Documents/UFRN/EDI/C-data-structures/test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gabrielnsd/Documents/UFRN/EDI/C-data-structures/test /home/gabrielnsd/Documents/UFRN/EDI/C-data-structures/test /home/gabrielnsd/Documents/UFRN/EDI/C-data-structures/test /home/gabrielnsd/Documents/UFRN/EDI/C-data-structures/test /home/gabrielnsd/Documents/UFRN/EDI/C-data-structures/test/CMakeFiles/runTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/runTests.dir/depend

