#include "vector_utils.h"

double min_vector(const std::vector<double> & v){
    double min = v[0];
    for (auto x : v){
        if (x < min){
            min = x;
        }
    }
    return min;
}

double max_vector(const std::vector<double> & v){
    double max = v[0];
    for (auto x : v){
        if (x > max){
            max = x;
        }
    }
    return max;
}

double pnorm_vector(const std::vector<double> & v, int p){
    double suma = 0.0;
    for (auto x : v){
        suma += std::pow(std::abs(x),p);
    }
    return pow(suma,1.0/p);
}

void der_vector(const std::vector<double> & pol, std::vector<double> & der){
    der.resize(pol.size()-1, 0);
    for (int i=1; i< pol.size(); i++){
        der[i-1] = pol[i] * i;
    }
    return;
}

void print_vector(const std::vector<double> & v){
    for (auto x : v){
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return;
}

int argmin_vector(const std::vector<double> & v){
    int min = v[0];
    int idmin = 0;
    for (int i = 1; i<v.size() ; i++){
        if (v[i] < min){
            min = v[i];
            idmin = i;
        }
    }
    return idmin;
}

int argmax_vector(const std::vector<double> & v){
    int max = v[0];
    int idmax = 0;
    for (int i = 1; i<v.size() ; i++){
        if (v[i] > max){
            max = v[i];
            idmax = i;
        }
    }
    return idmax;
}

double mean_vector(const std::vector<double> & v){
    double suma = 0.0;
    for (auto x : v){
        suma += x;
    }
    return suma/v.size();
}

double percentil_vector(const std::vector<double> & v, int percentil){
    if (v.empty()){
        std::cout << "No data: function percentil_vector";
        return 0.0;
    }

    double index = (percentil / 100.0) * v.size();
    double lower = static_cast<int>(index);
    double fraction = index - lower;

    if (lower + 1 >= v.size()){
        return v[lower];
    }else return v[lower]*(1.0-fraction) + v[lower + 1]*fraction;
}

void fill_randomly(std::vector<double>& data) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0); // rango: 0.0 a 1.0

    for (auto& x : data) {
        x = dis(gen);
    }
}