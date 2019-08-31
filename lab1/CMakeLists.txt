cmake_minimum_required(VERSION 3.0.0)

project(lab1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

add_subdirectory(Utils)

add_subdirectory(Function)
add_subdirectory(Point)
add_subdirectory(Matrix)

add_subdirectory(Abstract-solver)
add_subdirectory(Matrix-abstract-solver)

add_subdirectory(Matrix-determinant-solver)
add_subdirectory(Matrix-inverse-solver)
add_subdirectory(Matrix-sylvester-test)

add_subdirectory(Simple-polynomial)
add_subdirectory(Simple-polynomial-real-roots-boundaries-solver)

add_subdirectory(NR)

set(INCLUDE_DIR ${CMAKE_HOME_DIRECTORY}/include )
set(SRC_DIR ${CMAKE_HOME_DIRECTORY}/src)

add_executable(lab1 ${SRC_DIR}/main.cpp)

target_link_libraries(lab1 Utils)

target_link_libraries(lab1 Point)
target_link_libraries(lab1 Matrix)
target_link_libraries(lab1 Function)

target_link_libraries(lab1 AbstractSolver)
target_link_libraries(lab1 MatrixAbstractSolver)
target_link_libraries(lab1 MatrixInverseSolver)

target_link_libraries(lab1 MatrixDeterminantSolver)

target_link_libraries(lab1 MatrixSylvesterTest)

target_link_libraries(lab1 SimplePolynomial)
target_link_libraries(lab1 SimplePolynomialRealRootsBoundariesSolver)

target_link_libraries(lab1 NR)