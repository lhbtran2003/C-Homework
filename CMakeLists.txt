cmake_minimum_required(VERSION 3.27)
project(C_Homework C)

set(CMAKE_C_STANDARD 11)

add_library(C_Homework STATIC library.c
        "Session 5/Ex1.c"
        "Session 5/Ex2.c"
        "Session 5/Ex3.c"
        "Session 5/Ex5.c"
        "Session 5/Ex4.c"
)
