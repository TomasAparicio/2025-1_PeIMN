#include <iostream>
#include <fstream>
#include "integration.h"

double f(double x);

int main (void){
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);

    std::cout << simpson(0.0, 1.0, 10, f) << "\n";
    return 0;
}

double f(double x)
{
   return x*x; //x²
}