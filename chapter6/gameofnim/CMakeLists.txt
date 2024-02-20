cmake_minimum_required(VERSION 3.26)
project(gameofnim C)

set(CMAKE_C_STANDARD 11)

add_executable(gameofnim main.c
        nim.c)
