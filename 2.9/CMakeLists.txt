cmake_minimum_required(VERSION 3.21.4)

set(PROJECT_NAME 28)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable("${PROJECT_NAME}" main.cpp inc/bmp.cpp inc/bmp.hpp)
file(COPY "in.bmp" DESTINATION "/")