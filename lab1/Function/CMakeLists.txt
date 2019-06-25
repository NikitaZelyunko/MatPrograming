cmake_minimum_required(VERSION 3.0.0)

project(Function)

set (INCLUDE_DIR include)
set (SOURCE_DIR src)


add_library(Function STATIC ${SOURCE_DIR}/source.cpp ${INCLUDE_DIR}/Function.h ${INCLUDE_DIR}/OneDimensionalFunction.h)