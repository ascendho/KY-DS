cmake_minimum_required(VERSION 3.25)
project(Exercise)

set(CMAKE_CXX_STANDARD 20)

# IsPalindrome
add_executable(IsPalindrome IsPalindrome.cpp IsPalindrome.h IsPalindrome-main.cpp)
add_library(IsPalindromeLib "../TextBook/SqStack.h" "../TextBook/SqStack.cpp")
target_link_libraries(IsPalindrome IsPalindromeLib)

# Postfix
add_executable(Postfix Postfix.cpp Postfix.h Postfix-main.cpp)
add_library(PostfixLib "../TextBook/SqStack.h" "../TextBook/SqStack.cpp")
target_link_libraries(Postfix PostfixLib)

# DblStack
add_executable(DblStack DblStack.cpp DblStack.h DblStack-main.cpp)

# SqQueueWithTag
add_executable(SqQueueWithTag SqQueueWithTag.cpp SqQueueWithTag.h SqQueueWithTag-main.cpp)

