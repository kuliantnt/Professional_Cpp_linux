cmake_minimum_required(VERSION 3.7)
project(STL_Container)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp PacketBuffer.h IPPacket.h Error.h Data.cpp Data.h BankAccount.h BuddyList.cpp BuddyList.h AccessList.cpp AccessList.h CableCompany.cpp CableCompany.h)
add_executable(STL_Container ${SOURCE_FILES})