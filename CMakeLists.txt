cmake_minimum_required(VERSION 3.24)
project(Project_K)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "./Resources/SFML/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(Project_K main.cpp)

target_link_libraries(Project_K sfml-graphics sfml-audio)