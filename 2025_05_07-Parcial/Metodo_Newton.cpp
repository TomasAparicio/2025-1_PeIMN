#include <iostream>
#include <cmath>
#include <functional>
#include <fstream>

using fptr = std::function<double(double)>;

double central_diff(double x, double h, fptr f);
double steady_value(double x, int h);

double f(double x);

int main(void){
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);
    
    double x = 7.0;
    double exact_result = 6.41560366145456;
    
    std::ofstream file("err_vs_h.txt");
    for (int N = 1; N <=8; ++N){
        double x_sug = steady_value(x, N);
        double err = std::abs(1- x_sug/exact_result);
        file << N << " "
                << x_sug << " "
                << err << " "
                << std::endl;

    }
    file.close();
    return 0;
}

double f(double x)
{
   return 20.0-2.5*x-0.015*x*x*x; // 20-2.5x-0.015x³ 
}

double central_diff(double x, double h, fptr f){
    return (f(x+h)-f(x-h))/(2*h);
};

double steady_value(double x, int N){ 
    double h = 0.001;
    for (int i=1; i<= N; ++i){
        x = x - f(x)/ central_diff(x, h, f);
    }
    return x;
}