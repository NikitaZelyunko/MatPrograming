#ifndef MATRIX_DETERMINANT_SOLVER
#define MATRIX_DETERMINANT_SOLVER

#include <iostream>
#include <string>

#include "MatrixAbstractSolver.h"
#include "Matrix.h"

const int MATRIX_IS_DEGENERATE = 0;

template <class T>
class MatrixDeterminantSolver : public MatrixAbstractSolver<T>
{
private:
    int findRowIndexMaxElementInColumnFromL(const Matrix<T>& x, int k, int l) const {
        int indexMax = l;
        T maxElem = x[l][l];
        for (int i = l; i < x.getRowCount(); i++) {
            if (abs(x[i][k]) > abs(maxElem)) {
                indexMax = i;
                maxElem = x[i][k];
            }
        }
        return indexMax;
    }

    const T computeTriangularDet(const Matrix<T>& x) const {
        if(this->isSquare(x)) {
            return x.forDiagReduce(1, [&](T acc, int i, const Matrix<T>& matrix) -> const T {
                return acc * matrix[i][i];
            });
        }
        this->matrixNotSquare();
        return this->getResult();
    }

    const T evaluateGeneralFormMatrixDet() const {
        if(this->isSquare(this->matrix)) {
            Matrix<T> resultMatrix = Matrix<T>(this->matrix);
            T det = 1;
            try {
                resultMatrix.forDiag([&](int i, const Matrix<T>& x) -> void {
                    if(i != x.getRowCount() - 1) {
                        int maxIndex = findRowIndexMaxElementInColumnFromL(x, i, i);
                        if (i != maxIndex) {
                            x.swapRows(i, maxIndex);
                            det *= -1;
                        }
                        T xii = x[i][i];
                        if (abs(xii) < this->epsilon) {
                            throw MATRIX_IS_DEGENERATE;
                        }
                        for(int k = i + 1; k < x.getColumnCount(); k++) {
                            T identifier = x[k][i]/xii;
                            for (int j = i; j < x.getColumnCount(); j++) {
                                x[k][j] -= x[i][j] * identifier;
                            }
                        }
                    }
                });
                return det * computeTriangularDet(resultMatrix);
            }
            catch (int err) {
                if(err == MATRIX_IS_DEGENERATE) {
                    return 0;
                }
            }
        } 
        else {
            this->matrixNotSquare();
        }
        return this->getResult();
    }

    const T computeDet() const {
        if(this->isTriangular) {
            return this->computeTriangularDet(this->matrix);
        } else {
            return this->evaluateGeneralFormMatrixDet();
        }
    }

public:
    using MatrixAbstractSolver<T>::MatrixAbstractSolver;
    const T solve() {
        this->setResult(computeDet());
        return this->getResult();
    }

    void print(string prefix) const {
        if(this->matrix) {
            cout<<"Determinant matrix:"<<endl;
            this->matrix.print(prefix);
            cout<<"Is: "<<this->getResult()<<endl;
        } else {
            this->solverNotInited();
        }
    }
};

void TestMatrixDeterminantSolver();

#endif