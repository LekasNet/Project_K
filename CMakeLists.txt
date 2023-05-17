cmake_minimum_required(VERSION 3.24)
project(Project_K)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 17)

add_executable(Project_K main.cpp field.cpp)

target_link_libraries(Project_K ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -mwindows)