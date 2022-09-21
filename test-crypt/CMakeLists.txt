cmake_minimum_required(VERSION 3.5)

project(test-crypt LANGUAGES CXX)

set(PROJECT_NAME crypt)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE
    main.cpp
    ecc.cpp)

set(INCLUDE
    ecc.h
    exception.h)

add_executable(${PROJECT_NAME} ${SOURCE} ${INCLUDE})
