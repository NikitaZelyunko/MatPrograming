#ifndef ONE_DIMENSIONAL_FUNCTION_H
#define ONE_DIMENSIONAL_FUNCTION_H
#include "Function.h"

template <class T>
class OneDimensionalFunction : public Function<T>
{
public:
    virtual T& operator() (T&);
    OneDimensionalFunction() {}
    ~OneDimensionalFunction();
};

#endif