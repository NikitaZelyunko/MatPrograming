#ifndef SIMPLE_POLYNOMIAL_H
#define SIMPLE_POLYNOMIAL_H

#include "Point.h"
#include "OneDimensionalFunction.h"
#include "Utils.h"

template <class T>
class SimplePolynomial: public OneDimensionalFunction<T> {
private:
    Point<T> koeffs;

public:
    using OneDimensionalFunction<T>::OneDimensionalFunction;

    SimplePolynomial(const Point<T>& koeffs): SimplePolynomial<T>() {
        this->koeffs = Point<T>(koeffs);
    }
    SimplePolynomial(const SimplePolynomial<T>& polinom): SimplePolynomial<T>(polinom.koeffs) {}

    SimplePolynomial(int n, T* koeffs) {
        this->koeffs = Point<T>(n, koeffs);
    }
    SimplePolynomial(int n, const T& filler) {
        this->koeffs = Point<T>(n, filler);
    }

    ~SimplePolynomial() {};

    virtual const T operator()(const T point) const {
        T mult = 1;
        return koeffs.template reduce<T>(0, [&](const T acc, int i, const Point<T>& vector) -> const T {
            T result = mult * vector[i];
            mult *=point;
            return acc + result;
        });
    }

    virtual const T operator()(const Point<T>& point) const {
        return this->operator()(point[0]);
    }

    void print(std::string name, int countOfNumbers=0, int precision=0) const {
        std::cout<<std::endl<<name<<std::endl;
        koeffs.forEachReverse([&](int i, const Point<T>& point) -> void {
            if(i != point.length() - 1) {
                std::cout<<" "<<(sign(point[i]) ? "+" : "");
            }
            if(countOfNumbers != 0 && precision != 0) {
                std::cout<<std::fixed<<std::setw(countOfNumbers)<<std::setprecision(precision)<<point[i];
            } else {
                std::cout<<point[i];
            }
            if(i > 1) {
                std::cout<<"x^("<<i<<")";
            } else if(i == 1) {
                std::cout<<"x";
            }
        });
        std::cout<<std::endl;
    }

    const Point<T> getKoeffs() const {
        return Point<T>(this->koeffs);
    }

};

void TestSimplePolynomial();


#endif //SIMPLE_POLYNOMIAL_H