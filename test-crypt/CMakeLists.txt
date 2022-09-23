cmake_minimum_required(VERSION 3.5)

project(test-crypt LANGUAGES CXX)

set(PROJECT_NAME crypt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE
    src/main.cpp
    src/ecc.cpp)

set(INCLUDE
    include/ecc.h
    include/exception.h)

add_executable(${PROJECT_NAME} ${SOURCE} ${INCLUDE})
