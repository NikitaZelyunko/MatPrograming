#ifndef SIMPLE_POLINOM_H
#define SIMPLE_POLINOM_H

#include "Point.h"
#include "OneDimensionalFunction.h"

template <class T>
class SimplePolinom: public OneDimensionalFunction<T> {
private:
    Point<T> koeffs;

public:
    using OneDimensionalFunction<T>::OneDimensionalFunction;

    SimplePolinom(const Point<T>& koeffs): SimplePolinom<T>() {
        this->koeffs = new Point<T>(koeffs);
    }
    SimplePolinom(const SimplePolinom<T>& polinom): SimplePolinom<T>(polinom.koeffs) {}

    SimplePolinom(int n, T* koeffs) {
        this->koeffs = Point<T>(n, koeffs);
    }
    SimplePolinom(int n, const T& filler) {
        this->koeffs = Point<T>(n, filler);
    }

    ~SimplePolinom() {};

    virtual const T& operator()(const T& point) const {
        T mult = 1;
        return koeffs.template reduce<T>(0, [&](const T& acc, int i, const Point<T>& vector) -> const T& {
            T result = mult * vector[i];
            mult *=point;
            return std::move(acc + result);
        });
    }

    void print(std::string name, int countOfNumbers=0, int precision=0) const {
        std::cout<<std::endl<<name<<std::endl;
        koeffs.forEachReverse([&](int i, const Point<T>& point) -> void {
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
            if(i > 0){
                std::cout<<" + ";
            }
        });
        std::cout<<std::endl;
    }
};

void TestSimplePolinom();


#endif //SIMPLE_POLINOM_H