cmake_minimum_required(VERSION 3.25)
project(DIY)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DIY
        Label.cpp
        Label.h
        LabelMaker.cpp
        LabelMaker.h
        labelTester.cpp)
