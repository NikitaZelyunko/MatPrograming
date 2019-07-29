#ifndef MATRIX_H
#define MATRIX_H

#include "Utils.h"

#include <functional>

template<class T>
class Matrix {

    private:

    int rowCount;
    int columnCount;
    // to do change to Row*, for example like alias of Point*
    T** coeffs;

    bool checkBoundary(int index) const {
        if(index >= 0) {
            if(index < rowCount) {
                return true;
            }
        }
        return false;
    }

    bool checkDimensionsEqual(int n1, int n2, int m1, int m2) const {
        if(n1 != n2) {
            return false;
        }
        if(m1 != m2) {
            return false;
        }
        return true;
    }

    bool checkDimensionsForMultMatrix(int n1, int n2, int m1, int m2) const {
        if(m1 != n2) {
            return false;
        }
        return true;
    }

    inline void printOutOfRange(int index) const {
        cout<<"Out of range "<<"rowCount="<<rowCount<<" index="<<index<<endl;
    }

    inline void printDimensionsIsNotEqual(int n1, int n2, int m1, int m2) const {
        cout<<"n1="<<n1<<" must be equal to n2="<<n2<<" m1="<<m1<<" must be equal to m2"<<m2<<endl;
    }

    inline void printDimensionsNotValidForMultMatrix(int n1, int n2, int m1, int m2) const {
        cout<<"m1="<<m1<<" must be equal to n2="<<n2<<endl;
    }

    public:

    static int correctDimension(int dimension) {
        return dimension < 0 ? 0 : dimension;
    }

    static T** copyMatrix(int rowCount, int columnCount, T** coeffs) {
        T** res = new T*[rowCount];
        for(int i =0; i < rowCount; i++) {
            res[i] = new T[columnCount];
            for(int j = 0; j < columnCount; j++) {
                res[i][j] = coeffs[i][j];
            }
        }
        return res;
    }

    static void deleteMatrix(int rowCount, T** coeffs) {
        for(int i = 0; i < rowCount; i++) {
            delete [] coeffs[i];
        }
        delete [] coeffs;
    }

    static T** createEmptyArray(int rowCount, int columnCount) {
        T** res = new T*[rowCount];
        for(int i = 0; i < rowCount; i++)
            res[i] = new T[columnCount];
        return res;
    }

    static T** createFillMatrix(int rowCount, int columnCount, const T& filler) {
        T** res = new T*[rowCount];
        for(int i = 0; i < rowCount; i++){
            res[i] = new T[columnCount];
            for(int j = 0; j < columnCount; j++)
                res[i][j] = filler;
        }
        return res;
    }

    static const Matrix<T> createIdentityMatrix(int rowCount) {
        T** coeffs = new T*[rowCount];
        for(int i = 0; i < rowCount; i++) {
            coeffs[i] = new T[rowCount];
            for(int j = 0; j < rowCount; j++)
                coeffs[i][j] = 0;
            coeffs[i][i] = 1;
        }
        return Matrix<T>(rowCount, rowCount, coeffs);
    }

    static const Matrix<T> transpose(const Matrix<T>& x) {
        Matrix<T> res = Matrix<T>(x.columnCount, x.rowCount);
        res.forEach([&](int i, int j, const Matrix<T>& matrix) -> void {
            res[i][j] = x[j][i];
        });
        return res;
    }

    Matrix(int rowCount, int columnCount) {
        this->rowCount = correctDimension(rowCount);
        this->columnCount = correctDimension(columnCount);
        this->coeffs = createEmptyArray(this->rowCount, this->columnCount);
    }

    Matrix(int rowCount, int columnCount, T** coeffs) {
        this->rowCount = correctDimension(rowCount);
        this->columnCount = correctDimension(columnCount);
        this->coeffs = copyMatrix(this->rowCount, this->columnCount, coeffs);
    }

    Matrix(int rowCount, int columnCount, const T& filler) {
        this->rowCount = correctDimension(rowCount);
        this->columnCount = correctDimension(columnCount);
        this->coeffs = createFillMatrix(this->rowCount, this->columnCount, filler);
    }

    Matrix(const Matrix<T>& x) {
        this->rowCount = x.rowCount;
        this->columnCount = x.columnCount;
        this->coeffs = copyMatrix(x.rowCount, x.columnCount, x.coeffs);
    }

    ~Matrix() {
        deleteMatrix(rowCount, coeffs);
    }

    inline void forEach(function<void (int, int, const Matrix<T>&)> callback) const  {
        for(int i = 0; i < rowCount; i++) {
            for(int j = 0; j < columnCount; j++){
                callback(i, j, *this);
            }
        }
    }
    
    inline const T reduce(T startAcc, function<T (T&, int, int, const Matrix<T>&)> callback) const {
        for(int i = 0; i < rowCount; i++){
            for(int j = 0; j < columnCount; j++) {
                startAcc = callback(startAcc, i, j, *this);
            }
        }
        return startAcc;
    }

    inline const Matrix<T> operator =(const Matrix<T>& x) {
        deleteMatrix(rowCount, coeffs);
        rowCount = x.rowCount;
        columnCount = x.columnCount;
        coeffs = copyMatrix(rowCount, columnCount, x.coeffs);
        return *this;
    }

    inline T* operator[](int rowIndex) const {
        // return T* but perhaps must return Point or Row
        if(checkBoundary(rowIndex)) {
            return coeffs[rowIndex];
        }
        printOutOfRange(rowIndex);
        return nullptr;
    }

    inline const Matrix<T> operator *(const T& scalar) const {
        Matrix<T> res = Matrix<T>(*this);
        forEach([&](int i, int j, const Matrix<T>& matrix) -> void {
            res[i][j] *=scalar;
        });
        return res;
    }

    inline const Matrix<T> operator *=(const T& scalar) {
        forEach([&](int i, int j, const Matrix<T>& matrix) -> void {
            matrix[i][j] *= scalar;
        });
        return *this;
    }

    inline const Matrix<T> operator -(const Matrix<T>& x) const {
        Matrix<T> res = Matrix<T>(*this);
        if(checkDimensionsEqual(rowCount, x.rowCount, columnCount, x.columnCount)) {
            res.forEach([&](int i, int j, const Matrix<T>& matrix) -> void {
                matrix[i][j] = coeffs[i][j] - x[i][j];
            });
        } else {
            printDimensionsIsNotEqual(rowCount, x.rowCount, columnCount, x.columnCount);
        }
        return res;
    }

    inline const Matrix<T> operator -=(const Matrix<T>& x) {
        if(checkDimensionsEqual(rowCount, x.rowCount, columnCount, x.columnCount)) {
            forEach([&](int i, int j, const Matrix<T>& matrix) -> void {
                matrix[i][j] -= x[i][j];
            });
        } else {
            printDimensionsIsNotEqual(rowCount, x.rowCount, columnCount, x.columnCount);
        }
        return *this;
    }

    inline const Matrix<T> operator +(const Matrix<T>& x) const {
        Matrix<T> res = Matrix<T>(*this);
        if(checkDimensionsEqual(rowCount, x.rowCount, columnCount, x.columnCount)) {
            res.forEach([&](int i, int j, const Matrix<T>& matrix) -> void {
                matrix[i][j] = coeffs[i][j] + x[i][j];
            });
        } else {
            printDimensionsIsNotEqual(rowCount, x.rowCount, columnCount, x.columnCount);
        }
        return res;
    }

    inline const Matrix<T> operator +=(const Matrix<T>& x) {
        if(checkDimensionsEqual(rowCount, x.rowCount, columnCount, x.columnCount)) {
            forEach( [&](int i, int j, const Matrix<T>& matrix) -> void {
                matrix[i][j] += x[i][j];
            });
        } else {
            printDimensionsIsNotEqual(rowCount, x.rowCount, columnCount, x.columnCount);
        }
        return *this;
    }

    inline const Matrix<T> operator *(const Matrix<T>& x) const {
        Matrix<T> res = Matrix<T>(rowCount, x.columnCount);
        if(checkDimensionsForMultMatrix(rowCount, x.rowCount, columnCount, x.columnCount)) {
            res.forEach([&](int i, int j, const Matrix<T>& matrix) -> void {
                T sum = 0;
                for(int k = 0; k < columnCount; k++)
                    sum+= coeffs[i][k] * x[k][j];
                res[i][j] = sum;
            });
        } else {
            printDimensionsNotValidForMultMatrix(rowCount, x.rowCount, columnCount, x.columnCount);
        }
        return res;
    }

    inline const Matrix<T> operator *=(Matrix<T>& x) {
        Matrix<T> res = this->operator*(x);
        (*this) = res;
        return *this;
    }

    inline const Matrix<T> transpose() {
        Matrix<T> res = Matrix<T>(columnCount, rowCount);
        res.forEach([this](int i, int j, const Matrix<T>& matrix) -> void {
            matrix[i][j] = coeffs[j][i];
        });
        (*this) = res;
        return *this;
    }

    inline int getRowCount() const {
        return this->rowCount;
    }

    inline int getColumnCount() const {
        return this->columnCount;
    }

    inline int n() const {
        return this->rowCount;
    }

    inline int m() const {
        return this->columnCount;
    }

    void print(string comment) const {
        printArray(coeffs, rowCount, columnCount, comment);
    }
};

void TestMatrix();

#endif