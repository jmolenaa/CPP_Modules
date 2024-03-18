cmake_minimum_required(VERSION 3.22.1)
project(cpp03)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(open ex00/src/ClapTrap.cpp
        ex00/src/main.cpp)

target_include_directories(open PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/ex00/incs)

#add_executable(usefulfixed ex01/src/main.cpp
#        ex01/src/Fixed.cpp)
#
#target_include_directories(usefulfixed PUBLIC
#        ${CMAKE_CURRENT_SOURCE_DIR}/ex01/incs)
#
#add_executable(workwork ex02/src/main.cpp
#        ex02/src/Fixed.cpp)
#
#target_include_directories(workwork PUBLIC
#        ${CMAKE_CURRENT_SOURCE_DIR}/ex02/incs)
#
#add_executable(BSP
#        ex03/src/Fixed.cpp
#        ex03/src/main.cpp
#        ex03/src/Point.cpp
#        ex03/src/bsp.cpp)
#
#target_include_directories(BSP PUBLIC
#        ${CMAKE_CURRENT_SOURCE_DIR}/ex03/incs)
