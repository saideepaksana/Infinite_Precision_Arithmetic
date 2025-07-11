cmake_minimum_required(VERSION 3.10)
project(InfinitePrecision)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

add_library(infprec
    src/integer.cpp
    src/floating.cpp
)

add_executable(infprec-cli src/main.cpp)
target_link_libraries(infprec-cli infprec)