cmake_minimum_required(VERSION 3.7)
project(RoundRobin)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        main.cpp
        RoundRobin.h
        quick_sort.h
        )

add_executable(RoundRobin ${SOURCE_FILES})