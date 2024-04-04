cmake_minimum_required(VERSION 3.27)
project(CPP_05)

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wall -Werror -Wextra -fsanitize=address)
add_link_options(-Wall -Werror -Wextra -fsanitize=address)

add_executable(bureacrat
        ex00/src/main.cpp
        ex00/src/Bureaucrat.cpp)

target_include_directories(bureacrat PUBLIC ex00/incs)

add_executable(form
        ex01/src/main.cpp
        ex01/src/Bureaucrat.cpp
        ex01/src/Form.cpp)

target_include_directories(form PUBLIC ex01/incs)
