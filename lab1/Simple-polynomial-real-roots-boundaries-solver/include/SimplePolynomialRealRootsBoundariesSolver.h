#ifndef SIMPLE_POLYNOMIAL_REAL_ROOTS_BOUNDARIES_SOLVER_H
#define SIMPLE_POLYNOMIAL_REAL_ROOTS_BOUNDARIES_SOLVER_H

#include "AbstractSolver.h"
#include "Point.h"

template <class S>
class SimplePolynomialRealRootsBoundariesSolver : public AbstractSolver<Point<Point<S>>, S> {

};

void TestSimplePolynomialRealRootsBoundariesSolver();

#endif //SIMPLE_POLYNOMIAL_REAL_ROOTS_BOUNDARIES_SOLVER_H
