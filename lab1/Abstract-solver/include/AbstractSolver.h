#ifndef ABSTRACT_SOLVER_H
#define ABSTRACT_SOLVER_H

#include <iostream>

template<class T>
class AbstractSolver {
private:
    T result;
protected:

    bool isInit = false;
    T epsilon;

    virtual void solverNotInited() const {
        std::cout<<std::endl<<"Solver not inited"<<std::endl;
    }

    virtual void solverNotSolved() const {
        std::cout<<std::endl<<"Solver not solved. Run solve() method before ask result."<<std::endl;
    }

    virtual void resultIsNotInited() const {
        std::cout<<std::endl<<"result is not inited"<<std::endl;
    }

    const T setResult(const T& newValue) {
        isInit = true;
        result = newValue;
        return result;
    }

    AbstractSolver(T epsilon){
        this->epsilon = epsilon;
    };

public:
    virtual const T solve() {return this->result;};
    
    ~AbstractSolver(){};

    bool isSolved() const {
        return this->isInit;
    }

    const T getResult() const {
        if(!isInit) {
           resultIsNotInited();
        }
        return this->result;
    }

    const T getEpsilon() const {
        return this->epsilon;
    }

};

#endif