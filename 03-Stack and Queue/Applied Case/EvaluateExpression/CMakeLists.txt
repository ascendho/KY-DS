cmake_minimum_required(VERSION 3.25)
project(EvaluateExpression)

set(CMAKE_CXX_STANDARD 20)

# EvaluateExpression
add_executable(EvaluateExpression EvaluateExpression.cpp EvaluateExpression.h EvaluateExpression-main.cpp)
add_library(EvaluateExpressionLib "../../TextBook/LinkStack.cpp")
target_link_libraries(EvaluateExpression EvaluateExpressionLib)