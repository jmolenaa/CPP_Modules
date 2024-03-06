cmake_minimum_required(VERSION 3.22.1)
project(cpp02)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(fixed ex00/src/main.cpp
        ex00/src/Fixed.cpp)

target_include_directories(fixed PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/ex00/incs)

add_executable(usefulfixed ex01/src/main.cpp
        ex01/src/Fixed.cpp)

target_include_directories(usefulfixed PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/ex01/incs)

add_executable(workwork ex02/src/main.cpp
        ex02/src/Fixed.cpp)

target_include_directories(workwork PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/ex02/incs)

#
#add_executable(ex03
#        ex03/Fixed.cpp
#        ex03/main.cpp
#        ex03/Point.cpp
#        ex03/Point.h
#        ex03/bsp.cpp)