#include <iostream>
#include <cmath>

bool IsPrime (long n);

int main (void){
    long minimo = 300;
    long maximo = 400;
    long suma = 0;
    bool Prime;


    for (long jj = minimo; jj<=maximo-4; ++jj){
        if (IsPrime(jj) == true and IsPrime(jj+4)==true){
            std::cout << jj << " y " << jj+4 << " son primos primos\n";
        }
    }

    return 0;
}

bool IsPrime (long n){
    for (long ii = 2; ii < n; ++ii){
        if (n % ii == 0){
            return false; //Si tiene divisores retorna falso
        }
    }
    return true;
}

