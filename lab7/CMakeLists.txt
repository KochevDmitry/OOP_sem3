cmake_minimum_required(VERSION 3.10)
project(lab_7)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

add_executable(laba7
    main.cpp
    ./npc/npc.h
    ./npc/slaver.h
    ./npc/knight.h
    ./npc/squirrel.h
    ./pattern/factory.h
    ./pattern/visitor.h
    ./pattern/observer.h
    ./pattern/factory.cpp
    ./pattern/visitor.cpp
    ./pattern/observer.cpp
    ./npc/npc.cpp
    ./npc/slaver.cpp
    ./npc/knight.cpp
    ./npc/squirrel.cpp
    )

enable_testing()
add_executable(tests
    gtests.cpp
    ./npc/npc.h
    ./npc/slaver.h
    ./npc/knight.h
    ./npc/squirrel.h
    ./pattern/factory.h
    ./pattern/visitor.h
    ./pattern/observer.h
    ./pattern/factory.cpp
    ./pattern/visitor.cpp
    ./pattern/observer.cpp
    ./npc/npc.cpp
    ./npc/slaver.cpp
    ./npc/knight.cpp
    ./npc/squirrel.cpp
    )

target_link_libraries(tests ${GTEST_LIBRARIES})
add_test(NAME counter_test COMMAND tests)