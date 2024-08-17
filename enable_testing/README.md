## CTest, enable_testing()

리눅스 환경에서 vscode 로 코딩 시 visual studio 의 test explorer 기능이 필요했고, 알아보니 CMake 에서도 비슷한 기능을 지원하여 학습하였다.

CTest는 CMake 프로젝트의 테스트 프레임워크로, CTest를 사용하면 CMake 프로젝트에서 단위테스트, 통합 테스트 및 기능 테스트를 쉽게 작성하고 실행할 수 있다.

본 학습에서는 CTest 를 이용해 gtest 를 실행시키는 예제를 구현한다.

### 프로젝트 구성
```
/CTestGTestExample
│
├── CMakeLists.txt
├── main.cpp
├── math_functions.cpp
├── math_functions.h
└── test_math_functions.cpp
```

### CMake 작성
```cmake
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
```

### 주요 부분 설명
```cmake
include(CTest)
enable_testing()
```
CTest 를 사용하기 위해선 CTest 모듈을 포함시켜야 한다.

`enable_testing()` 은 테스트가 실행 될 수 있게 준비를 해 주는 명령어인데, 간단하게 `add_test()` 명령어가 활성화 될 수 있게 해주는 명령어로 이해하자.

> '[cmake doc](https://cmake.org/cmake/help/latest/command/enable_testing.html) 을 보면 `include(CTest)` 가 호출 될 때 `enable_testing()` 가 같이 호출 된다고 명시되어 있다, 일단 학습을 위해서 명시적으로 호출하긴 했는데 자동으로 호출 된다는 점도 기억해야겠다.'

```cmake
# Test setup
add_executable(test_math_functions test_math_functions.cpp math_functions.cpp)

target_link_libraries(test_math_functions gtest_main)

add_test(NAME MathFunctionsTest COMMAND test_math_functions)
```
테스트를 위한 실행 파일(gtest를 이용해 작성한 unittest)을 구성하고 add_test 명령어를 사용하여 테스트를 등록하였다.

> 여기서 `COMMAND`는 테스트를 실행할 때 사용할 명령(실행 파일이나 스크립트)을 지정하는 역할을한다. 테스트 실행 파일 명칭은 `test_math_functions` 로 했으니 해당 명칭을 명령어 인자로 주면 되겠다.