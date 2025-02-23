cmake_minimum_required(VERSION 3.10)

project(ImageToASCII)

set(CMAKE_CXX_STANDARD 17)

add_executable(imageToASCII src/main.cpp)

target_include_directories(imageToASCII PRIVATE include)
