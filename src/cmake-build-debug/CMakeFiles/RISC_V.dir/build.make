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
CMAKE_SOURCE_DIR = /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RISC_V.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/RISC_V.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/RISC_V.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RISC_V.dir/flags.make

CMakeFiles/RISC_V.dir/parser/parser.cpp.o: CMakeFiles/RISC_V.dir/flags.make
CMakeFiles/RISC_V.dir/parser/parser.cpp.o: ../parser/parser.cpp
CMakeFiles/RISC_V.dir/parser/parser.cpp.o: CMakeFiles/RISC_V.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RISC_V.dir/parser/parser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RISC_V.dir/parser/parser.cpp.o -MF CMakeFiles/RISC_V.dir/parser/parser.cpp.o.d -o CMakeFiles/RISC_V.dir/parser/parser.cpp.o -c /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/parser/parser.cpp

CMakeFiles/RISC_V.dir/parser/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RISC_V.dir/parser/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/parser/parser.cpp > CMakeFiles/RISC_V.dir/parser/parser.cpp.i

CMakeFiles/RISC_V.dir/parser/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RISC_V.dir/parser/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/parser/parser.cpp -o CMakeFiles/RISC_V.dir/parser/parser.cpp.s

CMakeFiles/RISC_V.dir/memory/memory.cpp.o: CMakeFiles/RISC_V.dir/flags.make
CMakeFiles/RISC_V.dir/memory/memory.cpp.o: ../memory/memory.cpp
CMakeFiles/RISC_V.dir/memory/memory.cpp.o: CMakeFiles/RISC_V.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RISC_V.dir/memory/memory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RISC_V.dir/memory/memory.cpp.o -MF CMakeFiles/RISC_V.dir/memory/memory.cpp.o.d -o CMakeFiles/RISC_V.dir/memory/memory.cpp.o -c /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/memory/memory.cpp

CMakeFiles/RISC_V.dir/memory/memory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RISC_V.dir/memory/memory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/memory/memory.cpp > CMakeFiles/RISC_V.dir/memory/memory.cpp.i

CMakeFiles/RISC_V.dir/memory/memory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RISC_V.dir/memory/memory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/memory/memory.cpp -o CMakeFiles/RISC_V.dir/memory/memory.cpp.s

CMakeFiles/RISC_V.dir/RegisterFile/RegisterFile.cpp.o: CMakeFiles/RISC_V.dir/flags.make
CMakeFiles/RISC_V.dir/RegisterFile/RegisterFile.cpp.o: ../RegisterFile/RegisterFile.cpp
CMakeFiles/RISC_V.dir/RegisterFile/RegisterFile.cpp.o: CMakeFiles/RISC_V.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RISC_V.dir/RegisterFile/RegisterFile.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RISC_V.dir/RegisterFile/RegisterFile.cpp.o -MF CMakeFiles/RISC_V.dir/RegisterFile/RegisterFile.cpp.o.d -o CMakeFiles/RISC_V.dir/RegisterFile/RegisterFile.cpp.o -c /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/RegisterFile/RegisterFile.cpp

CMakeFiles/RISC_V.dir/RegisterFile/RegisterFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RISC_V.dir/RegisterFile/RegisterFile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/RegisterFile/RegisterFile.cpp > CMakeFiles/RISC_V.dir/RegisterFile/RegisterFile.cpp.i

CMakeFiles/RISC_V.dir/RegisterFile/RegisterFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RISC_V.dir/RegisterFile/RegisterFile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/RegisterFile/RegisterFile.cpp -o CMakeFiles/RISC_V.dir/RegisterFile/RegisterFile.cpp.s

CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBuffer.cpp.o: CMakeFiles/RISC_V.dir/flags.make
CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBuffer.cpp.o: ../ReorderBuffer/ReorderBuffer.cpp
CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBuffer.cpp.o: CMakeFiles/RISC_V.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBuffer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBuffer.cpp.o -MF CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBuffer.cpp.o.d -o CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBuffer.cpp.o -c /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReorderBuffer/ReorderBuffer.cpp

CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBuffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReorderBuffer/ReorderBuffer.cpp > CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBuffer.cpp.i

CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBuffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReorderBuffer/ReorderBuffer.cpp -o CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBuffer.cpp.s

CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBufferType.cpp.o: CMakeFiles/RISC_V.dir/flags.make
CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBufferType.cpp.o: ../ReorderBuffer/ReorderBufferType.cpp
CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBufferType.cpp.o: CMakeFiles/RISC_V.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBufferType.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBufferType.cpp.o -MF CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBufferType.cpp.o.d -o CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBufferType.cpp.o -c /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReorderBuffer/ReorderBufferType.cpp

CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBufferType.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBufferType.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReorderBuffer/ReorderBufferType.cpp > CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBufferType.cpp.i

CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBufferType.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBufferType.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReorderBuffer/ReorderBufferType.cpp -o CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBufferType.cpp.s

CMakeFiles/RISC_V.dir/ReservationStation/ReservationStation.cpp.o: CMakeFiles/RISC_V.dir/flags.make
CMakeFiles/RISC_V.dir/ReservationStation/ReservationStation.cpp.o: ../ReservationStation/ReservationStation.cpp
CMakeFiles/RISC_V.dir/ReservationStation/ReservationStation.cpp.o: CMakeFiles/RISC_V.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/RISC_V.dir/ReservationStation/ReservationStation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RISC_V.dir/ReservationStation/ReservationStation.cpp.o -MF CMakeFiles/RISC_V.dir/ReservationStation/ReservationStation.cpp.o.d -o CMakeFiles/RISC_V.dir/ReservationStation/ReservationStation.cpp.o -c /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReservationStation/ReservationStation.cpp

CMakeFiles/RISC_V.dir/ReservationStation/ReservationStation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RISC_V.dir/ReservationStation/ReservationStation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReservationStation/ReservationStation.cpp > CMakeFiles/RISC_V.dir/ReservationStation/ReservationStation.cpp.i

CMakeFiles/RISC_V.dir/ReservationStation/ReservationStation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RISC_V.dir/ReservationStation/ReservationStation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReservationStation/ReservationStation.cpp -o CMakeFiles/RISC_V.dir/ReservationStation/ReservationStation.cpp.s

CMakeFiles/RISC_V.dir/ReservationStation/ReservationStationType.cpp.o: CMakeFiles/RISC_V.dir/flags.make
CMakeFiles/RISC_V.dir/ReservationStation/ReservationStationType.cpp.o: ../ReservationStation/ReservationStationType.cpp
CMakeFiles/RISC_V.dir/ReservationStation/ReservationStationType.cpp.o: CMakeFiles/RISC_V.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/RISC_V.dir/ReservationStation/ReservationStationType.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RISC_V.dir/ReservationStation/ReservationStationType.cpp.o -MF CMakeFiles/RISC_V.dir/ReservationStation/ReservationStationType.cpp.o.d -o CMakeFiles/RISC_V.dir/ReservationStation/ReservationStationType.cpp.o -c /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReservationStation/ReservationStationType.cpp

CMakeFiles/RISC_V.dir/ReservationStation/ReservationStationType.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RISC_V.dir/ReservationStation/ReservationStationType.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReservationStation/ReservationStationType.cpp > CMakeFiles/RISC_V.dir/ReservationStation/ReservationStationType.cpp.i

CMakeFiles/RISC_V.dir/ReservationStation/ReservationStationType.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RISC_V.dir/ReservationStation/ReservationStationType.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/ReservationStation/ReservationStationType.cpp -o CMakeFiles/RISC_V.dir/ReservationStation/ReservationStationType.cpp.s

CMakeFiles/RISC_V.dir/predictor/predictor.cpp.o: CMakeFiles/RISC_V.dir/flags.make
CMakeFiles/RISC_V.dir/predictor/predictor.cpp.o: ../predictor/predictor.cpp
CMakeFiles/RISC_V.dir/predictor/predictor.cpp.o: CMakeFiles/RISC_V.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/RISC_V.dir/predictor/predictor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RISC_V.dir/predictor/predictor.cpp.o -MF CMakeFiles/RISC_V.dir/predictor/predictor.cpp.o.d -o CMakeFiles/RISC_V.dir/predictor/predictor.cpp.o -c /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/predictor/predictor.cpp

CMakeFiles/RISC_V.dir/predictor/predictor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RISC_V.dir/predictor/predictor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/predictor/predictor.cpp > CMakeFiles/RISC_V.dir/predictor/predictor.cpp.i

CMakeFiles/RISC_V.dir/predictor/predictor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RISC_V.dir/predictor/predictor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/predictor/predictor.cpp -o CMakeFiles/RISC_V.dir/predictor/predictor.cpp.s

CMakeFiles/RISC_V.dir/main/main.cpp.o: CMakeFiles/RISC_V.dir/flags.make
CMakeFiles/RISC_V.dir/main/main.cpp.o: ../main/main.cpp
CMakeFiles/RISC_V.dir/main/main.cpp.o: CMakeFiles/RISC_V.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/RISC_V.dir/main/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RISC_V.dir/main/main.cpp.o -MF CMakeFiles/RISC_V.dir/main/main.cpp.o.d -o CMakeFiles/RISC_V.dir/main/main.cpp.o -c /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/main/main.cpp

CMakeFiles/RISC_V.dir/main/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RISC_V.dir/main/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/main/main.cpp > CMakeFiles/RISC_V.dir/main/main.cpp.i

CMakeFiles/RISC_V.dir/main/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RISC_V.dir/main/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/main/main.cpp -o CMakeFiles/RISC_V.dir/main/main.cpp.s

CMakeFiles/RISC_V.dir/utils/utils.cpp.o: CMakeFiles/RISC_V.dir/flags.make
CMakeFiles/RISC_V.dir/utils/utils.cpp.o: ../utils/utils.cpp
CMakeFiles/RISC_V.dir/utils/utils.cpp.o: CMakeFiles/RISC_V.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/RISC_V.dir/utils/utils.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RISC_V.dir/utils/utils.cpp.o -MF CMakeFiles/RISC_V.dir/utils/utils.cpp.o.d -o CMakeFiles/RISC_V.dir/utils/utils.cpp.o -c /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/utils/utils.cpp

CMakeFiles/RISC_V.dir/utils/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RISC_V.dir/utils/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/utils/utils.cpp > CMakeFiles/RISC_V.dir/utils/utils.cpp.i

CMakeFiles/RISC_V.dir/utils/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RISC_V.dir/utils/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/utils/utils.cpp -o CMakeFiles/RISC_V.dir/utils/utils.cpp.s

# Object files for target RISC_V
RISC_V_OBJECTS = \
"CMakeFiles/RISC_V.dir/parser/parser.cpp.o" \
"CMakeFiles/RISC_V.dir/memory/memory.cpp.o" \
"CMakeFiles/RISC_V.dir/RegisterFile/RegisterFile.cpp.o" \
"CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBuffer.cpp.o" \
"CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBufferType.cpp.o" \
"CMakeFiles/RISC_V.dir/ReservationStation/ReservationStation.cpp.o" \
"CMakeFiles/RISC_V.dir/ReservationStation/ReservationStationType.cpp.o" \
"CMakeFiles/RISC_V.dir/predictor/predictor.cpp.o" \
"CMakeFiles/RISC_V.dir/main/main.cpp.o" \
"CMakeFiles/RISC_V.dir/utils/utils.cpp.o"

# External object files for target RISC_V
RISC_V_EXTERNAL_OBJECTS =

RISC_V: CMakeFiles/RISC_V.dir/parser/parser.cpp.o
RISC_V: CMakeFiles/RISC_V.dir/memory/memory.cpp.o
RISC_V: CMakeFiles/RISC_V.dir/RegisterFile/RegisterFile.cpp.o
RISC_V: CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBuffer.cpp.o
RISC_V: CMakeFiles/RISC_V.dir/ReorderBuffer/ReorderBufferType.cpp.o
RISC_V: CMakeFiles/RISC_V.dir/ReservationStation/ReservationStation.cpp.o
RISC_V: CMakeFiles/RISC_V.dir/ReservationStation/ReservationStationType.cpp.o
RISC_V: CMakeFiles/RISC_V.dir/predictor/predictor.cpp.o
RISC_V: CMakeFiles/RISC_V.dir/main/main.cpp.o
RISC_V: CMakeFiles/RISC_V.dir/utils/utils.cpp.o
RISC_V: CMakeFiles/RISC_V.dir/build.make
RISC_V: CMakeFiles/RISC_V.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable RISC_V"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RISC_V.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RISC_V.dir/build: RISC_V
.PHONY : CMakeFiles/RISC_V.dir/build

CMakeFiles/RISC_V.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RISC_V.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RISC_V.dir/clean

CMakeFiles/RISC_V.dir/depend:
	cd /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/cmake-build-debug /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/cmake-build-debug /mnt/d/HuaweiMoveData/Users/86180/Desktop/PPCA/RISC-V/src/cmake-build-debug/CMakeFiles/RISC_V.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RISC_V.dir/depend
