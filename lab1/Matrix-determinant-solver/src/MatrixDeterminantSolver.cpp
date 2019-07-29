#include "../include/MatrixDeterminantSolver.h"

void TestMatrixDeterminantSolver() {
    Matrix<double> a(2,2,2);
    a.print("a:");
    MatrixDeterminantSolver<double> solver = MatrixDeterminantSolver<double>(a, true);
    cout<<"Solve result:"<<solver.solve()<<endl;
}