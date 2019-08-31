#ifndef SIMPLE_POLYNOMIAL_REAL_ROOTS_BOUNDARIES_SOLVER_H
#define SIMPLE_POLYNOMIAL_REAL_ROOTS_BOUNDARIES_SOLVER_H

#include "AbstractSolver.h"
#include "Point.h"
#include "SimplePolynomial.h"

const short int SIMPLE_METHOD = 0;
const short int NEWTON_METHOD = 1;

template <class S>
class SimplePolynomialRealRootsBoundariesSolver : public AbstractSolver<Point<Point<S>>, S> {
    typedef Point<Point<S>> BoundariesResult;
protected:
    Point<S> polinomialKoeffs;
    short int methodType;

    const BoundariesResult simpleMethod() const {
        S* polynomialKoeffs = Point<S>::toArray(this->polinomialKoeffs);
        S positiveCheck = findMin(polynomialKoeffs, this->polinomialKoeffs.length());

        this->polinomialKoeffs.forEach([&](int i, const Point<S>& point) -> void {
            polynomialKoeffs[i] = abs(polynomialKoeffs[i]);
        });

        S A = findMax(polynomialKoeffs, this->polinomialKoeffs.length() - 1);
        S range = 1 + A / abs(this->polinomialKoeffs[this->polinomialKoeffs.length()-1]);

        Point<S> positiveBoundaries;
        if(positiveCheck < 0) {
            positiveBoundaries = Point<S>(2);
            positiveBoundaries[0] = 0;
            positiveBoundaries[1] = range;
        }
        Point<S> negativeBoundaries(2);
        negativeBoundaries[0] = -range;
        negativeBoundaries[1] = 0;

        Point<Point<S>> result(2);
        result[0] = negativeBoundaries;
        result[1] = positiveBoundaries;
        return result;
    }

    const BoundariesResult newtonMethod() const {

    }

    const BoundariesResult computeResult() const {
        switch (methodType) {
            case SIMPLE_METHOD: {
                return simpleMethod();
            }
            case NEWTON_METHOD: {
                return newtonMethod();
            }
        }
        return Point<Point<S>>(2, Point<S>(2, 3));
    }

public:
    using AbstractSolver<BoundariesResult, S>::AbstractSolver;

    SimplePolynomialRealRootsBoundariesSolver(int n, S* koeffs, const short int methodType, const S epsilon):AbstractSolver<BoundariesResult, S>(epsilon) {
        this->methodType = methodType;
        polinomialKoeffs = Point<S>(n, koeffs);
    }

    SimplePolynomialRealRootsBoundariesSolver(const SimplePolynomial<S>& polynomial, const short int methodType, const S epsilon):AbstractSolver<BoundariesResult, S>(epsilon) {
        this->methodType = methodType;
        polinomialKoeffs = polynomial.getKoeffs();
    }
};

void TestSimplePolynomialRealRootsBoundariesSolver();

#endif //SIMPLE_POLYNOMIAL_REAL_ROOTS_BOUNDARIES_SOLVER_H
