#include <iostream>

int main ()
{
    for (int ii = 1; ii <= 10; ++ii){
        for (int jj = 1; jj <= 10; ++jj){
            (jj<=10-ii) ? std::cout << " " : std::cout << "*";
        }
        std::cout << "\n";
    }
    
}
