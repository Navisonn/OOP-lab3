cmake_minimum_required(VERSION 3.10)
project(Figures)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(figures
    src/main.cpp
    src/Figure.cpp
    src/Rhombus.cpp
    src/Pentagon.cpp
    src/Hexagon.cpp
    src/Array.cpp
)
