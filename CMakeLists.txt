cmake_minimum_required(VERSION 3.6)
project(tests_on_ease_of_numbers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp methods.cpp methods.h)
add_executable(tests_on_ease_of_numbers ${SOURCE_FILES})