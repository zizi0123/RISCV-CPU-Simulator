cmake_minimum_required(VERSION 3.22)
project(RISC_V)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/parser)
include_directories(src/RegisterFile)
include_directories(src/ReorderBuffer)
include_directories(src/ReservationStation)

add_executable(RISC_V
        parser/parser.cpp
        memory/memory.cpp
        RegisterFile/RegisterFile.cpp
        ReorderBuffer/ReorderBuffer.cpp
        ReorderBuffer/ReorderBufferType.cpp
        ReservationStation/ReservationStation.cpp
        ReservationStation/ReservationStationType.cpp
        predictor/predictor.cpp
        main/main.cpp
        utils/utils.cpp)

