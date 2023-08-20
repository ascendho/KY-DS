cmake_minimum_required(VERSION 3.25)
project(03_Stack_and_Queue)

set(CMAKE_CXX_STANDARD 20)

add_executable(SqStack SqStack.cpp SqStack.h)
add_executable(LinkStack LinkStack.cpp LinkStack.h)
add_executable(SqQueue SqQueue.cpp SqQueue.h)
add_executable(LinkQueue LinkQueue.cpp LinkQueue.h)

add_executable(StackAndRecursion StackAndRecursion.cpp StackAndRecursion.h)
add_library(StackAndRecursionLib "../../02-Linear List/TextBook/LinkList.cpp")
target_link_libraries(StackAndRecursion StackAndRecursionLib)
