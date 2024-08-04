cmake_minimum_required(VERSION 3.10)

project(MyboostProject VERSION 1.0)

if(DEFINED ENV{BOOST_HOME})
    set(BOOST_ROOT $ENV{BOOST_HOME}/stage)
endif()

find_package(Boost 1.85 REQUIRED COMPONENTS filesystem system)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find Boost")
endif()

add_executable(myprogram main.cpp)

target_compile_features(myprogram PRIVATE cxx_std_17)

target_include_directories(myprogram PRIVATE ${Boost_INCLUDE_DIRS})

target_link_libraries(myprogram PRIVATE ${Boost_LIBRARIES})