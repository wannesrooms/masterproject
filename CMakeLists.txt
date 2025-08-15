cmake_minimum_required(VERSION 3.10)
project(GhanaJump)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "Ghana_Jump/*.cpp")
add_executable(GhanaJump ${SOURCES})

find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

# (optioneel) zorg dat headers in Ghana_Jump gevonden worden met #include "X.h"
target_include_directories(GhanaJump PRIVATE ${CMAKE_SOURCE_DIR}/Ghana_Jump)

target_link_libraries(GhanaJump PRIVATE sfml-system sfml-window sfml-graphics sfml-audio)