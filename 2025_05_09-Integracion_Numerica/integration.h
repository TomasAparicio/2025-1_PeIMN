#pragma once
#include <cmath>
#include <functional>

using fptr = std::function<double(double)>;

double trapezoid (double a, double b, int steps, fptr f);
double simpson (double a, double b, int steps, fptr f);