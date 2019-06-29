cmake_minimum_required(VERSION 3.0.0)

project(Matrix)

set(INCLUDE_DIR include)
set(SOURCE_DIR src)

add_library(Matrix STATIC ${INCLUDE_DIR}/Matrix.h ${SOURCE_DIR}/source.cpp)