@echo off

set BUILD_TYPE=Ninja
set BUILD_SUFFIX=ninja

chcp 65001

set BUILD_FOLDER=build_%BUILD_SUFFIX%

if not exist %BUILD_FOLDER% mkdir %BUILD_FOLDER%

cd %BUILD_FOLDER%

cmake -G %BUILD_TYPE% ..
cmake --build .

copy ..\171024_cpp_compilation\build_run.bat .\171024_cpp_compilation
copy ..\181024_refactoring\build_run.bat .\181024_refactoring
copy ..\241203_refactoring\build_run.bat .\241203_refactoring
copy ..\241210_multiply_code\build_run.bat .\241210_multiply_code

copy ..\run_tests.bat .