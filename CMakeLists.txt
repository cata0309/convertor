cmake_minimum_required(VERSION 3.15)
project(convertor)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
set(SFML_INCLUDE_DIR include)
set(SFML_LIBRARY_DIR lib)
set(SFML_DIR lib/cmake/SFML)
link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS SFML_INCLUDE_DIR: )
    message(STATUS SFML_LIBRARIES: )
    message(STATUS SFML_VERSION: )
endif()
add_custom_target(
play
COMMAND make && ./convertor)
add_executable(convertor main.cpp Defines.hpp InputForm.cpp InputForm.hpp Logics.cpp Logics.hpp UserInterface.cpp UserInterface.hpp)
target_link_libraries (convertor sfml-graphics sfml-window sfml-system sfml-audio)

