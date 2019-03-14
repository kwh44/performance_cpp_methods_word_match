cmake_minimum_required(VERSION 3.0)

project(performance_cpp_tools CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Release)

find_package(Boost COMPONENTS system REQUIRED)

add_executable(main main.cpp word_count.cpp word_count.h tristan_tokenizing_algorithm.cpp tristan_tokenizing_algorithm.h boost_way_of_tokenizing.cpp boost_way_of_tokenizing.h read_textfile_in_string.cpp read_textfile_in_string.h)

target_link_libraries(main Boost::system)