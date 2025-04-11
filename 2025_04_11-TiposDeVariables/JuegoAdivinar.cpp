#include <iostream>
void play(void)
int main(void){
    const int NUM = 10;
    int num = -1;
    int intentos = 0;
    const int MIN = 1;
    const int MAX = 100;

    while (num != NUM){
        intentos += 1;
        std::cout << "Adivina un numero entre " << MIN << " y " << MAX <<":\n";
        std::cin >> num;
        
        if (num == 0)
            {
                std::cout << "Te haz rendido";
                break;
            }
        if (MAX >= num and num >= MIN){
            if (num== NUM){
                std::cout << "Le pegaste al numero, era:" << NUM<< "\n";
                break;
            }if (num > NUM) {
                std::cout << "El numero que escribiste es muy grande, un poco mas pequeño.\n";
            } else {
                std::cout << "El numero que escribiste es muy chiquito, te falta.\n";
            }  
        } else {
            std::cout << " El numero esta fuera del rango, se termina el juego.\n";
            continue;
        }
        if (intentos % 10 == 0)
            { std::cout << "Haz hecho "<< intentos << "Si te quieres salir en cualquier momento pon 0: \n";
        }
    }

    return 0;
}
