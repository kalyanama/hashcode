cmake_minimum_required(VERSION 3.13)
project(hashcode C)

set(CMAKE_C_STANDARD 99)

add_executable(hashcode main.c parsing.h photo.h graph_builder.h graph_builder.c)