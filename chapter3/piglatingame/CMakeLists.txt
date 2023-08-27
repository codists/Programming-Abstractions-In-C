cmake_minimum_required(VERSION 3.26)
project(piglatingame C)

set(CMAKE_C_STANDARD 11)

add_executable(piglatingame main.c
        simpio.c
        genlib.c
        strlib.c
        exception.c)
