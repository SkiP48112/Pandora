@echo off
set BUILD_DIR=../../build
set CONFIG=Debug

if not exist "%BUILD_DIR%" (
    echo Build directory "%BUILD_DIR%" not found. Please run generate_project_files.bat first.
    cmd
)

cd "%BUILD_DIR%"
cmake --build . --config %CONFIG%
cd ..

echo Build completed.
cmd