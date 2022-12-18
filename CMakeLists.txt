

cmake_minimum_required(VERSION 3.10)
set(Name psr)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

project(${Name})

set(Headers Rules.h Game.h)
set(Sources main.cpp Game.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(psr main.cpp Game/Game.cpp)