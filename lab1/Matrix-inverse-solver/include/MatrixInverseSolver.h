#ifndef MATRIX_INVERSE_SOLVER
#define MATRIX_INVERSE_SOLVER

#include "Matrix.h"
#include "AbstractSolver.h"
#include "MatrixDeterminantSolver.h"

template<class T>
class MatrixInverseSolver : public AbstractSolver<Matrix<T>> {
    Matrix<T> matrix = Matrix<T>(0,0);
    MatrixDeterminantSolver<T> determinant;
    public:
        using AbstractSolver<Matrix<T>>::AbstractSolver;

        MatrixInverseSolver(const Matrix<T>& matrix, T epsilon): AbstractSolver<Matrix<T>>(epsilon) {
            this->matrix = Matrix<T>(matrix);
            this->determinant = MatrixDeterminantSolver<T>(matrix, epsilon);
        }
};
#endif