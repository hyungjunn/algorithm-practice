cmake_minimum_required(VERSION 4.1)
project(algorithm_practice)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(algorithm_practice main.cpp)
add_executable(solve baekjoon/1697.cpp)
