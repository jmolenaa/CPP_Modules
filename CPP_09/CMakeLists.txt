cmake_minimum_required(VERSION 3.22.1)
project(cpp09)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wshadow -Wno-shadow")

add_executable(btc ex00/src/main.cpp
        ex00/src/BitcoinExchange.cpp
        ex00/src/Date.cpp)

target_include_directories(btc PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/ex00/incs)

add_executable(rpn ex01/src/main.cpp
                ex01/src/RPN.cpp)

target_include_directories(rpn PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/ex01/incs)

add_executable(merge ex02/src/main.cpp)

target_include_directories(merge PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/ex02/incs)

