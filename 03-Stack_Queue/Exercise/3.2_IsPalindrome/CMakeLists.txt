cmake_minimum_required(VERSION 3.25)
project(3_2_IsPalindrome)

set(CMAKE_CXX_STANDARD 20)

# IsPalindrome
add_executable(IsPalindrome IsPalindrome.cpp IsPalindrome.h IsPalindrome-main.cpp)
add_library(IsPalindromeLib "../../TextBook/01_SqStack/SqStack.h" "../../TextBook/01_SqStack/SqStack.cpp")
target_link_libraries(IsPalindrome IsPalindromeLib)