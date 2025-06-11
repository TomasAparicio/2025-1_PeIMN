#include "vector_utils.h"

void fill(std::vector<double> & data, std::string filename);

int main(int argc, char **argv){
    std::string fname = argv[1];
    
    std::vector<double> data;

    fill(data, fname);

    std::cout << "Media" << mean_vector << "\n"
            << "Percentil 25: " << percentil_vector(data, 25) << "\n"
            << "Percentil 50: " << percentil_vector(data, 50) << "\n"
            << "Percentil 75: " << percentil_vector(data, 75) << "\n"
            << "Minimo: " << min_vector(data) << "\n"
            << "Maximo: " << max_vector(data) << std::endl;

    return 0;
}

void fill(std::vector<double> & data, std::string filename){
    std::ifstream fin(filename);

    if (!fin.is_open()) {
    std::cerr << "Error: no se pudo abrir el archivo " << filename << std::endl; //Lanzar error si no abre
    std::cout << "No abrio" << "\n";
    return;
    }
    double x;  // Declarar las variables para leer los datos

    while(fin >> x){
        data.push_back(x);
    }

    fin.close();
}

