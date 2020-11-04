cmake_minimum_required(VERSION 3.17)
project(white_references)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(white_references
        matrix_sum.cpp)
