#include "../include/SimplePolinom.h"

void TestSimplePolinom() {
    std::cout<<std::endl<<std::endl;
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Test: Simple polinom test."<<std::endl;
    SimplePolinom<double> polinom(3, 2);
    polinom.print("f(x):");
    std::cout<<"f(2):"<<polinom(2)<<std::endl;
    std::cout<<"--------------------------"<<std::endl;
}
