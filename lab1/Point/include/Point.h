#ifndef POINT_H
#define POINT_H

#include "../../Utils/include/Utils.h"

template<class T>
class Point {
    private:
        int n = 0;
        T* coeffs;
    // dimension


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

    inline void fillCoeffs(const T& filler) {
        for(int i = 0; i < n; i++)
            this->coeffs[i] = filler;
    }

    public:

    static T* copyArray(T* x, int n) {
        T* result = new T[n];
        for(int i = 0; i < n; i++) 
            result[i] = x[i];
        return result;
    }
    Point(int n) {
        this->n = correctDimension(n);
        this->coeffs = createOneDimArray(this->n);
    }

    Point(int n, const T& filler) {
        this->n = correctDimension(n);
        this->coeffs = new T[this->n];
        fillCoeffs(filler);
    }

    Point(int n, T* coeffs) {
        this->n = correctDimension(n);
        this->coeffs = copyArray(coeffs, this->n);
    }

    Point(const Point<T>& x) {
        this->n = x.n;
        this->coeffs = copyArray(x.coeffs, x.n);
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

    inline T& enorm() {
        T result = 0;
        for(int i =0; i < n; i++)
            result+=coeffs[i];
        return sqrt(result);
    }

    inline const Point<T> operator =(const Point<T>& x) {
        n = x.n;
        delete coeffs;
        coeffs = copyArray(x.coeffs, x.n);
        return *this;
    }

    inline const Point<T> operator =(const T& scalar) {
        delete coeffs;
        fillCoeffs(scalar);
        return *this;
    }

    inline const Point<T> operator *(const T& scalar) {
        Point<T> res(*this);
        for(int i = 0; i < n; i++)
            res[i] *=scalar;
        return res;
    }

    inline const Point<T> operator *=(const T& scalar) {
        for(int i = 0; i < n; i++)
            coeffs[i]*=scalar;
        return Point(*this);
    }    
    
    inline const Point<T> operator /(const T& scalar) {
        Point<T> res(*this);
        if(scalar != 0) {
            for(int i = 0; i < n; i++)
                res[i] /=scalar;
        }
        return res;
    }

    inline const Point<T> operator /=(const T& scalar) {
        if(scalar != 0) {
            for(int i = 0; i < n; i++)
                coeffs[i]/=scalar;
        }
        return Point(*this);
    }

    inline const Point<T> operator +(const Point<T>& x) {
        Point<T> res(*this);
        for(int i = 0; i < n; i++)
            res[i] += x[i];
        return res;
    }

    inline const Point<T> operator +=(const Point<T>& x) {
        for(int i = 0; i < n; i++)
            coeffs[i]+=x[i];
        return Point(*this);
    }

    inline const Point<T> operator -(const Point<T>& x) {
        Point<T> res(*this);
        for(int i = 0; i < n; i++)
            res[i] -= x[i];

        double a = 2;
        double b = a*=4;
        return res;
    }

    inline const Point<T> operator -=(const Point<T>& x) {
        for(int i = 0; i < n; i++)
            coeffs[i]-=x[i];
        return Point(*this);
    }

    inline void print(string name) {
        printArray(coeffs, n, name);
    }
};

void TestPoint();

#endif
