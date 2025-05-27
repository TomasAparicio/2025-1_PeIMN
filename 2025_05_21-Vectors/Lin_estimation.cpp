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
    double m = 0.0;
    double b = 0.0;
    double d_m = 0.0;
    double d_b = 0.0;

    //Constantes fisicas
    const double e = 1.602176634e-19;
    const double h_real = 6.62607015e-34;
    double h_estimated; // h estimado a partir de la pendiente
    double phi;   // Función de trabajo
    

    

    //Llenar vector y su linealización
    fill(xdata , ydata , filename);
    lin_estimation(xdata , ydata , m , b , d_m , d_b);

    //resultados esperimentales
    std::cout << m << e << std::endl;
    h_estimated = m * e;
    phi = -b;
    double err = std::abs(1-h_estimated/h_real);
    double h_error = d_m * e;

    //Crear Archivo
    std::ofstream file("Regresion_lineal.txt");
    file.precision(15);
    file.setf(std::ios::scientific);

    file << h_estimated << " "
            << h_error << " "
            << phi << " "
            << err << " "
            << m << " "
            << b << " "
            << d_m << " "
            << d_b << " "
            << std::endl;

    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);


    //Salida en consola
    std::cout << "h estimado: " << h_estimated << "\n"
                << "h error: " << h_error << "\n"
                << "phi: " << phi << "\n"
                << "err: " << err << "\n"
                << "m: " << m << "\n"
                << "b: " << b << "\n"
                << "d_m: " << d_m << "\n"
                << "d_b: " << d_b 
                << std::endl;

    return 0;
}

void fill(std::vector<double> & xdata, std::vector<double> & ydata, const std::string filename){
    std::ifstream fin(filename);

    if (!fin.is_open()) {
    std::cerr << "Error: no se pudo abrir el archivo " << filename << std::endl; //Lanzar error si no abre
    std::cout << "No abrio" << "\n";
    return;
    }
    double x, y;  // Declarar las variables para leer los datos

    while(fin >> x >> y){
        xdata.push_back(x);
        ydata.push_back(y);
    }


    fin.close();  // Cerrar el archivo

    //std::cout << "Datos cargados:\n";
    //for (size_t i = 0; i < xdata.size(); ++i) {
    //    std::cout << xdata[i] << " " << ydata[i] << "\n";
    //}
    
    return;
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
    
    //std::cout << "Denominador = " << (Exx - Ex*Ex) << "\n";

    //Calculo pendiente
    m = (Exy - Ex*Ey) / (Exx - Ex*Ex);
    b = (Exx*Ey - Ex*Exy) / (Exx - Ex*Ex);
        
    // Calcular varianza residual
    double s2 = (N/(N-2.0)) * (Eyy - Ey*Ey - m*m*(Exx - Ex*Ex));
    
    // Calcular errores
    d_m = std::sqrt(s2 / (N * (Exx - Ex*Ex)));
    d_b = d_m * std::sqrt(Exx);
    return;
}