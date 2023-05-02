cmake_minimum_required(VERSION 3.23)
project(OrderMenuProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(OrderMenuProject main.cpp "Calculate Total.cpp" "Calculate Total.h")

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(OrderMenuProject sfml-system sfml-window sfml-graphics sfml-audio sfml-network)