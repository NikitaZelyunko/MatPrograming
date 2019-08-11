//
// Created by Никита on 11.08.2019.
//

#ifndef MATRIX_SYLVESTER_TEST_H
#define MATRIX_SYLVESTER_TEST_H

#include "Matrix.h"
#include "MatrixAbstractSolver.h"

template <class S>
class MatrixSylvesterTest : MatrixAbstractSolver<bool, S> {
    public:
    using MatrixAbstractSolver<bool,S>::MatrixAbstractSolver;

    bool solve() {
        return false;
    }
};

void TestMatrixSylvesterTest();

#endif // MATRIX_SYLVESTER_TEST_H
