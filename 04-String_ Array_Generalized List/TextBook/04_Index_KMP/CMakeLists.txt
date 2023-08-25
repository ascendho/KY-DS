cmake_minimum_required(VERSION 3.25)
project(04_Index_KMP)

set(CMAKE_CXX_STANDARD 20)

add_executable(Index_KMP Index_KMP.cpp Index_KMP.h Index_KMP-main.cpp)
add_library(Index_KMPLib "../01_SString/SString.cpp" "../01_SString/SString.h")
target_link_libraries(Index_KMP Index_KMPLib)