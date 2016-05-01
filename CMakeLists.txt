cmake_minimum_required(VERSION 3.5)
project(AStar)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    GridEnvironment.cpp
    GridEnvironment.h main.cpp InefficientAStar.h)

add_executable(AStar ${SOURCE_FILES})