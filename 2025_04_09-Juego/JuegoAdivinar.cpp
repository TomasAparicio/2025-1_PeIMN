#include <iostream>

int main(void){
    const int NUM = 10;
    int num = -1;

    while (num != NUM){
        std::cout << "Adivina un numero entre 1 y 100:\n";
        std::cin >> num;
        
        if (num > NUM) {
            std::cout << "El numero que escribiste es muy grande, un poco mas pequeño.\n";
        } else {
            std::cout << "El numero que escribiste es muy chiquito, te falta.\n";}
    }
    std::cout << "Ganaste, el numero era: " <<NUM <<"\n";
    return 0;
}
