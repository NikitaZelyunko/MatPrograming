#ifndef MATRIX_H
#define MATRIX_H

#include "../../Utils/include/Utils.h"

template<class T>
class Matrix {
    private:

    int rowCount;
    int columnCount;
    // to do change to Row*, for example like alias of Point*
    T** coeffs;

    bool checkBoundary(int index) {
        if(index >= 0) {
            if(index < rowCount) {
                return true;
            }
        }
        return false;
    }

    bool checkDimensionsEqual(int n1, int n2, int m1, int m2) {
        if(n1 != n2) {
            return false;
        }
        if(m1 != m2) {
            return false;
        }
        return true;
    }

    bool checkDimensionsForMultMatrix(int n1, int n2, int m1, int m2){
        if(m1 != n2) {
            return false;
        }
        return true;
    }

    inline void printOutOfRange(int index) {
        cout<<"Out of range "<<"rowCount="<<rowCount<<" index="<<index<<endl;
    }

    inline void printDimensionsIsNotEqual(int n1, int n2, int m1, int m2) {
        cout<<"n1="<<n1<<" must be equal to n2="<<n2<<" m1="<<m1<<" must be equal to m2"<<m2<<endl;
    }

    inline void printDimensionsNotValidForMultMatrix(int n1, int n2, int m1, int m2) {
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

    inline T* operator[](int rowIndex) {
        // return T* but perhaps must return Point or Row
        if(checkBoundary(rowIndex)) {
            return coeffs[rowIndex];
        }
        printOutOfRange(rowIndex);
    }

    inline const Matrix<T> operator *(const T& scalar) {
        Matrix<T> res = Matrix<T>(*this);
        for(int i = 0; i < rowCount; i++)
            for(int j = 0; j < columnCount; j++)
                res[i][j] *=scalar;
        return res;
    }

    inline const Matrix<T> operator -(const Matrix<T>& x) {
        if(checkDimensionsEqual(rowCount, x.rowCount, columnCount, x.columnCount)) {
            Matrix<T> res = Matrix<T>(*this);
            for(int i = 0; i < rowCount; i++)
                for(int j = 0; j < columnCount; j++)
                    res[i][j] = coeffs[i][j] - x[i][j];
            return res;
        }
        printDimensionsIsNotEqual(rowCount, x.rowCount, columnCount, x.columnCount);
    }

    inline const Matrix<T> operator +(const Matrix<T>& x) {
        if(checkDimensionsEqual(rowCount, x.rowCount, columnCount, x.columnCount)) {
            Matrix<T> res = Matrix<T>(*this);
            for(int i = 0; i < rowCount; i++)
                for(int j = 0; j < columnCount; j++)
                    res[i][j] = coeffs[i][j] + x[i][j];
            return res;
        }
        printDimensionsIsNotEqual(rowCount, x.rowCount, columnCount, x.columnCount);
    }

    inline const Matrix<T> operator *(const Matrix<T>& x) {
        if(checkDimensionsForMultMatrix(rowCount, x.rowCount, columnCount, x.columnCount)) {
            T** coeffs = new T*[rowCount];
            for(int i = 0; i < rowCount; i++) {
                coeffs[i] = new T[x.columnCount];
                for(int j = 0; j < x.columnCount; j++) {
                    T sum = 0;
                    for(int k = 0; k < columnCount; k++)
                        sum+= coeffs[i][k] * x[k][j];
                    coeffs[i][j] = sum;
                }
            }
            return Matrix<T>(rowCount, x.columnCount, coeffs);
        }
        printDimensionsNotValidForMultMatrix(rowCount, x.rowCount, columnCount, x.columnCount);
    }


    inline int getRowCount() {
        return this->rowCount;
    }

    inline int getColumnCount() {
        return this->columnCount;
    }

    inline int n() {
        return this->rowCount;
    }

    inline int m() {
        return this->columnCount;
    }

    void print(string comment) {
        printArray(coeffs, rowCount, columnCount, comment);
    }
};

void TestMatrix();

#endif