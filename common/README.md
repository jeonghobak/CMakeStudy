## Common
### Visual Studio 프로젝트 구성을 위한 배치 파일 작성
~~~bat
@echo off

rem 환경 변수 설정 여부 확인
if "%BOOST_HOME%"=="" (
    echo BOOST_HOME env_val is not set
    pause
    exit /b 1
)

cmake -S . -B build -G "Visual Studio 17 2022"

pause
~~~

#### 명령어 상세분석
`cmake -S . -B build -G "Visual Studio 17 2022"`

`-S .` : 소스 디렉토리 지정(.로 했으니 현재 디렉토리 위치를 소스 디렉토리로 지정)   
`-B build` : 빌드 디렉토리 지정, build 라는 이름의 디렉토리를 빌드 디렉토리로 지정   
`-G "Visual Studio 17 2022"` : 빌드 시스템 지정.
