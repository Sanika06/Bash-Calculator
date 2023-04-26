cmake_minimum_required(VERSION 3.24)
project(binary_calculator C)

set(CMAKE_C_STANDARD 11)

add_executable(binary_calculator main.c cmake-build-debug linkedlist1.c "main(1).cpp" stack.c evaluate.c includes/evaluate.h)

target_include_directories(binary_calculator PUBLIC includes/)
