cmake_minimum_required(VERSION 3.16)

# Set the project name
project(LMS LANGUAGES CXX)

# Use modern C++ standard (C++20; change to 17 or 23 if needed)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Automatically find all .cpp files in the project root and subdirectories.
# CONFIGURE_DEPENDS ensures CMake re-evaluates file lists when new files are added.
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

# Exclude build directory in case in-tree or subfolder builds are used
list(FILTER SOURCES EXCLUDE REGEX "/build/")

# Alternatively, you can list source files explicitly:
# set(SOURCES
#     main.cpp
#     funcs.cpp
# )

# Create the executable from source files
add_executable(${PROJECT_NAME} ${SOURCES})

# Include header search paths (allows #include "funcs.h" from project root or include/ folder)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Enable compiler warnings to catch potential issues early
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()
