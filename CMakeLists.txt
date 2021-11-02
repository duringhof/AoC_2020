cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

project(AoC_2020)

include_directories(include)

add_executable(day01 src/day01.cpp)
add_executable(day02 src/day02.cpp)
add_executable(day03 src/day03.cpp)