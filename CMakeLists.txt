### CMake for BST ###
cmake_minimum_required(VERSION 3.15...3.30)

### Compiler settings ###
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++) 
set(CMAKE_CXX_STANDARD 17)

# Set a default C++ compile flag
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DEX2" CACHE STRING "Set C++ Compiler Flags" FORCE)

### Project statament ###
project(
  BST
  VERSION 1.0
  # LANGUAGE CXX
  # DESCRIPTION "BST in C++"
)

### Source path ###
set(SOURCES
  src/main.cpp
  src/BST.cpp
)

### Executable statament ###
add_executable(${PROJECT_NAME} ${SOURCES})

### Include path ###
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

### Compile commands generation ###
set(CMAKE_EXPORT_COMPILE_COMMANDS)
