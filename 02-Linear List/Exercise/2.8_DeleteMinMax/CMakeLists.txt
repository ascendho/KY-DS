cmake_minimum_required(VERSION 3.25)
project(2_8_DeleteMinMax)

set(CMAKE_CXX_STANDARD 20)

add_executable(DeleteMinMax DeleteMinMax.cpp DeleteMinMax.h DeleteMinMax-main.cpp)
add_library(DeleteMinMaxLib ../../TextBook/02_LinkList/LinkList.h ../../TextBook/02_LinkList/LinkList.cpp)
target_link_libraries(DeleteMinMax DeleteMinMaxLib)