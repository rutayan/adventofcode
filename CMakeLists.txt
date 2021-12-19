cmake_minimum_required(VERSION 3.17)

set(PROJECT_NAME aoc)
project(${PROJECT_NAME})

find_program(CLANG_FORMAT clang-format)
if(NOT CLANG_FORMAT AND ENABLE_CLANG_FORMAT)
    message(SEND_ERROR "clang-format not found!")
endif()

add_subdirectory(src)
