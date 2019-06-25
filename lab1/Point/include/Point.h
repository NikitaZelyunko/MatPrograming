#ifndef POINT_H
#define POINT_H

#include "../../Utils/include/Utils.h"

template<class T>
class Point {
    private:
    // dimension
    int n = 0;
    T* coeffs;

    bool checkBoundary(int index) {
        if(index >= 0) {
            if(index < n) {
                return true;
            }
        }
        return false;
    }

    inline int correctDimension(int dimension) {
        return dimension < 0 ? 0 : dimension;
    }

    inline void printOutOfRange(int index) {
        cout<<"Out of range "<<"n="<<n<<" index="<<index<<endl;
    }

    inline void fillCoeffs(T filler) {
        for(int i = 0; i < n; i++)
            this->coeffs[i] = filler;
    }

    public:
    Point(int n) {
        this->n = correctDimension(n);
        this->coeffs = createOneDimArray(this->n);
    }

    Point(int n, T filler) {
        this->n = correctDimension(n);
        this->coeffs = createOneDimArray(this->n);
        fillCoeffs(filler);
    }

    Point(int n, T* coeffs) {
        this->n = n;
        this->coeffs = coeffs;
    }

    ~Point() {
        delete coeffs;
    }

    T& operator[] (int index) {
        if(checkBoundary(index)) {
            return coeffs[index];
        }
        printOutOfRange(index);
    }

    inline void print(string name) {
        printArray(coeffs, n, name);
    }
};

void TestPoint();

#endif
