cmake_minimum_required(VERSION 3.27)
project(ProjectC C)

set(CMAKE_C_STANDARD 11)

add_executable(ProjectC
        main.c
        column.h
        column.c
        cdataframe.h
        cdataframe.c)
