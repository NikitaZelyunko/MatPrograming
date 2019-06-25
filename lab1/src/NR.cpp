#include "../include/NR.h"

// double eNorm(double * x, int n)
// {
// 	double result = 0;
// 	for (int i = 0; i < n; i++) {
// 		result += pow(x[i], 2);
// 	}
// 	return sqrt(result);
// }

// void printArray(double * a, int n, string comment)
// {
	
// 	if (a) {
// 		cout << comment << endl;
// 		for (int i = 0; i < n; i++) {
// 			cout << a[i] << " ";
// 		}
// 		cout << endl;
// 	}
// 	else cout << "printArray: a not exist" << endl;
// }

// void printArray(double ** a, int n, int m, string comment)
// {
// 	if (a) {
// 		cout << comment << endl;
// 		for (int i = 0; i < n; i++) {
// 			for (int j = 0; j < m; j++) {
// 				cout << a[i][j] << " ";
// 			}
// 			cout << endl;
// 		}
// 	}
// 	else cout << "printArray: a not exist" << endl;
// }

// double ** createTwoDimArray(int n, int m)
// {
// 	double** result = new double*[n];
// 	for (int i = 0; i < n; i++) {
// 		result[i] = new double[n];
// 	}
// 	return result;
// }

// void deleteTwoDimArray(double ** a, int n)
// {
// 	for (int i = 0; i < n; i++) {
// 		delete[] a[i];
// 	}
// 	delete a;
// }

// double * getCopyArray(double * a, int n)
// {
// 	double* result = createOneDimArray(n);
// 	for (int i = 0; i < n; i++) {
// 		result[i] = a[i];
// 	}
// 	return result;
// }

// double ** getCopyArray(double ** a, int n, int m)
// {
// 	double **result = createTwoDimArray(n, m);
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			result[i][j] = a[i][j];
// 		}
// 	}
// 	return result;
// }

// double * multOnScalar(double * x, int n, double scalar)
// {
// 	double* result = createOneDimArray(n);
// 	for (int i = 0; i < n; i++) {
// 		result[i] = scalar*x[i];
// 	}
// 	return result;
// }

// double ** multOnScalar(double ** A, int n, int m, double scalar)
// {
// 	double** result = createTwoDimArray(n, m);
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			result[i][j] = scalar * A[i][j];
// 		}
// 	}
// 	return result;
// }

// double * expVector(double * x, double exp, int n)
// {
// 	double* result = createOneDimArray(n);
// 	for (int i = 0; i < n; i++) {
// 		result[i] = pow(x[i], exp);
// 	}
// 	return result;
// }

// double * sumVectors(double * x1, double* x2, int n)
// {
// 	double* result = createOneDimArray(n);
// 	for (int i = 0; i < n; i++) {
// 		result[i] = x1[i] + x2[i];
// 	}
// 	return result;
// }

// double * sumVectorsMultOnScalars(double a, double * x1, double b, double * x2, int n)
// {
// 	double* result = createOneDimArray(n);
// 	for (int i = 0; i < n; i++) {
// 		result[i] = a*x1[i] + b*x2[i];
// 	}
// 	return result;
// }

// double * substrVectors(double * x1, double * x2, int n)
// {
// 	double* minusX2 = multOnScalar(x2, n, -1);
// 	for (int i = 0; i < n; i++) {
// 		minusX2[i] += x1[i];
// 	}
// 	return minusX2;
// }

// double scalarMult(double * x1, double* x2, int n)
// {
// 	double result = 0;
// 	for (int i = 0; i < n; i++) {
// 		result += x1[i] * x2[i];
// 	}
// 	return result;
// }

// double * multMatrixOnVector(double ** A, int n, int m, double * x)
// {
// 	double* result = createOneDimArray(n);
// 	for (int i = 0; i < n; i++) {
// 		double sum = 0;
// 		for (int j = 0; j < m; j++) {
// 			sum += A[i][j] * x[j];
// 		}
// 		result[i] = sum;
// 	}
// 	return result;
// }

// double ** MakeIdentityMatrix(int n)
// {
// 	double** E = createTwoDimArray(n, n);
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			E[i][j] = 0;
// 		}
// 		E[i][i] = 1;
// 	}
// 	return E;
// }

void swapRows(double ** A, int m, int k, int l)
{
	for (int j = 0; j < m; j++) {
		swap(A[k][j], A[l][j]);
	}
}

int findRowIndexMaxElementInColumnFromL(double ** A, int n, int k, int l)
{
	int indexMax = l;
	double maxElem = A[l][l];
	for (int i = l; i < n; i++) {
		if (abs(A[i][k]) > maxElem) {
			indexMax = i;
			maxElem = A[i][k];
		}
	}
	return indexMax;
}

MatrixWithDeterm* inverseMatrix(MatrixWithDeterm &matrix, double epsilon)
{
	double** A = getCopyArray(matrix.matrix, matrix.n, matrix.m);
	int n = matrix.n;

	double** E = MakeIdentityMatrix(n);
	double det = 1;
	// ������ ���
	for (int i = 0; i < n; i++) {
		int maxIndex = findRowIndexMaxElementInColumnFromL(A, n, i, i);
		if (i != maxIndex) {
			swapRows(A, n, i, maxIndex);
			swapRows(E, n, i, maxIndex);
			det *= -1;
		}
		double aii = A[i][i];
		if (module(aii) < epsilon) {
			cout << "A[i][i] == 0 i = " << i << endl;
			return new MatrixWithDeterm(nullptr, 0, 0, 0);
		}
		for (int j = 0; j < n; j++) {
			A[i][j] /= aii;
		}
		for (int j = 0; j < n; j++) {
			E[i][j] /= aii;
		}

		for (int k = i + 1; k < n; k++) {
			double aki = A[k][i];
			for (int j = i; j < n; j++) {
				A[k][j] -= A[i][j] * aki;
			}
			for (int j = 0; j < n; j++) {
				E[k][j] -= E[i][j] * aki;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		det *= A[i][i];
	}
	if (det == 0) {
		cout << "Determ == 0" << endl;
		return new MatrixWithDeterm(nullptr, 0, 0, 0);
	}

	// �������� ���

	for (int i = n - 1; i >= 0; i--) {
		for (int k = i - 1; k >= 0; k--) {
			double aki = A[k][i];
			A[k][i] = 0;
			for (int j = 0; j < n; j++) {
				E[k][j] -= E[i][j] * aki;
			}
		}
	}

	return new MatrixWithDeterm(E, n, n, det);
}

double* getTochnValue(
	double* x0, int n,
	double e1, double e2,
	F f, Grad grad, Hessian h, Min min,
	int M) {

	double *result = createOneDimArray(n);

	double *gradXk;

	double *xK = getCopyArray(x0, n);
	double *xK_1;
	double *xK_Xk_1;

	double tk = 0;

	double* dk;
	double* tDk;

	MatrixWithDeterm *H = new MatrixWithDeterm(nullptr, 0, 0, 0);
	MatrixWithDeterm *H_1 = new MatrixWithDeterm(nullptr, 0, 0, 0);

	int k = 0;
	int condEnd = 0;
	do {
		gradXk = grad(xK, n);
		if (eNorm(gradXk, n) >= e1) {
			H = new MatrixWithDeterm(h(xK, n), n, n, 0);
			
			H_1 = inverseMatrix(*H, e1);
			
			if (H_1->determ > 0) {
				dk = multMatrixOnVector(H_1->matrix, n, n, gradXk);
			}
			else {
				dk = gradXk;
			}

			tk = min(xK, dk);
			tDk = multOnScalar(dk, n, tk);
			xK_1 = sumVectors(xK, tDk, n);
			xK_Xk_1 = substrVectors(xK_1, xK, n);
			
			if (eNorm(xK_Xk_1, n) <= e2 && module(f(xK_1) - f(xK)) <= e2) {
				condEnd++;
			}
			else {
				condEnd = 0;
			}

			delete xK;
			delete dk;
			delete tDk;
			delete xK_Xk_1;
			delete H;
			delete H_1;
			xK = xK_1;
		}
		else {
			condEnd = 3;
		}

		delete gradXk;
		k++;
	} while (k < M && condEnd <2 );

	cout << "k: " << k << endl;
	return xK;
}
