cmake_minimum_required(VERSION 3.25)
project(lab)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab
        main.cpp
        CarInventory.cpp
        CarInventory.h
        )
