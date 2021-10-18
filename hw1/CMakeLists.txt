cmake_minimum_required(VERSION 3.20)
project(hw1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-fexec-charset=CP949")

add_executable(hw1 main.cpp KMP.h Aho_corasick.h checker.cpp)
