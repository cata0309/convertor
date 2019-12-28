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

if (SFML_FOUND)
    message(STATUS SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR})
    message(STATUS SFML_LIBRARIES: ${SFML_LIBRARY_DIR})
    message(STATUS SFML_VERSION: ${SFML_VERSION})
endif ()
add_custom_target(
        play
        COMMAND make && convertor)
add_executable(convertor src/main.cpp src/Defines.hpp src/UserInterface.cpp src/UserInterface.hpp src/Logics.cpp src/Logics.hpp src/InputForm.cpp src/InputForm.hpp)
target_link_libraries(convertor sfml-graphics sfml-window sfml-system sfml-audio)

