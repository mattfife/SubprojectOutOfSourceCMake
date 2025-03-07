cmake_minimum_required(VERSION 3.10)

# src directory info (sources, includes, etc)
set (SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/)
set (INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# include directories (including ones needed from other libraries)
set (INCLUDE_DIRS 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../class1/include
) 

# This application's files
# src files
set (SRCS ${SRC_DIR}/main.cpp)
# include files
set (INCLUDES ${INCLUDE_DIR}/main.h)


# Add include directories
include_directories(${INCLUDE_DIRS})

# build executable
add_executable(helloworld ${SRCS} ${INCLUDES} )
set_property(DIRECTORY ${PROJECT_ROOT} PROPERTY VS_STARTUP_PROJECT helloworld)

# Add link libraries to include static libs
target_link_libraries(helloworld PRIVATE class1)
