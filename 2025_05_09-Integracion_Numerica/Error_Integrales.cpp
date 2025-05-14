#include <cmath>
#include <functional>
#include <iostream>
#include <fstream>

using fptr = std::function<double(double)>;

double trapezoid (double a, double b, int steps, fptr f);
double simpson (double a, double b, int steps, fptr f);

using algtr = std::function <double(double, double, int, fptr f)>;

double richardson(double a, double b, int steps, fptr f, algtr method, int Order);

double f(double x);

int main (void){
    double lim_min = -5.0; // Limite de integracion menor
    double lim_max = 5.0; // limite de integracion mayor
    double steps_min = 2; // pasos minimos
    double steps_max = 2000000; // pasos maximos
    double mult = 1.8; // multiplicador de los pasos en cada iteracion del for

    /*se pone ese multiplicador tan raro para tener suficientes datos,
    no termina en 2000000 pero si en un numero muy cercano
    */

    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);
        
    std::ofstream file("err_vs_N.txt");
    for (int N = steps_min; N <=steps_max; N *= mult){
        //Valores segun cada metodo
        double V_Real = 1.56898093601156;
        double V_Trapecio = trapezoid(lim_min, lim_max, N, f) ;
        double V_Simpson = simpson(lim_min, lim_max, N, f) ;
        double V_r_Trapecio = richardson (lim_min, lim_max, N, f, trapezoid, 2);
        double V_r_Simpson = richardson (lim_min, lim_max, N, f, simpson, 4);

        //Errores relativos asociados a cada metodo
        double Err_Trapecio = std::abs(1-V_Trapecio/V_Real);
        double Err_Simpson = std::abs(1-V_Simpson/V_Real);
        double Err_r_Trapecio = std::abs(1-V_r_Trapecio/V_Real);
        double Err_r_Simpson = std::abs(1-V_r_Simpson/V_Real);

        file << N << " "
                << Err_Trapecio << " "
                << Err_Simpson << " "
                << Err_r_Trapecio << " "
                << Err_r_Simpson << " "
                << std::endl;

        //impresion en consola para que la verificación de datos al calificar sea mas facil
        std::cout << N << " "
          << Err_Trapecio << " "
          << Err_Simpson << " "
          << Err_r_Trapecio << " "
          << Err_r_Simpson << " "
          << std::endl;

    }
    
    file.close();
    return 0;
}

double f(double x)
{
   return std::sin(std::exp(x)); //sin(e^x)
}


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
