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

    void solverNotInited() const {
        cout<<endl<<"Solver not inited"<<endl;
    }

    void solverNotSolved() const {
        cout<<endl<<"Solver not solved"<<endl;
    }

    const T computeTriangularDet(const Matrix<T>& x) const {
        return x.reduce(1, [&](T acc, int i, int j, const Matrix<T>& matrix) -> const T {
                return i == j ? acc * matrix[i][j] : acc;
        });
    }

    const Matrix<T> getLowerTriangular() const {
        return Matrix<T>(1,1,1);
    }

    const T evaluateGeneralFormMatrixDet() const {
        Matrix<T> lowerTriangMatrix = this->getLowerTriangular();
        return this->computeTriangularDet(lowerTriangMatrix);
    }

    const T computeDet() {
        if(this->isTriangular) {
            return this->computeTriangularDet(this->matrix);
        } else {
            return this->evaluateGeneralFormMatrixDet();
        }
    }

public:

    MatrixDeterminantSolver(const Matrix<T>& matrix) {
        this->matrix = Matrix<T>(matrix);
    }

    MatrixDeterminantSolver(const Matrix<T>& matrix, bool isTriangular) {
        this->matrix = Matrix<T>(matrix);
        this->isTriangular = isTriangular;
    }

    const T solve() {
        this->result = this->computeDet();
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