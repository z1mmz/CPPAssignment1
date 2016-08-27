cmake_minimum_required(VERSION 3.6)
project(assignment1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/maze.cpp
    src/maze.h
    src/maze.h.gch
    src/mazegen.cpp
    src/mazegen.h
        src/mazer.cpp
    src/mazer.h
    src/mazer.h.gch
        a
    makefile
    maze.g
    mazer
    mazer.o
    readme)

add_executable(assignment1 ${SOURCE_FILES})