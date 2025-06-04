#include <iostream>
#include <vector>
#include <cmath>

void multiplicacion_matrices(int n_col_A, int n_row_A, const std::vector<double> & A,int n_col_B, int n_row_B,
     const std::vector<double> & B, std::vector<double> & R);

int main(int argc, char **argv){

    double vx= std::stod(argv[1]);
    double vy= std::stod(argv[2]);
    double vz= std::stod(argv[3]);
    double thetax= std::stod(argv[4]);
    double thetay= std::stod(argv[5]);
    double thetaz= std::stod(argv[6]);

    //Posicion original
    std::vector<double> posicion(3,0.0);
    posicion[0] = vx;
    posicion[1] = vy;
    posicion[2] = vz;

    // Matriz de rotación X
    std::vector<double> R_x (9,0.0);
    R_x[0] = 1;
    R_x[4] = std::cos(thetax);
    R_x[5] = -std::sin(thetax);
    R_x[7] = std::sin(thetax);
    R_x[8] = std::cos(thetax);

    // Matriz de rotación Y
    std::vector<double> R_y(9, 0.0);
    R_y[0] = std::cos(thetay);
    R_y[2] = std::sin(thetay);
    R_y[4] = 1;
    R_y[6] = -std::sin(thetay);
    R_y[8] = std::cos(thetay);

    // Matriz de rotación Z
    std::vector<double> R_z(9, 0.0);
    R_z[0] = std::cos(thetaz);
    R_z[1] = -std::sin(thetaz);
    R_z[3] = std::sin(thetaz);
    R_z[4] = std::cos(thetaz);
    R_z[8] = 1;

    //vector auxiliar de posicion
    std::vector<double> temp_posicion(3, 0.0);

    //Rotacion en x
    multiplicacion_matrices(3 ,3 ,R_x, 1, 3, posicion, temp_posicion);
    posicion = temp_posicion;

    //Rotacion en y
    multiplicacion_matrices(3 ,3 ,R_y, 1, 3, posicion, temp_posicion);
    posicion = temp_posicion;

    //Rotacion en z
    multiplicacion_matrices(3 ,3 ,R_z, 1, 3, posicion, temp_posicion);
    posicion = temp_posicion;

    std::cout << posicion[0] << "   " << posicion[1] << "   " << posicion[2] << "\n";
}

void multiplicacion_matrices(int n_col_A, int n_row_A, const std::vector<double> & A,int n_col_B, int n_row_B,
     const std::vector<double> & B, std::vector<double> & R){
    if (n_col_A != n_row_B){
        std::cerr << "Tamaños equivocados al multiplicar matrices";
        std::cout << "Error al multiplicar las matrices";
    }
    R.resize(n_row_A * n_col_B);
    for (int ii = 0; ii < n_row_A; ii++){
        for (int jj = 0; jj < n_col_B; jj++){
            double sum = 0.0;
            for (int k = 0; k < n_col_A; k++){
                sum += A[n_col_A*ii + k]*B[n_col_B*k +jj];
            }
            R[n_col_B*ii + jj] = sum;
        }
    }
    return;
}