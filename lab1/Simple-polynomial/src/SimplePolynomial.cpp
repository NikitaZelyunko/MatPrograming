#include "SimplePolynomial.h"

void TestSimplePolynomial() {
    std::cout<<std::endl<<std::endl;
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Test: Simple polynomial test."<<std::endl;
    SimplePolynomial<double> polinom(3, 2);
    polinom.print("f(x):");
    std::cout<<"f(2):"<<polinom(2)<<std::endl;

    Point<double> koeffs1(4, 3);
    SimplePolynomial<double> polinom1(koeffs1);
    polinom1.print("f1(x):");
    std::cout<<"f1(3):"<<polinom1(3)<<std::endl;

    double* koeffs2 = new double[4];
    koeffs2[0] = 2; koeffs2[1] = 1.5; koeffs2[2] = -4; koeffs2[3] = 0;
    SimplePolynomial<double> polinom2(4, koeffs2);
    polinom2.print("f2(x):");
    std::cout<<"f2(1.5):"<<polinom2(1.5)<<std::endl;

    SimplePolynomial<double> polinom3(polinom2);
    polinom3.print("f3(x):");
    std::cout<<"f3(1.5):"<<polinom3(1.5)<<std::endl;

    Point<double> point1(2, 2);
    std::cout<<"f3(2,2):"<<polinom3(point1)<<std::endl;

    polinom3.getKoeffs().print("f3.koeffs:");
    std::cout<<"--------------------------"<<std::endl;
}
