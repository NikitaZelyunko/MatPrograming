#include "../include/Point.h"

void TestPoint() {
    cout<<endl<<endl;
    cout<<"--------------"<<endl;
    cout<<"TEST POINT LIB"<<endl;
    Point<double> a = Point<double>(1);
    Point<double> b = Point<double>(2);
    Point<double> c = Point<double>(2, -2);
    Point<double> d = Point<double>(2, 0.0);
    double *coeffs1 = createOneDimArray(3);
    for(int i = 0; i < 3; i++) {
        coeffs1[i] = i;
    }
    Point<double> e = Point<double>(3, coeffs1);

    a.print("a:");
    b.print("b:");
    c.print("c:");
    d.print("d:");
    e.print("e:");

    a[0] = -1;

    b[0] = 6;
    b[1] = -7;
    b[3] = 44;
    a.print("a:");
    b.print("b:");
    cout<<"--------------"<<endl;
}
