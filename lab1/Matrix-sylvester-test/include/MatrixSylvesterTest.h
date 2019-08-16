#ifndef MATRIX_SYLVESTER_TEST_H
#define MATRIX_SYLVESTER_TEST_H

#include "Point.h"
#include "Matrix.h"
#include "MatrixAbstractSolver.h"

const int ALTERNATING_CERTAINTY = 0;
const int POSITIVE_CERTAINTY = 1;
const int NEGATIVE_CERTAINTY = 2;

template <class S>
class MatrixSylvesterTest : MatrixAbstractSolver<int, S> {
    private:
    const S multKElementsPoint(const Point<S>& point, int k) {
        S result = 1;
        for(int i = 0; i<point.n() && i < k; i++) {
            result*=point[i];
        }
        return result;
    }
    const int resolveCertainty() {
        int minDimension = min(this->matrix.getColumnCount(), this->matrix.getRowCount());
        Point<S> cornerMinors = Point<S>(minDimension);
        Matrix<S> resultMatrix = Matrix<S>(this->matrix);
        if(Matrix<S>::isSquare(resultMatrix)) {
            try {
                resultMatrix.forDiag([&](int i, const Matrix<S>& x) -> void {
                    S xii = x[i][i];
                    if(abs(xii) >= this->getEpsilon()) {
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
            }
        }
        return ALTERNATING_CERTAINTY;
    }

    protected: 
    /*
        If matrix is positive certainty return 1;
        If matrix is negative certainty return 2;
        Else return 0.        
    **/
    virtual const int computeResult() const {

    }

    public:
    using MatrixAbstractSolver<int,S>::MatrixAbstractSolver;

    const int solve() {
        return ALTERNATING_CERTAINTY;
    }
};

void TestMatrixSylvesterTest();

#endif
