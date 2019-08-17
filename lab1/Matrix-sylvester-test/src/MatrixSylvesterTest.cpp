#include "../include/MatrixSylvesterTest.h"


void TestMatrixSylvesterTest() {
    cout<<endl<<endl;
    cout<<"--------------------"<<endl;
    cout<<"Test: Matrix Sylvester test."<<endl;
    Matrix<double> a(3,3);
    a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
    a[1][0] = 4; a[1][1] = 2; a[1][2] = 2;
    a[2][0] = 2; a[2][1] = 9; a[2][2] = 7;
    a.print("a:");
    MatrixSylvesterTest<double> tester1(a, 0.00001);
    cout<<"Result:"<<tester1.solve()<<endl;

    Matrix<double> b(3,3);
    b[0][0] = 0; b[0][1] = 2; b[0][2] = 0;
    b[1][0] = 2; b[1][1] = 0; b[1][2] = 0;
    b[2][0] = 0; b[2][1] = 0; b[2][2] = 0;
    b.print("b:");
    MatrixSylvesterTest<double> tester2(b, 0.00001);
    cout<<"Result:"<<tester2.solve()<<endl;

    Matrix<double> c(3,3);
    c[0][0] = -2; c[0][1] = 2; c[0][2] = 0;
    c[1][0] = 2; c[1][1] = 3; c[1][2] = 0;
    c[2][0] = 0; c[2][1] = 0; c[2][2] = 2;
    c.print("c:");
    MatrixSylvesterTest<double> tester3(c, 0.00001);
    cout<<"Result:"<<tester3.solve()<<endl;

    Matrix<double> d(3,3);
    d[0][0] = -2; d[0][1] = 2; d[0][2] = 0;
    d[1][0] = 2; d[1][1] = -3; d[1][2] = 0;
    d[2][0] = 0; d[2][1] = 0; d[2][2] = -2;
    d.print("d:");
    MatrixSylvesterTest<double> tester4(d, 0.00001);
    cout<<"Result:"<<tester4.solve()<<endl;
    cout<<"--------------------"<<endl;
}