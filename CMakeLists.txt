cmake_minimum_required(VERSION 3.5)

project(newStates LANGUAGES CXX)

file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(newStates  ${SRCS} ${HDRS})
