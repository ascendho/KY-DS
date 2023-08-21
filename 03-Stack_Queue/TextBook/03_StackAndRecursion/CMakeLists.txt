cmake_minimum_required(VERSION 3.25)
project(03_StackAndRecursion)

set(CMAKE_CXX_STANDARD 20)

add_executable(StackAndRecursion StackAndRecursion.cpp StackAndRecursion.h)
add_library(StackAndRecursionLib "../../../02-Linear List/TextBook/02_LinkList/LinkList.h" "../../../02-Linear List/TextBook/02_LinkList/LinkList.cpp")
target_link_libraries(StackAndRecursion StackAndRecursionLib)