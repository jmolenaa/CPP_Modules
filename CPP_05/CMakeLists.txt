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

add_executable(moreforms
        ex02/src/main.cpp
        ex02/src/Bureaucrat.cpp
        ex02/src/AForm.cpp
        ex02/src/ShrubberyCreationForm.cpp
        ex02/src/RobotomyRequestForm.cpp
        ex02/src/PresidentialPardonForm.cpp)

target_include_directories(moreforms PUBLIC ex02/incs)

add_executable(intern
        ex03/src/main.cpp
        ex03/src/Bureaucrat.cpp
        ex03/src/AForm.cpp
        ex03/src/ShrubberyCreationForm.cpp
        ex03/src/RobotomyRequestForm.cpp
        ex03/src/PresidentialPardonForm.cpp
        ex03/src/Intern.cpp)

target_include_directories(intern PUBLIC ex03/incs)


