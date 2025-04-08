#include <iostream>
#include <string>

int main(void){
    std::string nombre;

    
    std::cout << "Hola, ¿Cual es tu nombre?\n";
    std::cin >> nombre;

    std::cout << "\n Hola, " << nombre << "\n";

    return 0;
}