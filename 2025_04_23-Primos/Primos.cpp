#include <iostream>
#include <cmath>

bool IsPrime (long n);

int main (void){
    long N=0;
    bool Prime;
    while (N<2){
    std::cout << "\nPon el entero mayor a 1 que quieres comprobar si es primo: ";
    std::cin >> N;
    }
    Prime = IsPrime(N);
    if (Prime == true){
        std::cout << "El numero " << N << " es primo\n";
    }else {
        std::cout << "El numero " << N << " no es primo.\n";
    }

    return 0;
}

bool IsPrime (long n){
    for (int ii = 2; ii <= std::sqrt(n)+1; ++ii){
        if (n % ii == 0){
            return false;
        }
    }
    return true;
}

