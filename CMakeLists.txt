cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")


project(HelloWorld)

include_directories(include)

add_executable(HelloWorld src/main.cpp)
