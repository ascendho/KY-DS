cmake_minimum_required(VERSION 3.25)
project(02_Linear_List)

set(CMAKE_CXX_STANDARD 20)

add_executable(SqList SqList.cpp SqList.h)
add_executable(LinkList LinkList.cpp LinkList.h)
add_executable(DuLinkList DuLinkList.cpp DuLinkList.h)
add_executable(CLinkList CLinkList.cpp CLinkList.h)
add_executable(Union Union.cpp Union.h)
add_executable(MergeList MergeList.cpp MergeList.h)
add_executable(Polynomial Polynomial.cpp Polynomial.h)