cmake_minimum_required(VERSION 3.10)

project(SimpleTestExample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include(CTest)
enable_testing()

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

FetchContent_MakeAvailable(googletest)

set(SOURCE_FILES 
    main.cpp
    math_functions.cpp
)

# exe
add_executable(SimpleTestExample ${SOURCE_FILES})

# Test setup
add_executable(test_math_functions test_math_functions.cpp math_functions.cpp)

target_link_libraries(test_math_functions gtest_main)

add_test(NAME MathFunctionsTest COMMAND test_math_functions)

