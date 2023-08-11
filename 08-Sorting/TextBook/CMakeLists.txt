cmake_minimum_required(VERSION 3.25)
project(TextBook)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataList DataList.cpp DataList.h)
add_executable(InsertSort InsertSort.cpp InsertSort.h)
add_executable(BInsertSort BInsertSort.cpp BInsertSort.h)
add_executable(ShellSort ShellSort.cpp ShellSort.h)
