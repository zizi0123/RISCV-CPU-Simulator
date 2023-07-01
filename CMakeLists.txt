cmake_minimum_required(VERSION 3.16)
project(RISC_V)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/parser)
include_directories(src/RegisterFile)
include_directories(src/ReorderBuffer)
include_directories(src/ReservationStation)

add_executable(code
        src/parser/parser.cpp
        src/memory/memory.cpp
        src/RegisterFile/RegisterFile.cpp
        src/ReorderBuffer/ReorderBuffer.cpp
        src/ReorderBuffer/ReorderBufferType.cpp
        src/ReservationStation/ReservationStation.cpp
        src/ReservationStation/ReservationStationType.cpp
        src/predictor/predictor.cpp
        src/main/main.cpp
        src/utils/utils.cpp)

