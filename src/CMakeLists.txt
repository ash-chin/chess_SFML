cmake_minimum_required(VERSION 3.10)

project(myapp)
set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_LINK_FLAGS "-lGL")

find_package(SFML 2.5.1 COMPONENTS graphics)

set(SOURCES main.cpp pieces.cpp gamemanager.cpp pieces.h gamemanager.h)

add_executable(myapp ${SOURCES})

target_link_libraries(myapp sfml-graphics)