#pragma once
#include <cmath>
#include <functional>

using fptr = std::function<double(double)>;

double trapezoid (double a, double b, int steps, fptr f);
double simpson (double a, double b, int steps, fptr f);

using algtr = std::function <double(double, double, int, fptr f)>;

double richardson(double a, double b, int steps, fptr f, algtr method, int Order);

double gauss2 (double a, double b, fptr f);