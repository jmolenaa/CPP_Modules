cmake_minimum_required(VERSION 3.27)
project(CPP_07)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -Wall -Werror -Wextra")



add_executable(functions
        ex00/src/main.cpp
        ex00/src/Fixed.cpp)

target_include_directories(functions PUBLIC ex00/incs)

add_executable(iter
        ex01/src/main.cpp
        ex01/src/Fixed.cpp)

target_include_directories(iter PUBLIC ex01/incs)
