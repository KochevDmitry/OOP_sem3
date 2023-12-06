cmake_minimum_required(VERSION 3.10)
project(lab3)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SCR figure_array.cpp figure.cpp rhombus.cpp pentagon.cpp hexagon.cpp)

add_executable(lab3 main.cpp figure_array.cpp figure.cpp rhombus.cpp pentagon.cpp hexagon.cpp)

enable_testing()
add_executable(tests gtests.cpp figure_array.cpp figure.cpp rhombus.cpp pentagon.cpp hexagon.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)