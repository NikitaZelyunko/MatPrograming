//
// Created by Никита on 11.08.2019.
//

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
    MatrixSylvesterTest<double> tester(a, 0.00001);
    cout<<"Result:"<<tester.solve()<<endl;
    cout<<"--------------------"<<endl;
}