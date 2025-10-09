cmake_minimum_required(VERSION 3.10)
project(Tetris)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Automatically find all source files in the src directory
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Set the include directories
include_directories(
    src
    lib/raylib/src
)

# Add raylib as a subdirectory
add_subdirectory(lib/raylib)

# Add the executable
add_executable(Tetris ${SOURCES})

# Link raylib to the executable
target_link_libraries(Tetris PRIVATE raylib)

# Platform-specific configurations
if(WIN32)
    # For Windows, link against additional libraries required by raylib
    target_link_libraries(Tetris PRIVATE opengl32 gdi32 winmm)
elseif(UNIX AND NOT APPLE)
    # For Linux, link against additional libraries
    target_link_libraries(Tetris PRIVATE GL m pthread dl rt X11)
elseif(APPLE)
    # For macOS, link against required frameworks
    target_link_libraries(Tetris PRIVATE "-framework OpenGL" "-framework OpenAL" "-framework Cocoa" "-framework IOKit")
endif()