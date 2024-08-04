@echo off

if "%BOOST_HOME%"=="" (
    echo BOOST_HOME env_val is not set
    pause
    exit /b 1
)

cmake -S . -B build -G "Visual Studio 17 2022"

pause