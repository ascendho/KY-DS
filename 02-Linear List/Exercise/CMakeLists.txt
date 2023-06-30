cmake_minimum_required(VERSION 3.25)
project(Exercise)

set(CMAKE_CXX_STANDARD 20)

# Inverse
add_executable(Inverse Inverse.cpp Inverse.h Inverse-main.cpp)
add_library(InverseLib ../TextBook/LinkList.h ../TextBook/LinkList.cpp)
target_link_libraries(Inverse InverseLib)