cmake_minimum_required(VERSION 3.25)
project(2_7_Inverse)

set(CMAKE_CXX_STANDARD 20)

# Inverse
add_executable(Inverse Inverse.cpp Inverse.h Inverse-main.cpp)
add_library(InverseLib ../../TextBook/02_LinkList/LinkList.h ../../TextBook/02_LinkList/LinkList.cpp)
target_link_libraries(Inverse InverseLib)