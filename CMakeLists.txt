# CMakeList.txt : Top-level CMake project file

cmake_minimum_required (VERSION 3.10)
project(helloworld VERSION 1.0)

# Removes the ZERO_CHECK project from visual studio
set(CMAKE_SUPPRESS_REGENERATION true)

# Set up the output file locations
set (PROJECT_ROOT ${CMAKE_SOURCE_DIR}/build)
set (LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/libs)
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# Include sub-projects under the src/ directory
add_subdirectory ("src")