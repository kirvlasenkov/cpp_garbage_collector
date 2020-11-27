cmake_minimum_required(VERSION 3.17)
project(week_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(week_3
        sum_reverse_sort/sum_reverse_sort.h
        sum_reverse_sort/sum_reverse_sort.cpp
        sum_reverse_sort/test_runner.h
        sum_reverse_sort/SRS_tests.cpp
        phone_number/phone_number.h
        phone_number/phone_number.cpp rectangle/rectangle.cpp rectangle/rectangle.h decomposition/query.h decomposition/query.cpp decomposition/responses.h decomposition/responses.cpp decomposition/bus_manager.h decomposition/bus_manager.cpp decomposition/main.cpp)