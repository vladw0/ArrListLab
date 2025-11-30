cmake_minimum_required(VERSION 3.14)
project(ArrListProject LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_library(arrlib INTERFACE)
target_include_directories(arrlib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(arrlist_app src/main.cpp)
target_link_libraries(arrlist_app PRIVATE arrlib)

add_subdirectory(gtest)

add_executable(arrlist_test test/test_arrlist.cpp)
target_link_libraries(arrlist_test PRIVATE arrlib gtest_main)
include(GoogleTest)
gtest_discover_tests(arrlist_test)
