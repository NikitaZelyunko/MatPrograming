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

    void resultIsNotInited() const {
        std::cout<<std::endl<<"result is not inited"<<std::endl;
    }

    const T setResult(const T& newValue) {
        isInit = true;
        result = newValue;
        return result;
    }

    const T getResult() const {
        if(!isInit) {
           resultIsNotInited();
        }
        return this->result;
    }
public:
    virtual const T solve() {return this->result;};
    AbstractSolver(){};
    ~AbstractSolver(){};

};

#endif