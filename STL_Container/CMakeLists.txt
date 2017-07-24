cmake_minimum_required(VERSION 3.7)
project(STL_Container)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp PacketBuffer.h IPPacket.h)
add_executable(STL_Container ${SOURCE_FILES})