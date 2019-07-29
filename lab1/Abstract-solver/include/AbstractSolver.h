#ifndef ABSTRACT_SOLVER_H
#define ABSTRACT_SOLVER_H

template<class T>
class AbstractSolver {
protected:
    T result;
public:
    virtual const T solve(){return 0;}
    AbstractSolver(){};
    ~AbstractSolver(){};
};

#endif