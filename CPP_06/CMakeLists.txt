cmake_minimum_required(VERSION 3.27)
project(CPP_06)

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wall -Werror -Wextra -fsanitize=address)
add_link_options(-Wall -Werror -Wextra -fsanitize=address)

add_executable(scalar
        ex00/src/main.cpp
        ex00/src/ScalarConverter.cpp)

target_include_directories(scalar PUBLIC ex00/incs)

add_executable(serializer
        ex01/src/main.cpp
        ex01/src/Serializer.cpp
        ex01/src/Data.cpp)

target_include_directories(serializer PUBLIC ex01/incs)

