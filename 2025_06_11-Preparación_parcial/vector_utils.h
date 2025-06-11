#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>


double min_vector(const std::vector<double> & v);
double max_vector(const std::vector<double> & v);
double pnorm_vector(const std::vector<double> & v, int p);
void der_vector(const std::vector<double> & pol, std::vector<double> & der);
void print_vector(const std::vector<double> & v);
int argmin_vector(const std::vector<double> & v);
int argmax_vector(const std::vector<double> & v);
double mean_vector(const std::vector<double> & v);
double percentil_vector(const std::vector<double> & v, int percentil);
void fill_randomly(std::vector<double>& data);