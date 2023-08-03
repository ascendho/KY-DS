cmake_minimum_required(VERSION 3.25)
project(Data_Compression)

set(CMAKE_CXX_STANDARD 20)

add_executable(Select HuffmanTree.h)
add_executable(CreatHuffmanCode HuffmanTree.h)
add_executable(CreateHuffmanTree HuffmanTree.h)
add_executable(HuffmanTree HuffmanTree.cpp HuffmanTree.h)
