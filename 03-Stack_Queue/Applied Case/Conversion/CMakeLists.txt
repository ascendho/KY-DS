cmake_minimum_required(VERSION 3.25)
project(Conversion)

set(CMAKE_CXX_STANDARD 20)

# Conversion
add_executable(Conversion Conversion.cpp Conversion.h Conversion-main.cpp Conversion-main.cpp)
add_library(ConversionLib "../../TextBook/02_LinkStack/LinkStack.h" "../../TextBook/02_LinkStack/LinkStack.cpp")
target_link_libraries(Conversion ConversionLib)
