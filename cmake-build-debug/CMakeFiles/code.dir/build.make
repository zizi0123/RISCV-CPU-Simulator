# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/code.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/code.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/code.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/code.dir/flags.make

CMakeFiles/code.dir/src/parser/parser.cpp.o: CMakeFiles/code.dir/flags.make
CMakeFiles/code.dir/src/parser/parser.cpp.o: ../src/parser/parser.cpp
CMakeFiles/code.dir/src/parser/parser.cpp.o: CMakeFiles/code.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/code.dir/src/parser/parser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/code.dir/src/parser/parser.cpp.o -MF CMakeFiles/code.dir/src/parser/parser.cpp.o.d -o CMakeFiles/code.dir/src/parser/parser.cpp.o -c /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/parser/parser.cpp

CMakeFiles/code.dir/src/parser/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/code.dir/src/parser/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/parser/parser.cpp > CMakeFiles/code.dir/src/parser/parser.cpp.i

CMakeFiles/code.dir/src/parser/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/code.dir/src/parser/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/parser/parser.cpp -o CMakeFiles/code.dir/src/parser/parser.cpp.s

CMakeFiles/code.dir/src/memory/memory.cpp.o: CMakeFiles/code.dir/flags.make
CMakeFiles/code.dir/src/memory/memory.cpp.o: ../src/memory/memory.cpp
CMakeFiles/code.dir/src/memory/memory.cpp.o: CMakeFiles/code.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/code.dir/src/memory/memory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/code.dir/src/memory/memory.cpp.o -MF CMakeFiles/code.dir/src/memory/memory.cpp.o.d -o CMakeFiles/code.dir/src/memory/memory.cpp.o -c /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/memory/memory.cpp

CMakeFiles/code.dir/src/memory/memory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/code.dir/src/memory/memory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/memory/memory.cpp > CMakeFiles/code.dir/src/memory/memory.cpp.i

CMakeFiles/code.dir/src/memory/memory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/code.dir/src/memory/memory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/memory/memory.cpp -o CMakeFiles/code.dir/src/memory/memory.cpp.s

CMakeFiles/code.dir/src/RegisterFile/RegisterFile.cpp.o: CMakeFiles/code.dir/flags.make
CMakeFiles/code.dir/src/RegisterFile/RegisterFile.cpp.o: ../src/RegisterFile/RegisterFile.cpp
CMakeFiles/code.dir/src/RegisterFile/RegisterFile.cpp.o: CMakeFiles/code.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/code.dir/src/RegisterFile/RegisterFile.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/code.dir/src/RegisterFile/RegisterFile.cpp.o -MF CMakeFiles/code.dir/src/RegisterFile/RegisterFile.cpp.o.d -o CMakeFiles/code.dir/src/RegisterFile/RegisterFile.cpp.o -c /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/RegisterFile/RegisterFile.cpp

CMakeFiles/code.dir/src/RegisterFile/RegisterFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/code.dir/src/RegisterFile/RegisterFile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/RegisterFile/RegisterFile.cpp > CMakeFiles/code.dir/src/RegisterFile/RegisterFile.cpp.i

CMakeFiles/code.dir/src/RegisterFile/RegisterFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/code.dir/src/RegisterFile/RegisterFile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/RegisterFile/RegisterFile.cpp -o CMakeFiles/code.dir/src/RegisterFile/RegisterFile.cpp.s

CMakeFiles/code.dir/src/ReorderBuffer/ReorderBuffer.cpp.o: CMakeFiles/code.dir/flags.make
CMakeFiles/code.dir/src/ReorderBuffer/ReorderBuffer.cpp.o: ../src/ReorderBuffer/ReorderBuffer.cpp
CMakeFiles/code.dir/src/ReorderBuffer/ReorderBuffer.cpp.o: CMakeFiles/code.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/code.dir/src/ReorderBuffer/ReorderBuffer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/code.dir/src/ReorderBuffer/ReorderBuffer.cpp.o -MF CMakeFiles/code.dir/src/ReorderBuffer/ReorderBuffer.cpp.o.d -o CMakeFiles/code.dir/src/ReorderBuffer/ReorderBuffer.cpp.o -c /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReorderBuffer/ReorderBuffer.cpp

CMakeFiles/code.dir/src/ReorderBuffer/ReorderBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/code.dir/src/ReorderBuffer/ReorderBuffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReorderBuffer/ReorderBuffer.cpp > CMakeFiles/code.dir/src/ReorderBuffer/ReorderBuffer.cpp.i

CMakeFiles/code.dir/src/ReorderBuffer/ReorderBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/code.dir/src/ReorderBuffer/ReorderBuffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReorderBuffer/ReorderBuffer.cpp -o CMakeFiles/code.dir/src/ReorderBuffer/ReorderBuffer.cpp.s

CMakeFiles/code.dir/src/ReorderBuffer/ReorderBufferType.cpp.o: CMakeFiles/code.dir/flags.make
CMakeFiles/code.dir/src/ReorderBuffer/ReorderBufferType.cpp.o: ../src/ReorderBuffer/ReorderBufferType.cpp
CMakeFiles/code.dir/src/ReorderBuffer/ReorderBufferType.cpp.o: CMakeFiles/code.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/code.dir/src/ReorderBuffer/ReorderBufferType.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/code.dir/src/ReorderBuffer/ReorderBufferType.cpp.o -MF CMakeFiles/code.dir/src/ReorderBuffer/ReorderBufferType.cpp.o.d -o CMakeFiles/code.dir/src/ReorderBuffer/ReorderBufferType.cpp.o -c /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReorderBuffer/ReorderBufferType.cpp

CMakeFiles/code.dir/src/ReorderBuffer/ReorderBufferType.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/code.dir/src/ReorderBuffer/ReorderBufferType.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReorderBuffer/ReorderBufferType.cpp > CMakeFiles/code.dir/src/ReorderBuffer/ReorderBufferType.cpp.i

CMakeFiles/code.dir/src/ReorderBuffer/ReorderBufferType.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/code.dir/src/ReorderBuffer/ReorderBufferType.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReorderBuffer/ReorderBufferType.cpp -o CMakeFiles/code.dir/src/ReorderBuffer/ReorderBufferType.cpp.s

CMakeFiles/code.dir/src/ReservationStation/ReservationStation.cpp.o: CMakeFiles/code.dir/flags.make
CMakeFiles/code.dir/src/ReservationStation/ReservationStation.cpp.o: ../src/ReservationStation/ReservationStation.cpp
CMakeFiles/code.dir/src/ReservationStation/ReservationStation.cpp.o: CMakeFiles/code.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/code.dir/src/ReservationStation/ReservationStation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/code.dir/src/ReservationStation/ReservationStation.cpp.o -MF CMakeFiles/code.dir/src/ReservationStation/ReservationStation.cpp.o.d -o CMakeFiles/code.dir/src/ReservationStation/ReservationStation.cpp.o -c /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReservationStation/ReservationStation.cpp

CMakeFiles/code.dir/src/ReservationStation/ReservationStation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/code.dir/src/ReservationStation/ReservationStation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReservationStation/ReservationStation.cpp > CMakeFiles/code.dir/src/ReservationStation/ReservationStation.cpp.i

CMakeFiles/code.dir/src/ReservationStation/ReservationStation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/code.dir/src/ReservationStation/ReservationStation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReservationStation/ReservationStation.cpp -o CMakeFiles/code.dir/src/ReservationStation/ReservationStation.cpp.s

CMakeFiles/code.dir/src/ReservationStation/ReservationStationType.cpp.o: CMakeFiles/code.dir/flags.make
CMakeFiles/code.dir/src/ReservationStation/ReservationStationType.cpp.o: ../src/ReservationStation/ReservationStationType.cpp
CMakeFiles/code.dir/src/ReservationStation/ReservationStationType.cpp.o: CMakeFiles/code.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/code.dir/src/ReservationStation/ReservationStationType.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/code.dir/src/ReservationStation/ReservationStationType.cpp.o -MF CMakeFiles/code.dir/src/ReservationStation/ReservationStationType.cpp.o.d -o CMakeFiles/code.dir/src/ReservationStation/ReservationStationType.cpp.o -c /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReservationStation/ReservationStationType.cpp

CMakeFiles/code.dir/src/ReservationStation/ReservationStationType.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/code.dir/src/ReservationStation/ReservationStationType.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReservationStation/ReservationStationType.cpp > CMakeFiles/code.dir/src/ReservationStation/ReservationStationType.cpp.i

CMakeFiles/code.dir/src/ReservationStation/ReservationStationType.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/code.dir/src/ReservationStation/ReservationStationType.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReservationStation/ReservationStationType.cpp -o CMakeFiles/code.dir/src/ReservationStation/ReservationStationType.cpp.s

CMakeFiles/code.dir/src/predictor/predictor.cpp.o: CMakeFiles/code.dir/flags.make
CMakeFiles/code.dir/src/predictor/predictor.cpp.o: ../src/predictor/predictor.cpp
CMakeFiles/code.dir/src/predictor/predictor.cpp.o: CMakeFiles/code.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/code.dir/src/predictor/predictor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/code.dir/src/predictor/predictor.cpp.o -MF CMakeFiles/code.dir/src/predictor/predictor.cpp.o.d -o CMakeFiles/code.dir/src/predictor/predictor.cpp.o -c /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/predictor/predictor.cpp

CMakeFiles/code.dir/src/predictor/predictor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/code.dir/src/predictor/predictor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/predictor/predictor.cpp > CMakeFiles/code.dir/src/predictor/predictor.cpp.i

CMakeFiles/code.dir/src/predictor/predictor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/code.dir/src/predictor/predictor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/predictor/predictor.cpp -o CMakeFiles/code.dir/src/predictor/predictor.cpp.s

CMakeFiles/code.dir/src/main/main.cpp.o: CMakeFiles/code.dir/flags.make
CMakeFiles/code.dir/src/main/main.cpp.o: ../src/main/main.cpp
CMakeFiles/code.dir/src/main/main.cpp.o: CMakeFiles/code.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/code.dir/src/main/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/code.dir/src/main/main.cpp.o -MF CMakeFiles/code.dir/src/main/main.cpp.o.d -o CMakeFiles/code.dir/src/main/main.cpp.o -c /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/main/main.cpp

CMakeFiles/code.dir/src/main/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/code.dir/src/main/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/main/main.cpp > CMakeFiles/code.dir/src/main/main.cpp.i

CMakeFiles/code.dir/src/main/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/code.dir/src/main/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/main/main.cpp -o CMakeFiles/code.dir/src/main/main.cpp.s

CMakeFiles/code.dir/src/utils/utils.cpp.o: CMakeFiles/code.dir/flags.make
CMakeFiles/code.dir/src/utils/utils.cpp.o: ../src/utils/utils.cpp
CMakeFiles/code.dir/src/utils/utils.cpp.o: CMakeFiles/code.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/code.dir/src/utils/utils.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/code.dir/src/utils/utils.cpp.o -MF CMakeFiles/code.dir/src/utils/utils.cpp.o.d -o CMakeFiles/code.dir/src/utils/utils.cpp.o -c /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/utils/utils.cpp

CMakeFiles/code.dir/src/utils/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/code.dir/src/utils/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/utils/utils.cpp > CMakeFiles/code.dir/src/utils/utils.cpp.i

CMakeFiles/code.dir/src/utils/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/code.dir/src/utils/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/utils/utils.cpp -o CMakeFiles/code.dir/src/utils/utils.cpp.s

# Object files for target code
code_OBJECTS = \
"CMakeFiles/code.dir/src/parser/parser.cpp.o" \
"CMakeFiles/code.dir/src/memory/memory.cpp.o" \
"CMakeFiles/code.dir/src/RegisterFile/RegisterFile.cpp.o" \
"CMakeFiles/code.dir/src/ReorderBuffer/ReorderBuffer.cpp.o" \
"CMakeFiles/code.dir/src/ReorderBuffer/ReorderBufferType.cpp.o" \
"CMakeFiles/code.dir/src/ReservationStation/ReservationStation.cpp.o" \
"CMakeFiles/code.dir/src/ReservationStation/ReservationStationType.cpp.o" \
"CMakeFiles/code.dir/src/predictor/predictor.cpp.o" \
"CMakeFiles/code.dir/src/main/main.cpp.o" \
"CMakeFiles/code.dir/src/utils/utils.cpp.o"

# External object files for target code
code_EXTERNAL_OBJECTS =

code: CMakeFiles/code.dir/src/parser/parser.cpp.o
code: CMakeFiles/code.dir/src/memory/memory.cpp.o
code: CMakeFiles/code.dir/src/RegisterFile/RegisterFile.cpp.o
code: CMakeFiles/code.dir/src/ReorderBuffer/ReorderBuffer.cpp.o
code: CMakeFiles/code.dir/src/ReorderBuffer/ReorderBufferType.cpp.o
code: CMakeFiles/code.dir/src/ReservationStation/ReservationStation.cpp.o
code: CMakeFiles/code.dir/src/ReservationStation/ReservationStationType.cpp.o
code: CMakeFiles/code.dir/src/predictor/predictor.cpp.o
code: CMakeFiles/code.dir/src/main/main.cpp.o
code: CMakeFiles/code.dir/src/utils/utils.cpp.o
code: CMakeFiles/code.dir/build.make
code: CMakeFiles/code.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable code"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/code.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/code.dir/build: code
.PHONY : CMakeFiles/code.dir/build

CMakeFiles/code.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/code.dir/cmake_clean.cmake
.PHONY : CMakeFiles/code.dir/clean

CMakeFiles/code.dir/depend:
	cd /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/cmake-build-debug /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/cmake-build-debug /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/cmake-build-debug/CMakeFiles/code.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/code.dir/depend
