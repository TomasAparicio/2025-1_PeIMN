#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <random>
#include <complex>

void print_matrix(const std::vector<double> & M, int nrows, int ncols);
void fill_matrix_random(std::vector<double> & M, const int nrows, const int ncols, const int seed);
void multiplication_matrix(int n_col_A, int n_row_A, const std::vector<double> & A,int n_col_B, int n_row_B,
     const std::vector<double> & B, std::vector<double> & R);
double trace_matrix(int n_col_A, int n_row_A, const std::vector<double> & A);
void transpose_matrix(int n_col_A, int n_row_A, const std::vector<double> & A, std::vector<double> & B);
void elevate_matrix(int n, const std::vector<double> & A, std::vector<double> & B, int exp);
bool norm_less_than_matrix(const std::vector<double> & A, double epsilon);
bool check_inverse(int n,const std::vector<double> & A,const std::vector<double> & B, double epsilon);
void fill_matrix_hilbert(int row, int col, std::vector<double> & A);
bool check_idempotent_matrix(int n, int exp, double epsilon, const std::vector<double> & A);
bool check_orthogonal_matrix(int n,const std::vector<double> & A, double epsilon);
bool check_commute_matrix(int n, const std::vector<double> & A, const std::vector<double> & B, double epsilon);
bool is_hermitian_matrix(int n, const std::vector<std::complex<double>>& A, double epsilon);
void multiplication_matrix_complex (int n_col_A, int n_row_A, std::vector<std::complex<double>> & A,int n_col_B, int n_row_B,
     std::vector<std::complex<double>> & B, std::vector<std::complex<double>> & R);
void transpose_matrix(int n_col_A, int n_row_A,const std::vector<std::complex<double>> & A, std::vector<std::complex<double>> & B);
void add_matrices(int n, const std::vector<double>& A, const std::vector<double>& B, std::vector<double>& R);
void scalar_multiply_matrix(int n, double scalar, const std::vector<double>& A, std::vector<double>& R);
void evaluate_polynomial_on_matrix(int n, const std::vector<double>& A, const std::vector<double>& coeffs, std::vector<double>& result);