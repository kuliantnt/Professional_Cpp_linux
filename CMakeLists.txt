cmake_minimum_required(VERSION 3.7)
project(Professional_Cpp_linux)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        MemoryDemo/main.cpp
        MemoryDemo/MemoryDemo.cpp
        MemoryDemo/MemoryDemo.h)

add_executable(Professional_Cpp_linux ${SOURCE_FILES})