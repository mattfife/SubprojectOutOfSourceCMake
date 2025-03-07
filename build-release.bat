@echo off
call build-clean.bat
mkdir build
cd build
cmake ..
msbuild HelloWorld.sln /p:Configuration=Release
cd ..
