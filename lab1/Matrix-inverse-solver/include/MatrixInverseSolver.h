#ifndef MATRIX_INVERSE_SOLVER
#define MATRIX_INVERSE_SOLVER

#include "Matrix.h"
#include "MatrixAbstractSolver.h"
#include "MatrixDeterminantSolver.h"

template<class S>
class MatrixInverseSolver : public MatrixAbstractSolver<Matrix<S>, S> {

    protected:
    virtual const Matrix<S> computeResult() const {
        S detMult = 1;
        Matrix<S> resultMatrix = Matrix<S>(this->matrix);
        Matrix<S> E = Matrix<S>::createIdenti;
        if(Matrix<S>::isSquare(resultMatrix)) {
            try {
                resultMatrix.forDiag([&](int i, const Matrix<S>& x) -> void {
                    if(i != x.getRowCount() - 1) {
                        int maxIndex = findRowIndexMaxElementInColumnFromL(x, i, i);
                        if (i != maxIndex) {
                            x.swapRows(i, maxIndex);
                            detMult *= -1;
                        }
                        S xii = x[i][i];
                        if (abs(xii) < epsilon) {
                            throw MATRIX_IS_DEGENERATE;
                        }
                        for(int k = i + 1; k < x.getColumnCount(); k++) {
                            S identifier = x[k][i]/xii;
                            for (int j = i; j < x.getColumnCount(); j++) {
                                x[k][j] -= x[i][j] * identifier;
                            }
                        }
                    }
                });
            }
            catch (int err) {
                if(err == MATRIX_IS_DEGENERATE) {
                    detMult = 0;
                }
            }
        }
        return resultMatrix;
    }

    public:
        using MatrixAbstractSolver<Matrix<S>, S>::MatrixAbstractSolver;
};

void TestMatrixInverseSolver();
#endif