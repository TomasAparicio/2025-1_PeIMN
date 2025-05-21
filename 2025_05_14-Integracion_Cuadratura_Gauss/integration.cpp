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

    //puntos de evaluacion segun Gauss
    double x_0 = -1.0/std::sqrt(3.0);
    double x_1 =  1.0/std::sqrt(3.0);

    //Pesos
    double w0  =  1.0;
    double w1  =  1.0;

    //aux
    double aux1 = (b-a)/2;
    double aux2 = (b+a)/2;
    
    return aux1 * (w0*f(aux1*x_0+aux2) + w1 * f(aux1*x_1+aux2));
}
double gauss3 (double a, double b, fptr f){
    
    //puntos de evaluacion segun Gauss
    double x_0 = -std::sqrt(0.6);
    double x_1 =  0;
    double x_2 =  std::sqrt(0.6);

    //Pesos
    double w0  =  5.0/9.0;
    double w1  =  8.0/9.0;
    double w2  =  5.0/9.0;

    //aux
    double aux1 = (b-a)/2;
    double aux2 = (b+a)/2;
    
    return aux1 * (w0*f(aux1*x_0+aux2) + w1 * f(aux1*x_1+aux2) +  w2 * f(aux1*x_2+aux2));
}

double gauss5(double a, double b, fptr f){
    // aux
    double aux1 = (b - a)/2.0;
    double aux2 = (b + a)/2.0;

    //define point coordinates
    std::vector<double> x(5);
    x[0] = -1.0/3.0*std::sqrt(5+2*std::sqrt(10.0/7.0));
    x[1] = -1.0/3.0*std::sqrt(5-2*std::sqrt(10.0/7.0));
    x[2] = 0.0;
    x[3] = +1.0/3.0*std::sqrt(5-2*std::sqrt(10.0/7.0));
    x[4] = +1.0/3.0*std::sqrt(5+2*std::sqrt(10.0/7.0));

    //define weights
    std::vector<double> w(5);
    w[0] = (322.0-13.0*std::sqrt(70.0))/900.0;
    w[1] = (322.0+13.0*std::sqrt(70.0))/900.0;
    w[2] = 128.0/225.0;
    w[3] = (322.0+13.0*std::sqrt(70.0))/900.0;
    w[4] = (322.0-13.0*std::sqrt(70.0))/900.0;

    //capture integral
    double result = 0.0;
    for(int k = 0; k < 5; ++k){
        result = result + w[k] * f(aux1 * x[k] + aux2);
    }
    return aux1 * result;
}

double gauss7(double a, double b, fptr f){
    // aux
    double aux1 = (b - a)/2.0;
    double aux2 = (b + a)/2.0;

    //define point coordinates
    std::vector<double> x(7);
    x[0] = -0.949107912342759;
    x[1] = -0.741531185599394;
    x[2] = -0.405845151377397;
    x[3] = 0.0;
    x[4] = 0.405845151377397;
    x[5] = 0.741531185599394;
    x[6] = 0.949107912342759;

    //define weights
    std::vector<double> w(7);
    w[0] = 0.129484966168870;
    w[1] = 0.279705391489277;
    w[2] = 0.381830050505119;
    w[3] = 0.417959183673469;
    w[4] = 0.381830050505119;
    w[5] = 0.279705391489277;
    w[6] = 0.129484966168870;
    

    //capture integral
    double result = 0.0;
    for(int k = 0; k < 7; ++k){
        result = result + w[k] * f(aux1 * x[k] + aux2);
    }
    return aux1 * result;
}