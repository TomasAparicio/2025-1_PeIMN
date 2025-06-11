#include "matrix_utils.h"
void print_matrix(const std::vector<double> & M, int nrows, int ncols){
    std::cout.setf(std::ios::scientific);
    std::cout.precision(15);

    for (int ii = 0; ii < nrows; ++ii) {
        for (int jj = 0; jj < ncols; ++jj) {
            std::cout << M[ii*ncols + jj] << " "; // (ii, jj) = ii*NCOLS + jj
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void fill_matrix_random(std::vector<double> & M, const int nrows, const int ncols, const int seed){
    std::mt19937 gen(seed);
    std::uniform_real_distribution<> dis(-1, 1);
    for (int ii = 0; ii < nrows; ii++){
        for (int jj = 0; jj < ncols; jj++){
            M[ii*ncols + jj] = dis(gen);
        }
    }
}

void multiplication_matrix(int n_col_A, int n_row_A, const std::vector<double> & A,int n_col_B, int n_row_B,
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

double trace_matrix(int n_col_A, int n_row_A, const std::vector<double> & A){
    if ((n_col_A != n_row_A) or (n_col_A*n_row_A != A.size())){
        std::cerr << "Tamaños equivocados";
        return 0.0;
    }

    double sum = 0.0;
    for (int i=0; i<n_row_A; i++){
        sum += A[i*n_col_A + i];
    }

    return sum;
}

void transpose_matrix(int n_col_A, int n_row_A, const std::vector<double> & A, std::vector<double> & B){
    if ((n_col_A*n_row_A) != A.size()){
        std::cerr << "Tamaños equivocados";
        return;
    }
    B.resize(A.size());
    for (int ii = 0; ii < n_row_A; ii++){
        for(int jj = 0; jj < n_col_A; jj++){
            B[ii+jj*n_row_A] = A[jj + ii*n_col_A];
        }
    }
    return;
}

void elevate_matrix(int n, const std::vector<double> & A, std::vector<double> & B, int exp){
    if ((n*n) != A.size()){
        std::cerr << "Tamaños equivocados";
        return;
    }
    if (exp == 0) {
        B.assign(n * n, 0.0);
        for (int i = 0; i < n; ++i) {
            B[i * n + i] = 1.0;
        }
        return;
    }

    B = A;
    std::vector<double> C (n*n, 0);

    for (int i= 1; i< exp; i++){
        multiplication_matrix(n, n, A, n, n, B, C);
        B = C;
    }
    return;
}

bool norm_less_than_matrix(const std::vector<double> & A, double epsilon){
    for (auto x:A){
        if (x>epsilon or x < -epsilon){
            return false;
        }
    }
    return true;
}

bool check_inverse(int n,const std::vector<double> & A,const std::vector<double> & B, double epsilon){
    std::vector<double> C (n*n);
    multiplication_matrix(n, n, A, n, n, B, C);
    for (int i=0; i<n; i++){
        C[i*n+i] -= 1.0;
    }
    bool order_one = norm_less_than_matrix(C,epsilon);

    multiplication_matrix(n, n, B, n, n, A, C);
    for (int i=0; i<n; i++){
        C[i*n+i] -= 1.0;
    }
    bool order_two = norm_less_than_matrix(C,epsilon);

    return order_one and order_two;
}

void fill_matrix_hilbert(int row, int col, std::vector<double> & A){
    for (int ii=0; ii < row; ii++){
        for(int jj=0; jj < col; jj++){
            A[jj + ii*col] = 1.0/(1.0+ii+jj);
        }
    }
    return;
}

bool check_idempotent_matrix(int n, int exp, double epsilon, const std::vector<double> & A){
    std::vector<double> B (n*n);

    elevate_matrix(n, A, B, exp);

    for (int ii=0; ii<n; ii++){
        for (int jj=0; jj<n; jj++){
            B[jj + ii*n] -= A[jj + ii*n];
        }
    }

    return norm_less_than_matrix(B, epsilon);
}

bool check_orthogonal_matrix(int n,const std::vector<double> & A, double epsilon){
    std::vector<double> T (n*n);
    transpose_matrix(n, n, A, T);

    return check_inverse(n,A,T,epsilon);
}

bool check_commute_matrix(int n, const std::vector<double> & A, const std::vector<double> & B, double epsilon){
    std::vector<double> AB (n*n, 0);
    std::vector<double> BA (n*n, 0);

    multiplitation_matrix(n,n,A,n,n,B,AB);
    multiplitation_matrix(n,n,B,n,n,A,BA);

    for (int i=0; i < n; i++){
        for(int j=0; j<n; j++){
        AB[i*n + j] -= BA[i*n + j];
        }
    }

    return norm_less_than_matrix(AB, epsilon);
}

bool is_hermitian_matrix(int n, const std::vector<std::complex<double>>& A, double epsilon) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::complex<double> a_ij = A[i * n + j];
            std::complex<double> a_ji_conj = std::conj(A[j * n + i]);

            if (std::abs(a_ij - a_ji_conj) > epsilon) {
                return false;
            }
        }
    }
    return true;
}

void multiplication_matrix_complex (int n_col_A, int n_row_A, std::vector<std::complex<double>> & A,int n_col_B, int n_row_B,
     std::vector<std::complex<double>> & B, std::vector<std::complex<double>> & R){
    if (n_col_A != n_row_B){
        std::cerr << "Tamaños equivocados al multiplicar matrices";
        return;
    }
    R.resize(n_row_A * n_col_B);
    for (int ii = 0; ii < n_row_A; ii++){
        for (int jj = 0; jj < n_col_B; jj++){
            std::complex<double> sum = 0.0;
            for (int k = 0; k < n_col_A; k++){
                sum += A[n_col_A*ii + k]*B[n_col_B*k +jj];
            }
            R[n_col_B*ii + jj] = sum;
        }
    }
    return;
}

void transpose_matrix(int n_col_A, int n_row_A,const std::vector<std::complex<double>> & A, std::vector<std::complex<double>> & B){
    if ((n_col_A*n_row_A) != A.size()){
        std::cerr << "Tamaños equivocados";
        return;
    }
    B.resize(A.size());
    for (int ii = 0; ii < n_row_A; ii++){
        for(int jj = 0; jj < n_col_A; jj++){
            B[ii+jj*n_row_A] = std::conj(A[jj + ii*n_col_A]);
        }
    }
    return;
}

void add_matrices(int n, const std::vector<double>& A, const std::vector<double>& B, std::vector<double>& R) {
    R.resize(n * n);
    for (int i = 0; i < n * n; ++i) {
        R[i] = A[i] + B[i];
    }
}

void scalar_multiply_matrix(int n, double scalar, const std::vector<double>& A, std::vector<double>& R) {
    R.resize(n * n);
    for (int i = 0; i < n * n; ++i) {
        R[i] = scalar * A[i];
    }
}

void evaluate_polynomial_on_matrix(int n, const std::vector<double>& A, const std::vector<double>& coeffs, std::vector<double>& result) {
    int degree = coeffs.size() - 1;
    result.assign(n * n, 0.0);

    std::vector<double> term(n * n);      // para A^i
    std::vector<double> scaled(n * n);    // para c_i * A^i
    std::vector<double> temp(n * n);      // suma acumulada

    for (int i = 0; i <= degree; ++i) {
        elevate_matrix(n, A, term, i); // calcula A^i
        scalar_multiply_matrix(n, coeffs[i], term, scaled); // c_i * A^i
        add_matrices(n, result, scaled, temp); // suma acumulada
        result = temp; // actualiza resultado
    }
}