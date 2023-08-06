cmake_minimum_required(VERSION 3.25)
project(TextBook)

set(CMAKE_CXX_STANDARD 20)

add_executable(Graph Graph.cpp Graph.h)
add_executable(AdjacencyMatrix AdjacencyMatrix.cpp AdjacencyMatrix.h)
add_executable(AdjacencyList AdjacencyList.cpp AdjacencyList.h)
add_executable(DFS DFS.cpp DFS.h)
add_executable(BFS BFS.cpp BFS.h)