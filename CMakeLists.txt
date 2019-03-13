cmake_minimum_required(VERSION 3.0)

project(performance_cpp_tools CXX)

set(CMAKE_CXX_STANDARD 11)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options(-O3)
else()
    add_compile_options(-O2)
endif()

add_executable(main main.cpp word_count.cpp word_count.h tristan_tokenizing_algorithm.cpp tristan_tokenizing_algorithm.h boost_way_of_tokenizing.cpp boost_way_of_tokenizing.h read_textfile_in_string.cpp read_textfile_in_string.h)