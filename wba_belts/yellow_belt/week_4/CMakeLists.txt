cmake_minimum_required(VERSION 3.17)
project(week_4)

set(CMAKE_CXX_STANDARD 17)

add_executable(week_4
        print_vector_part.cpp
        find_greater_elements.cpp
        split_into_words.cpp
        remove_duplicates.cpp
        print_permutations.cpp
        print_stats.cpp
        merge_sort_2_splits.cpp merge_sort_3_splits.cpp)