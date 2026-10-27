cmake_minimum_required(VERSION 4.2)
project(TP_MPI C)

set(CMAKE_C_STANDARD 11)

add_executable(TP_MPI main.c
        semester1/tp1_part1.c
        semester1/tp1_part2.c
        semester1/tp2.c
        semester1/tp3_part1.c
        semester1/tp3_part2.c
        semester1/tp3_part3.c
        semester2/tp_linked_lists.c
        semester2/tp_doubly_linked_lists.c
        semester2/tp_queues.cpp
        semester2/tp_stacks.c
)
