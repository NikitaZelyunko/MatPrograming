cmake_minimum_required(VERSION 3.0.0)

project(Utils)

set(SOURCE_DIR src)
set(INCLUDE_DIR include)

add_library(Utils STATIC ${INCLUDE_DIR}/Utils.h ${SOURCE_DIR}/Utils.cpp)