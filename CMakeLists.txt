cmake_minimum_required(VERSION 3.15)
project(ShapesParser)

# Add Address Sanitizer support
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the Header's folder to the compiler's include directories
include_directories(Headers)

# Add the Helper's folder to the compiler's include directories
include_directories(Helper)

# Collect all the source files and header files into variables
file(GLOB_RECURSE SOURCES "Sources/*.cpp")
file(GLOB_RECURSE HEADERS "Headers/*.hpp")

# Create an executable target from the source file, header files, and helper files
add_executable(${PROJECT_NAME} main.cpp ${SOURCES} ${HEADERS})

# Add the Headers and Helper directory to the target's include directories property
target_include_directories(${PROJECT_NAME} PRIVATE Headers)