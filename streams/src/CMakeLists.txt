cmake_minimum_required(VERSION 3.0)

project(Workshop6 CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 14)

# the following options prevent compiler-optimization issues that are unwanted in an edu process
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

#### the list of targets ####
add_executable(ex1 ex1_avgfunc/main.cpp)            # calculating average of array elements
add_executable(ex2 ex2_read_from_stream/main.cpp)   # read from stream
add_executable(ex3 ex3_files/main.cpp)              # read and write text files
