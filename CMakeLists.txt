cmake_minimum_required(VERSION 3.15)
project(Application)

# Add Address Sanitizer support
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp)

if(WIN32)
    set(LIB_EXTENSION "dll")
elseif(APPLE)
    set(LIB_EXTENSION "dylib")
endif()

# Import the ShapesParser shared library
add_library(ShapesParser SHARED IMPORTED)

# Set the ShapesParser library path
set_target_properties(ShapesParser PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_LIST_DIR}/ShapesParser/libShapesParser.${LIB_EXTENSION})

# Add the Headers directories to the compiler include path
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/ShapesParser/Headers)

# Add the API directories to the compiler include path
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/ShapesParser/API)

# Link the ShapesParser library to the Application
target_link_libraries(${PROJECT_NAME} PRIVATE ShapesParser)