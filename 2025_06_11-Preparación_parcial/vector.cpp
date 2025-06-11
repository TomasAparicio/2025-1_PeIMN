#include "vector_utils.h"

int main(){
    std::vector<double> v (5,0);
    std::vector<double> der (4,0);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v[4] = 5;
    der_vector(v, der);

    std::cout << min_vector(v) << " id: " << argmin_vector(v) << "\n"
        << max_vector(v) << " id: " << argmax_vector(v) << "\n"
        << pnorm_vector(v,2) << "\n"
        << pnorm_vector(v,3) << std::endl;

    print_vector(v);
    print_vector(der);
}