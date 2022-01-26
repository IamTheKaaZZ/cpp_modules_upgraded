cmake_minimum_required(VERSION 3.10)
# cmake -S path_to_source -B path_to_build

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the project name
project(FragTrap)

# add the executable
add_executable(${PROJECT_NAME} FragTrap.cpp ClapTrap.cpp main.cpp)
