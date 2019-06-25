cmake_minimum_required(VERSION 3.0.0)

project(lab1)

add_subdirectory(Function)
add_subdirectory(Point)
add_subdirectory(Utils)

set(INCLUDE_DIR ${CMAKE_HOME_DIRECTORY}/include )
set(SRC_DIR ${CMAKE_HOME_DIRECTORY}/src)

add_executable(lab1 ${SRC_DIR}/main.cpp)

add_library(NR STATIC ${INCLUDE_DIR}/NR.h ${SRC_DIR}/NR.cpp)

target_link_libraries(lab1 Function)
target_link_libraries(lab1 NR)
target_link_libraries(lab1 Point)
target_link_libraries(lab1 Utils)
