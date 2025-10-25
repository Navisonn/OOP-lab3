cmake_minimum_required(VERSION 3.10)

project(GeometryFigures)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
set(SOURCES
    src/main.cpp
    src/rhombus.cpp
    src/pentagon.cpp
    src/hexagon.cpp
)
add_executable(geometry_app ${SOURCES})
target_compile_options(geometry_app PRIVATE -Wall -Wextra -Wpedantic)
set(TEST_SOURCES
    test/test.cpp
    src/rhombus.cpp
    src/pentagon.cpp
    src/hexagon.cpp
)
add_executable(geometry_tests ${TEST_SOURCES})
target_compile_options(geometry_tests PRIVATE -Wall -Wextra -Wpedantic)
add_custom_target(test
    COMMAND ./geometry_tests
    DEPENDS geometry_tests
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running unit tests"
)
