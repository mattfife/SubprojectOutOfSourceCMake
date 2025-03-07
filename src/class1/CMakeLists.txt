cmake_minimum_required(VERSION 3.10)

# src directory info (sources, includes, etc)
set (SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/)
set (INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# include directories (including ones needed from other libraries)
set (INCLUDE_DIRS 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
) 

# src files
set (SOURCES 
	${SRC_DIR}/class1.cpp
)

# local include files
set (INCLUDES 
	${INCLUDE_DIR}/class1.h
)

# Add include directories
include_directories(${INCLUDE_DIRS})

# build library
add_library(class1 STATIC ${SOURCES} ${INCLUDES})
