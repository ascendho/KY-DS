cmake_minimum_required(VERSION 3.25)
project(Applied_Case)

set(CMAKE_CXX_STANDARD 20)

add_executable(Virus_detection Virus_detection.cpp Virus_detection.h Virus_detection-main.cpp)
add_library(Virus_detectionLib "../TextBook/Index_BF.h" "../TextBook/Index_BF.cpp")
target_link_libraries(Virus_detection Virus_detection-mainLib)
