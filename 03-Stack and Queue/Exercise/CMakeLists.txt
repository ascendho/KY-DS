cmake_minimum_required(VERSION 3.25)
project(Exercise)

set(CMAKE_CXX_STANDARD 20)

add_executable(Exercise main.cpp)

# IsPalindrome
add_executable(IsPalindrome IsPalindrome.cpp IsPalindrome.h IsPalindrome-main.cpp)
add_library(IsPalindromeLib "../TextBook/SqStack.h" "../TextBook/SqStack.cpp")
target_link_libraries(IsPalindrome IsPalindromeLib)
