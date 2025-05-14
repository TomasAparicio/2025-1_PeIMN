#include "integration.h"

double trapezoid (double a, double b, int steps, fptr f){
    double sum_intermedia = 0;
    double dx = (b-a)/steps;
    for (int n = 1; n<steps;++n){ //suma los x_i con i distinto de 0 y de el numero de pasos
        double x = a + dx * n;
        sum_intermedia += f(x);

    }
    return dx*((f(a)+f(b))/2 + sum_intermedia);
}

double simpson (double a, double b, int steps, fptr f){
    if (steps % 2 == 1) ++steps; //si los steps son impares se les suma 1 para que sean pares
    
    double sum_par = 0;
    double sum_impar = 0;
    double dx = (b-a)/steps;

    for (int n = 1; n<=steps/2; ++n ){ //suma de los x_i pares
        double x = a + dx * (2*n - 1);
        sum_impar += f(x);
    }

    for (int n=1; n<=steps/2-1; ++n){ //suma de los x_i impares
        double x = a + dx *2* n;
        sum_par += f(x);
    }

    return dx/3*(f(a)+f(b)+4*sum_impar+2*sum_par); 
}

double richardson(double a, double b, int steps, fptr f, algtr method, int Order) {
    double I1 = method(a, b, steps, f);        // Aproximación con h
    double I2 = method(a, b, 2 * steps, f);    // Aproximación con h/2

    return (std::pow(2, Order) * I2 - I1) / (std::pow(2, Order) - 1.0);
}

double gauss2 (double a, double b, fptr f){

    double x_0 = -1.0/std::sqrt(3.0);
    double x_1 =  1.0/std::sqrt(3.0);
    double w0  =  1.0;
    double w1  =  1.0;
    double aux1 = (b-a)/2;
    double aux2 = (b+a)/2;
    
    return aux1 * (w0*f(aux1*x_0+aux2) + w1 * f(aux1*x_1+aux2));
}
