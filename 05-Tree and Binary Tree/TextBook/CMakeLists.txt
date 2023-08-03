cmake_minimum_required(VERSION 3.25)
project(TextBook)

set(CMAKE_CXX_STANDARD 20)

add_executable(InOrderTraverse InOrderTraverse.cpp BiNode.h)
add_executable(InOrderTraverseUsingStack InOrderTraverseUsingStack.cpp BiNode.h)
add_executable(CreateBiTree CreateBiTree.cpp BiNode.h)
add_executable(Copy Copy.cpp BiNode.h)
add_executable(Depth Depth.cpp BiNode.h)
add_executable(NodeCount NodeCount.cpp BiNode.h)
add_executable(InThreading InThreading.cpp BiThrNode.h)
add_executable(InOrderThreading InOrderThreading.cpp BiThrNode.h)
add_executable(InOrderTraverse_Thr InOrderTraverse_Thr.cpp BiThrNode.h)
