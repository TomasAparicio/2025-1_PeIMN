#include <iostream>
#include <cmath>
#include "integration.h"

double f(double x);

int main(void)
{
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);
    
    double a = -2.0;
    double b =  2.0;

    std::cout << trapezoid(a, b, 10, f) << "\n";
    std::cout << trapezoid(a, b, 1000, f) << "\n";
    std::cout << trapezoid(a, b, 10000000, f) << "\n";

    std::cout << simpson(a, b, 10, f) << "\n";

    std::cout << richardson(a, b, 10, f, trapezoid, 2) << "\n";

    std::cout << richardson(a, b, 10, f, simpson, 4) << "\n";

    std::cout << gauss2(a, b, f) << "\n";

    std::cout << gauss3(a, b, f) << "\n";

    std::cout << gauss5(a, b, f) << "\n";

    std::cout << gauss7(a, b, f) << "\n";


    return 0;
}

double f(double x)
{
    return 7*x*x*x -8*x*x + 3*x + 3;
}