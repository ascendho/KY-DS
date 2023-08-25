cmake_minimum_required(VERSION 3.25)
project(02_Index_BF)

set(CMAKE_CXX_STANDARD 20)

add_executable(Index_BF Index_BF.cpp Index_BF.h Index_BF-main.cpp)
add_library(Index_BFLib "../01_SString/SString.h" "../01_SString/SString.cpp")
target_link_libraries(Index_BF Index_BFLib)