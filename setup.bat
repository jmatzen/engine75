@echo off
if not exist "build" mkdir build
pushd build
conan install .. -s build_type=Debug -s compiler.version=16 -s compiler.cppstd=17 --build missing --profile ..\profiles\debug
cmake .. -G"Visual Studio 16 2019" -A x64
popd
