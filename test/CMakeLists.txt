cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 20)
project("BSTTest")

enable_testing()
add_executable(test
        NodeTest.cpp
        BSTTest.cpp)
target_link_libraries(test gtest gmock)
