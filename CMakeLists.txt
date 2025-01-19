cmake_minimum_required(VERSION 3.30)
project(Pong)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib CONFIG REQUIRED)

add_executable(Pong main.cpp)

target_link_libraries(Pong PRIVATE raylib)
