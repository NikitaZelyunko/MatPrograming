#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include "../../Point/include/Point.h"

using namespace std;

template<class T>
class Function
{
public:
    virtual T& operator() (Point<T>&);
    Function();
    ~Function();
};

#endif