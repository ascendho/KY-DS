cmake_minimum_required(VERSION 3.25)
project(3_4_Postfix)

set(CMAKE_CXX_STANDARD 20)

# Postfix
add_executable(Postfix Postfix.cpp Postfix.h Postfix-main.cpp)
add_library(PostfixLib "../../TextBook/01_SqStack/SqStack.h" "../../TextBook/01_SqStack/SqStack.cpp")
target_link_libraries(Postfix PostfixLib)