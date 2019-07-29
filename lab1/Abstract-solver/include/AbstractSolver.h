#ifndef ABSTRACT_SOLVER_H
#define ABSTRACT_SOLVER_H

template<class T>
class AbstractSolver {
private:
    T result;

    virtual const T solve();
};

#endif