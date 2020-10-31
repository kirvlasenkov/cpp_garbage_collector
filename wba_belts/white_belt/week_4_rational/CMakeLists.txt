cmake_minimum_required(VERSION 3.17)
project(week_4_rational)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        week_4_rational
        rational_interface.cpp
        rational_eq_add_sub.cpp
        rational_mult_div.cpp
        rational_io.cpp
        rational_map.cpp
        rational_throw.cpp
        rational_calculator.cpp)