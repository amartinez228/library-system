cmake_minimum_required(VERSION 4.2.3)
project(tests C)


set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_executable(tests library.c)