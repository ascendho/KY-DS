cmake_minimum_required(VERSION 3.25)
project(2_6_Max)

set(CMAKE_CXX_STANDARD 20)

add_executable(Max Max.cpp Max.h Max-main.cpp)
add_library(MaxLib ../../TextBook/02_LinkList/LinkList.h ../../TextBook/02_LinkList/LinkList.cpp)
target_link_libraries(Max MaxLib)