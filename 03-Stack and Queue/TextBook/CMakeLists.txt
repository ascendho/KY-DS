cmake_minimum_required(VERSION 3.25)
project(03_Stack_and_Queue)

set(CMAKE_CXX_STANDARD 20)

add_executable(SqStack SqStack.cpp SqStack.h)
add_executable(LinkStack LinkStack.cpp LinkStack.h)
add_executable(SqQueue SqQueue.cpp SqQueue.h)
add_executable(LinkQueue LinkQueue.cpp LinkQueue.h)

# Conversion
add_executable(Conversion Conversion.cpp Conversion.h Conversion-main.cpp)
add_library(ConversionLib LinkStack.cpp)
target_link_libraries(Conversion ConversionLib)

# Parenthesis Matching
add_executable(Matching Matching.cpp Matching.h Matching-main.cpp)
add_library(MatchingLib LinkStack.cpp)
target_link_libraries(Matching MatchingLib)

# TraverseList
add_executable(TraverseList TraverseList.cpp TraverseList.h TraverseList-main.cpp)
add_library(TraverseListLib "../../02-Linear List/TextBook/LinkList.cpp")
target_link_libraries(TraverseList TraverseListLib)

# Hanoi
add_executable(Hanoi Hanoi.cpp Hanoi.h Hanoi-main.cpp)

# Fib
add_executable(Fib Fib.cpp Fib.h)

# Fact
add_executable(Fact Fact.cpp Fact.h)