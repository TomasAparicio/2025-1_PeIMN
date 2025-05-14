#include <iostream>
#include <fstream>
#include "integration.h"

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