cmake_minimum_required(VERSION 3.15)
project(ShapesParser VERSION 1.0 LANGUAGES CXX DESCRIPTION "This is a shared library for parsing shapes from structured data.")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Recursive collect all .hpp files in Headers directory
file(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/Headers/*.hpp)

# Recursive collect all .cpp files in Sources directory
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR}/Sources/*.cpp)

# Create a shared library
add_library(
    ${PROJECT_NAME} SHARED
    ${HEADER_FILES}
    ${SOURCE_FILES}
)

# Set target version
set_target_properties(${PROJEC_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Set SO version
set_target_properties(${PROJEC_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})

# Add Headers directory to compiler include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/Headers)

# Declare API for shared library
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER ${CMAKE_SOURCE_DIR}/API/ShapeParser.hpp)