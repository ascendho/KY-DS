cmake_minimum_required(VERSION 3.25)
project(Exercise)

set(CMAKE_CXX_STANDARD 20)

# Inverse
add_executable(Inverse Inverse.cpp Inverse.h Inverse-main.cpp)
add_library(InverseLib ../TextBook/LinkList.h ../TextBook/LinkList.cpp)
target_link_libraries(Inverse InverseLib)

# Max
add_executable(Max Max.cpp Max.h Max-main.cpp)
add_library(MaxLib ../TextBook/LinkList.h ../TextBook/LinkList.cpp)
target_link_libraries(Max MaxLib)

# Difference
add_executable(Difference Difference.cpp Difference.h Difference-main.cpp)
add_library(DifferenceLib ../TextBook/LinkList.h ../TextBook/LinkList.cpp)
target_link_libraries(Difference DifferenceLib)

# DeleteMinMax
add_executable(DeleteMinMax DeleteMinMax.cpp DeleteMinMax.h DeleteMinMax-main.cpp)
add_library(DeleteMinMaxLib ../TextBook/LinkList.h ../TextBook/LinkList.cpp)
target_link_libraries(DeleteMinMax DeleteMinMaxLib)
