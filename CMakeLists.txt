cmake_minimum_required(VERSION 3.8)
project(MatrixCalc)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c MatrixOp.c)
add_executable(MatrixCalc ${SOURCE_FILES})