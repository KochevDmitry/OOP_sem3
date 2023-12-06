cmake_minimum_required(VERSION 3.10)
project(lab4)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SCR figure_array.h figure.h rhombus.h pentagon.h hexagon.h)

add_executable(lab4 main.cpp figure_array.h figure.h rhombus.h pentagon.h hexagon.h)

enable_testing()
add_executable(tests gtests.cpp figure_array.h figure.h rhombus.h pentagon.h hexagon.h)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)