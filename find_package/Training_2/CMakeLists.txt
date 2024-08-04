cmake_minimum_required(VERSION 3.10)

set(project_name MyBoostProject2)

project(${project_name} VERSION 1.0)

set(CMAKE_FIND_USE_SYSTEM_ENVIRONMENT_PATH TRUE)

find_package(Boost 1.85 REQUIRED COMPONENTS filesystem)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find Boost in system path")
endif()

add_executable(${project_name} main.cpp)

target_compile_features(${project_name} PRIVATE cxx_std_17)

target_include_directories(${project_name} PRIVATE ${Boost_INCLUDE_DIRS})

target_link_libraries(${project_name} PRIVATE ${Boost_LIBRARIES})