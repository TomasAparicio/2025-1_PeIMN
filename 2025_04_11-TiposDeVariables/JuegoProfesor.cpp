/*
Juego de adivinar un numero

Tener un numero
Preguntar al usuario el numero
Informar si lo adivino o no

*/

#include <iostream>
#include <random>

// declaration
void play(int min_val, int max_val);


int main(void) {
    play(1, 100);

    return 0;
}

// Implemetation
void play(int min_val, int max_val)
{
    const int NUM = min_val+ std::rand() % 100;
    std::cout << NUM
    int guessed_number = NUM/2;

    const int MIN = 1;
    const int MAX = 100;

    while(guessed_number != NUM) {
        std::cout << "Adivina un numero entre " << MIN << "  y " << MAX << ":\n";
        std::cin >> guessed_number;
        std::cout << "Ecribiste: " << guessed_number << "\n";

        // validacion del rango 
        if (guessed_number < MIN or MAX < guessed_number) {
            std::cout << "El numero no esta en el rango.\n";
            continue; 
        }

        if (guessed_number == NUM) {
            std::cout << "GANASTE!!!!\n";
            break;
        } else if (guessed_number > NUM){
            std::cout << "Te pasaste.\n";
        } else { // es menor
            std::cout << "Te falta.\n";
        }
    }

}