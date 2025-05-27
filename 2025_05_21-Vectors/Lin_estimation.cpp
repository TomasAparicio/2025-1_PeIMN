#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <numeric>

void fill(std::vector<double> & xdata, std::vector<double> & ydata, const std::string filename);
void lin_estimation(const std::vector<double> & xdata, const std::vector<double> & ydata,
     double & m, double & b, double & d_m, double & d_b);

int main (int argc, char **argv){
    //Crear los vectores que luego llenaremos
    std::vector<double> xdata;
    std::vector<double> ydata;

    //Nombre del archivo
    std::string filename = argv[1];

    //Creando las variables que van a modificarse
    double m;
    double b;
    double d_m;
    double d_b;

    //Constantes fisicas
    const double e = 1.02176634e-19;
    double h_real = 6.62607015e-34;
    double h_estimated; // h estimado a partir de la pendiente
    double phi;   // Función de trabajo
    

    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);

    //Llenar vector y su linealización
    fill(xdata , ydata , filename);
    lin_estimation(xdata , ydata , m , b , d_m , d_b);

    //resultados esperimentales
    h_estimated = m * e;
    phi = -b * e;

    std::ofstream file("Regresión lineal");

    file << h_estimated << " "
            << phi << " "
            << m << " "
            << b << " "
            << d_m << " "
            << d_b << " "
            << std::endl;
}

void fill(std::vector<double> & xdata, std::vector<double> & ydata, const std::string filename){
    std::ifstream fin(filename);

    if (!fin.is_open()) std::cerr << "Error: no se pudo abrir el archivo " << filename << std::endl; //Lanzar error si no abre

    double x, y;  // Declarar las variables para leer los datos

    while(fin >> x >> y){
        xdata.push_back(x);
        ydata.push_back(y);
    }

    fin.close();  // Cerrar el archivo
}

void lin_estimation(const std::vector<double>& xdata, const std::vector<double>& ydata, 
                   double& m, double& b, double& d_m, double& d_b) {
    const int N = xdata.size();
    
    // Calcular las esperanzas
    double Ex = std::accumulate(xdata.begin(), xdata.end(), 0.0) / N;
    double Ey = std::accumulate(ydata.begin(), ydata.end(), 0.0) / N;
    double Exx = std::inner_product(xdata.begin(), xdata.end(), xdata.begin(), 0.0) / N;
    double Exy = std::inner_product(xdata.begin(), xdata.end(), ydata.begin(), 0.0) / N;
    double Eyy = std::inner_product(ydata.begin(), ydata.end(), ydata.begin(), 0.0) / N;
    
    //Calculo pendiente
    m = (Exy - Ex*Ey) / (Exx - Ex*Ex);
    b = (Exx*Ey - Ex*Exy) / (Exx - Ex*Ex);
        
    // Calcular varianza residual
    double s2 = (N/(N-2.0)) * (Eyy - Ey*Ey - m*m*(Exx - Ex*Ex));
    
    // Calcular errores
    d_m = std::sqrt(s2 / (N * (Exx - Ex*Ex)));
    d_b = d_m * std::sqrt(Exx);
}