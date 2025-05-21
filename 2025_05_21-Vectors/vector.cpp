#include <vector>
#include <iostream>
#include <string>

double average(const std::vector<double> & x);
std::vector<double> data(int N);

int main(int argc , char **argv)
{

    // read the size from the command line
    const int N = std::stoi(argv[1]); 

    // compute the average
    std::cout << "Calculando promedio ...\n";
    double avg = average(data(N));
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    std::cout << avg << "\n";

    return 0;
}

double average(const std::vector<double> & x)
{
    double suma = 0.0;
    for(int ii = 0; ii < x.size(); ii++) {
        suma = suma + x[ii];
    }
    return suma/x.size();
}


std::vector<double> data(int N){
    // declare the vectorS
    std::vector<double> X;

        // resize the vector
    X.resize(N, 0);

    for(int ii = 0; ii < N; ii++) {
        X[ii] = ii;
    }
    return X;
}