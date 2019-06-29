#include "../include/Matrix.h"

void TestMatrix() {
    cout<<endl<<endl;
    cout<<"-------------------"<<endl;
    cout<<"----Test Matrix----"<<endl;
    Matrix<double> a = Matrix<double>(2,2,-1.5);
    a.print("a:");

    a[0][0] = 0;
    a[1][1] = 10;
    a.print("a:");

    double** coeffs = new double*[3];
    for(int i = 0; i < 3; i++) {
        coeffs[i] = new double[2];
        for(int j = 0; j < 2; j++)
            coeffs[i][j] = 1;
    }

    Matrix<double> b = Matrix<double>(3, 2, coeffs);
    b.print("b:");

    Matrix<double> identity = Matrix<double>::createIdentityMatrix(4);
    identity.print("E:");

    Matrix<double> c = Matrix<double>(identity);

    c[0][0] = -1;
    c[1][1] = -1;
    c[2][2] = -1;
    c[3][3] = -1;
    c.print("c:");

    cout<<"--End test Matrix--"<<endl;
    cout<<"-------------------"<<endl;
    cout<<endl<<endl;
}