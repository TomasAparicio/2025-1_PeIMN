#include <iostream>
#include <cmath>

bool IsPrime (long n);

int main (int argc, char **argv){
    long minimo = std::stoi(argv[1]);
    long maximo = std::stoi(argv[2]);
    long suma = 0;
    bool Prime;


    for (long jj = minimo; jj<=maximo-6; ++jj){
        if (IsPrime(jj) == true and IsPrime(jj+6)==true){
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

