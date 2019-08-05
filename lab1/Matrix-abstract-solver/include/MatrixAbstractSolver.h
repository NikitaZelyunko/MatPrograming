#ifndef MATRIX_ABSTRACT_SOLVER
#define MATRIX_ABSTRACT_SOLVER

#include "AbstractSolver.h"
#include "Matrix.h"

template<class T>
class MatrixAbstractSolver : public AbstractSolver<T> {
    protected:
        Matrix<T> matrix = Matrix<T>(0,0);
        bool isTriangular = false;
    
        virtual void matrixNotSquare() const {
            std::cout<<std::endl<<"The matrix is not square. The search for a determinant cannot be performed."<<std::endl;
        }

        bool checkTriangular(const Matrix<T>& matrix, bool cache) {
            bool isTriang = isAnyTriangular(matrix);
            if(cache) {
                this->isTriangular = isTriang;
            }
            return isTriang;
        }

    public:
        static bool isSquare(const Matrix<T>& x) {
            return x.getRowCount() == x.getColumnCount();
        }

        MatrixAbstractSolver(const Matrix<T>& matrix, T epsilon): AbstractSolver<T>(epsilon) {
            this->matrix = Matrix<T>(matrix);
        }

        MatrixAbstractSolver(const Matrix<T>& matrix, T epsilon, bool isTriangular): MatrixAbstractSolver<T>(matrix, epsilon) {
            this->isTriangular = isTriangular;
        }

        bool isLowerTriangular(const Matrix<T>& matrix) const {
            return matrix.everyLowerTriangle([&](int i, int j, const Matrix<T>& matrix) -> bool {
                return abs(matrix[i][j]) <= this->getEpsilon();
            });
        }

        bool isUpperTriangular(const Matrix<T>& matrix) const {
            return matrix.everyUpperTriangle([&](int i, int j, const Matrix<T>& matrix) -> bool {
                return abs(matrix[i][j]) <= this->getEpsilon();
            });
        }

        bool isAnyTriangular(const Matrix<T>& matrix) const {
            return isUpperTriangular(matrix) || isLowerTriangular(matrix);
        }
};

#endif