#include "../include/MatrixInverseSolver.h"

void TestMatrixInverseSolver() {
    Matrix<double> a(1,1,2);
    MatrixInverseSolver<double> solver1(a, 0.00001);
    Matrix<double> result = solver1.solve();
    result.print("Result:");
    
    Matrix<double> b(3,3,0.0);
    b[0][0] = 1; b[0][1] = 2;  b[0][2] = 3;
    b[1][0] = 4; b[1][1] = 2;  b[1][2] = 2;
    b[2][0] = 2; b[2][1] = 9;  b[2][2] = 7;
    b.print("b:");

    MatrixInverseSolver<double> solver2(b, 0.00001);
    solver2.solve().print("B^(-1):");
}