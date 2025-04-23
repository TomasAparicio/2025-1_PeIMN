#include <iostream>
#include <cmath>

double pi_aprox(int n);

int main() {
    int N = 20; //Termino hasta el cual se va a aproximar 
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);

    for (int n = 0; n <= N; ++n) {
        double pi_aprox_n = pi_aprox(n);
        double error_relativo = fabs(1.0 - pi_aprox_n / M_PI);
        std::cout << "n = " << n
             << ", pi_aprox(n) = " << pi_aprox_n
             << ", error relativo = " << error_relativo << "\n";
    }

    return 0;
}

double pi_aprox(int n) {
    double suma = 0.0;
    double termino = 0.0;
    for (int k = 0; k <= n; ++k) {
        termino = 1.0 / pow(16.0, k) * (
            4.0 / (8.0 * k + 1.0) - 2.0 / (8.0 * k + 4.0) - 1.0 / (8.0 * k + 5.0) - 1.0 / (8.0 * k + 6.0)
        ); //Calcula el termino k-esimo
        suma += termino; //Suma el termino k-esimo a lo que llevamos acumulado
    }
    return suma;
}