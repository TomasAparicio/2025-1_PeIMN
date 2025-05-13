#include "integration.h"

double trapezoid (double a, double b, int steps, fptr f){
    double sum_intermedia = 0;
    double dx = (b-a)/steps;
    for (int n = 1; n<steps;++n){
        double x = a + dx * n;
        sum_intermedia += f(x);

    }
    return dx*((f(a)+f(b))/2 + sum_intermedia);
}

double simpson (double a, double b, int steps, fptr f){
    double sum_par = 0;
    double sum_impar = 0;
    double dx = (b-a)/steps;

    for (int n = 1; n<=steps/2; ++n ){
        double x = a + dx * (2*n - 1);
        sum_impar += f(x);
    }

    for (int n=1; n<=steps/2-1; ++n){
        double x = a + dx *2* n;
        sum_par += f(x);
    }

    return dx/3*(f(a)+f(b)+4*sum_impar+2*sum_par);
}

