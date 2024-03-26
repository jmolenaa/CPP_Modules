cmake_minimum_required(VERSION 3.22.1)
project(cpp04)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(polymorph
            ex00/src/main.cpp
        ex00/src/Animal.cpp
        ex00/src/Dog.cpp
        ex00/src/Cat.cpp
        ex00/src/WrongAnimal.cpp
        ex00/src/WrongCat.cpp)

target_include_directories(polymorph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ex00/incs)


