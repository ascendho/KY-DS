cmake_minimum_required(VERSION 3.25)
project(Matching)

set(CMAKE_CXX_STANDARD 20)

# Parenthesis Matching
add_executable(Matching Matching.cpp Matching.h Matching-main.cpp)
add_library(MatchingLib "../../TextBook/02_LinkStack/LinkStack.h" "../../TextBook/02_LinkStack/LinkStack.cpp")
target_link_libraries(Matching MatchingLib)