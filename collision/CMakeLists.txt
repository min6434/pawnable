cmake_minimum_required (VERSION 3.5)

set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++11")

project (collision)

set (SRCS "main.cpp")

add_executable (collision ${SRCS})
