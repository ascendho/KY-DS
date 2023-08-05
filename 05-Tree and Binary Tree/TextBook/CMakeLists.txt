cmake_minimum_required(VERSION 3.25)
project(TextBook)

set(CMAKE_CXX_STANDARD 20)

add_executable(BiTree BiTree.cpp BiTree.h)
add_executable(BiThrTree BiThrTree.cpp BiThrTree.h)
add_executable(DisjointSet DisjointSet.cpp DisjointSet.h)

