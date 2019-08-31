#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

typedef double (*F) (double*);
typedef double* (*Grad) (double*, int);
typedef double** (*Hessian) (double*, int);
typedef double(*XtD) (double*, double*, double);
typedef double(*Min) (double*, double*);

typedef double(*f) (double);

double* getTochnValue(double* x0, int n, double e1, double e2, F f, Grad grad, Hessian h, Min min, int M);

double eNorm(double* x, int n);

inline double module(double x) {
	return x < 0 ? -x : x;
}

template<class T =double>
inline bool sign(T x) {
	return x < 0 ? false : true;
}

void printArray(double* a, int n, string comment);
void printArray(double** a, int n, int m, string comment);

inline double* createOneDimArray(int n) {
	return new double[n];
}

double** createTwoDimArray(int n, int m);

void deleteTwoDimArray(double** a, int n);

double*	 getCopyArray(double* a, int n);
double** getCopyArray(double** a, int n, int m);

double* multOnScalar(double* x, int n, double scalar);
double** multOnScalar(double** A, int n, int m, double scalar);

double* expVector(double* x, double exp, int n);

// x1 + x2
double* sumVectors(double* x1, double* x2, int n);

//a*x1 + b*x2
double* sumVectorsMultOnScalars(double a, double* x1, double b, double* x2, int n);

// x1 - x2
double* substrVectors(double* x1, double* x2, int n);

double scalarMult(double* x1, double* x2, int n);

double* multMatrixOnVector(double** A, int n, int m, double* x);

double** MakeIdentityMatrix(int n);

#endif