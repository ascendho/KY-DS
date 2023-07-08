cmake_minimum_required(VERSION 3.25)
project(TextBook)

set(CMAKE_CXX_STANDARD 20)

add_executable(SString SString.cpp SString.h)

# Index_BF
add_executable(Index_BF Index_BF.cpp Index_BF.h Index_BF-main.cpp)
add_library(Index_BFLib "SString.cpp" "SString.h")
target_link_libraries(Index_BF Index_BFLib)

# Index_KMP
add_executable(Index_KMP Index_KMP.cpp Index_KMP.h Index_KMP-main.cpp)
add_library(Index_KMPLib "SString.cpp" "SString.h")
target_link_libraries(Index_KMP Index_KMPLib)

# LString
add_executable(LString LString.cpp LString.h)

# GetNext
add_executable(next next.cpp next.h)

# GetNextVal
add_executable(nextval nextval.cpp nextval.h)



