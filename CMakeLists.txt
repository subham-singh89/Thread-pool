cmake_minimum_required(VERSION 3.8)
project(ThreadPoolExample)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ThreadPoolExample main.cpp Threadpool.cpp)
