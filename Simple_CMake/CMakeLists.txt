cmake_minimum_required(VERSION 3.00)

project(My_CMake_Study)

add_subdirectory(module1)
add_subdirectory(module2)
add_subdirectory(module3)

add_dependencies(module3 module1 module2)

add_executable(My_CMake_Study main.cpp)

target_link_libraries(My_CMake_Study 
module1
module2
module3
)



