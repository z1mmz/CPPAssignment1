cmake_minimum_required (VERSION 2.6)
project(cppassignment)
include_directories(src)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++14 -Wall -pedantic")
file(GLOB src
        "src/*.h"
        "src/*.cpp"
        )

add_executable(mazer ${src})