# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\NP\CLionProjects\zinali

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\NP\CLionProjects\zinali\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/zinali.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/zinali.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zinali.dir/flags.make

CMakeFiles/zinali.dir/main.c.obj: CMakeFiles/zinali.dir/flags.make
CMakeFiles/zinali.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\NP\CLionProjects\zinali\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/zinali.dir/main.c.obj"
	C:\clionming\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\zinali.dir\main.c.obj -c C:\Users\NP\CLionProjects\zinali\main.c

CMakeFiles/zinali.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/zinali.dir/main.c.i"
	C:\clionming\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\NP\CLionProjects\zinali\main.c > CMakeFiles\zinali.dir\main.c.i

CMakeFiles/zinali.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/zinali.dir/main.c.s"
	C:\clionming\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\NP\CLionProjects\zinali\main.c -o CMakeFiles\zinali.dir\main.c.s

# Object files for target zinali
zinali_OBJECTS = \
"CMakeFiles/zinali.dir/main.c.obj"

# External object files for target zinali
zinali_EXTERNAL_OBJECTS =

zinali.exe: CMakeFiles/zinali.dir/main.c.obj
zinali.exe: CMakeFiles/zinali.dir/build.make
zinali.exe: CMakeFiles/zinali.dir/linklibs.rsp
zinali.exe: CMakeFiles/zinali.dir/objects1.rsp
zinali.exe: CMakeFiles/zinali.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\NP\CLionProjects\zinali\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable zinali.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\zinali.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zinali.dir/build: zinali.exe
.PHONY : CMakeFiles/zinali.dir/build

CMakeFiles/zinali.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\zinali.dir\cmake_clean.cmake
.PHONY : CMakeFiles/zinali.dir/clean

CMakeFiles/zinali.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\NP\CLionProjects\zinali C:\Users\NP\CLionProjects\zinali C:\Users\NP\CLionProjects\zinali\cmake-build-debug C:\Users\NP\CLionProjects\zinali\cmake-build-debug C:\Users\NP\CLionProjects\zinali\cmake-build-debug\CMakeFiles\zinali.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zinali.dir/depend

