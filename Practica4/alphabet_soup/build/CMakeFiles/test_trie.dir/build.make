# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/1070/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1070/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup/build

# Include any dependencies generated for this target.
include CMakeFiles/test_trie.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_trie.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_trie.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_trie.dir/flags.make

CMakeFiles/test_trie.dir/test_trie.cpp.o: CMakeFiles/test_trie.dir/flags.make
CMakeFiles/test_trie.dir/test_trie.cpp.o: ../test_trie.cpp
CMakeFiles/test_trie.dir/test_trie.cpp.o: CMakeFiles/test_trie.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_trie.dir/test_trie.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_trie.dir/test_trie.cpp.o -MF CMakeFiles/test_trie.dir/test_trie.cpp.o.d -o CMakeFiles/test_trie.dir/test_trie.cpp.o -c /home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup/test_trie.cpp

CMakeFiles/test_trie.dir/test_trie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_trie.dir/test_trie.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup/test_trie.cpp > CMakeFiles/test_trie.dir/test_trie.cpp.i

CMakeFiles/test_trie.dir/test_trie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_trie.dir/test_trie.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup/test_trie.cpp -o CMakeFiles/test_trie.dir/test_trie.cpp.s

CMakeFiles/test_trie.dir/trie.cpp.o: CMakeFiles/test_trie.dir/flags.make
CMakeFiles/test_trie.dir/trie.cpp.o: ../trie.cpp
CMakeFiles/test_trie.dir/trie.cpp.o: CMakeFiles/test_trie.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_trie.dir/trie.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_trie.dir/trie.cpp.o -MF CMakeFiles/test_trie.dir/trie.cpp.o.d -o CMakeFiles/test_trie.dir/trie.cpp.o -c /home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup/trie.cpp

CMakeFiles/test_trie.dir/trie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_trie.dir/trie.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup/trie.cpp > CMakeFiles/test_trie.dir/trie.cpp.i

CMakeFiles/test_trie.dir/trie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_trie.dir/trie.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup/trie.cpp -o CMakeFiles/test_trie.dir/trie.cpp.s

CMakeFiles/test_trie.dir/trie_node.cpp.o: CMakeFiles/test_trie.dir/flags.make
CMakeFiles/test_trie.dir/trie_node.cpp.o: ../trie_node.cpp
CMakeFiles/test_trie.dir/trie_node.cpp.o: CMakeFiles/test_trie.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test_trie.dir/trie_node.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_trie.dir/trie_node.cpp.o -MF CMakeFiles/test_trie.dir/trie_node.cpp.o.d -o CMakeFiles/test_trie.dir/trie_node.cpp.o -c /home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup/trie_node.cpp

CMakeFiles/test_trie.dir/trie_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_trie.dir/trie_node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup/trie_node.cpp > CMakeFiles/test_trie.dir/trie_node.cpp.i

CMakeFiles/test_trie.dir/trie_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_trie.dir/trie_node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup/trie_node.cpp -o CMakeFiles/test_trie.dir/trie_node.cpp.s

# Object files for target test_trie
test_trie_OBJECTS = \
"CMakeFiles/test_trie.dir/test_trie.cpp.o" \
"CMakeFiles/test_trie.dir/trie.cpp.o" \
"CMakeFiles/test_trie.dir/trie_node.cpp.o"

# External object files for target test_trie
test_trie_EXTERNAL_OBJECTS =

test_trie: CMakeFiles/test_trie.dir/test_trie.cpp.o
test_trie: CMakeFiles/test_trie.dir/trie.cpp.o
test_trie: CMakeFiles/test_trie.dir/trie_node.cpp.o
test_trie: CMakeFiles/test_trie.dir/build.make
test_trie: CMakeFiles/test_trie.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable test_trie"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_trie.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_trie.dir/build: test_trie
.PHONY : CMakeFiles/test_trie.dir/build

CMakeFiles/test_trie.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_trie.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_trie.dir/clean

CMakeFiles/test_trie.dir/depend:
	cd /home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup /home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup /home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup/build /home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup/build /home/anonymusriv/Escritorio/UCO/2curso/Ed/Practica4/alphabet_soup/build/CMakeFiles/test_trie.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_trie.dir/depend
