cmake_minimum_required(VERSION 3.25)
project(TextBook)

set(CMAKE_CXX_STANDARD 20)

add_executable(SString SString.cpp SString.h)

# Index_BF
add_executable(Index_BF Index_BF.cpp Index_BF.h Index_BF-main.cpp)
add_library(Index_BFLib "SString.cpp" "SString.h")
target_link_libraries(Index_BF Index_BFLib)