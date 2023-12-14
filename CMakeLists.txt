cmake_minimum_required(VERSION 3.27)
project(C_Homework C)

set(CMAKE_C_STANDARD 11)

add_library(C_Homework STATIC library.c
        "Session 5/Ex1.c"
        "Session 5/Ex2.c"
        "Session 5/Ex3.c"
        "Session 5/Ex5.c"
        "Session 5/Ex4.c"
        "Session 7/Ex1.c"
        "Session 7/Ex2.c"
        "Session 7/Ex3.c"
        "Session 6/Homework/Ex1.c"
        "Session 8/Mang2chieu.c"
        "Session 8/saochepMang.c"
        "Session 8/tulam.c"
        "Session 8/Ex1.c"
        "Session 8/Ex2.c"
        "Session 8/Ex3.c"
        "Session 9/Ex1.c"
)
