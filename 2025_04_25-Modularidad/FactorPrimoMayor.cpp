#include"prime_utils.h"

int main (int argc, char **argv){
    long N = std::stol(argv[1]);
    if (N<=1){
    std::cerr << "Out of range number: " << n << "\n";
    return 0;
    }
    for (i=2,i<=N,++i){
        while (N % i == 0){
            if (isprime(i)){
                N /= i;
                if (N == 1){
                    std::cout << "El mayor divisor primo es: " << i;
                    return 0;
                }
            }
        }   
    }
}
