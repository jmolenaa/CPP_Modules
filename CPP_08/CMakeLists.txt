cmake_minimum_required(VERSION 3.22.1)
project(cpp08)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wshadow -Wno-shadow")

add_executable(easyfind ex00/src/main.cpp)

target_include_directories(easyfind PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/ex00/incs)

add_executable(span ex01/src/main.cpp
                    ex01/src/Span.cpp)

target_include_directories(span PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/ex01/incs)
