cmake_minimum_required(VERSION 3.25)
project(TextBook)

set(CMAKE_CXX_STANDARD 20)

add_executable(SSTable SSTable.cpp SSTable.h)
add_executable(Search_Seq Search_Seq.cpp Search_Seq.h)
add_executable(Search_Bin Search_Bin.cpp Search_Bin.h)
add_executable(BlockingSearch BlockingSearch.cpp BlockingSearch.h)

add_executable(BSTree BSTree.cpp BSTree.h)
