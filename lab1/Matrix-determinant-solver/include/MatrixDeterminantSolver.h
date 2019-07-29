#ifndef MATRIX_DETERMINANT_SOLVER
#define MATRIX_DETERMINANT_SOLVER

#include <iostream>
#include <string>

#include "AbstractSolver.h"
#include "Matrix.h"

template <class T>
class MatrixDeterminantSolver : public AbstractSolver<T>
{
private: 
    Matrix<T> matrix = Matrix<T>(0,0);
    bool isTriangular = false;
    bool convertToTriangular = true;

    void solverNotInited() const {
        cout<<"Solver not inited"<<endl;
    }

    void solverNotSolved() const {
        cout<<"Solver not solved"<<endl;
    }
    const T evaluateDet() const {
        if(this->isTriangular) {
            return this->matrix.reduce(1, [&](T acc, int i, int j, const Matrix<T>& matrix) -> const T {
                return i == j ? acc * matrix[i][j] : acc;
            });
        }
        return 0;
    }

public:

    MatrixDeterminantSolver(const Matrix<T>& matrix) {
        this->matrix = Matrix<T>(matrix);
    }

    MatrixDeterminantSolver(const Matrix<T>& matrix, bool isTriangular) {
        this->matrix = Matrix<T>(matrix);
        this->isTriangular = isTriangular;
    }

    MatrixDeterminantSolver(const Matrix<T>& matrix, bool isTriangular, bool convertToTriangular) {
        this->matrix = Matrix<T>(matrix);
        this->isTriangular = isTriangular;
        this->convertToTriangular = convertToTriangular;
    }

    const T solve() {
        this->result = this->evaluateDet();
        return this->getResult();
    }

    const T getResult() const {
        if(!this->result) {
            this->solverNotSolved();
        }
        return this->result;
    }

    void print(string prefix) const {
        if(this->matrix) {
            cout<<"Determinant matrix:"<<endl;
            this->matrix.print(prefix);
            cout<<"Is: "<<getResult()<<endl;
        } else {
            this->solverNotInited();
        }
    }
};

void TestMatrixDeterminantSolver();

#endif