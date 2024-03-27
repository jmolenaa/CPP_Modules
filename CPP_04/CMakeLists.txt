cmake_minimum_required(VERSION 3.22.1)
project(cpp04)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -fsanitize=address")

add_executable(polymorph
            ex00/src/main.cpp
        ex00/src/Animal.cpp
        ex00/src/Dog.cpp
        ex00/src/Cat.cpp
        ex00/src/WrongAnimal.cpp
        ex00/src/WrongCat.cpp)

target_include_directories(polymorph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ex00/incs)

add_executable(brain
        ex01/src/main.cpp
        ex01/src/Animal.cpp
        ex01/src/Dog.cpp
        ex01/src/Cat.cpp
        ex01/src/WrongAnimal.cpp
        ex01/src/WrongCat.cpp
        ex01/src/Brain.cpp)

target_include_directories(brain PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ex01/incs)

add_executable(abstract
        ex02/src/main.cpp
        ex02/src/AAnimal.cpp
        ex02/src/Dog.cpp
        ex02/src/Cat.cpp
        ex02/src/WrongAnimal.cpp
        ex02/src/WrongCat.cpp
        ex02/src/Brain.cpp)

target_include_directories(abstract PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ex02/incs)
