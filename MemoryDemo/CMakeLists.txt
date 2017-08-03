cmake_minimum_required(VERSION 3.7)
project(MemoryDemo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        MemoryDemo.cpp
        MemoryDemo.h)

add_executable(MemoryDemo ${SOURCE_FILES})