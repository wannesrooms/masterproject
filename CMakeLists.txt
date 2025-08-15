cmake_minimum_required(VERSION 3.10)
project(GhanaJump)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES
    "Ghana_Jump/*.cpp"
)

add_executable(GhanaJump ${SOURCES})

find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

target_link_libraries(GhanaJump sfml-system sfml-window sfml-graphics sfml-audio)