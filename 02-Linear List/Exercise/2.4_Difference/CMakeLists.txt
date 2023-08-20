cmake_minimum_required(VERSION 3.25)
project(2_4_Difference)

set(CMAKE_CXX_STANDARD 20)

add_executable(Difference Difference.cpp Difference.h Difference-main.cpp)
add_library(DifferenceLib ../../TextBook/02_LinkList/LinkList.h ../../TextBook/02_LinkList/LinkList.cpp)
target_link_libraries(Difference DifferenceLib)