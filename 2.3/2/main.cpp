#include <iostream>
#include <float.h>

double f(double x)
{
    return log(x) - 1;
}
double bisection(double a, double b, double eps)
{
    double fa = f(a);
    while (107)
    {
        double x = (a + b) / 2;
        if ((abs(x - a) < eps) || (abs(x - b) < eps))
            return x;
        else if (f(x) * fa > 0)
            a = x;
        else
            b = x;
    }
}
int main()
{
    double eps = 1e-4;
    std::cout << bisection(0, DBL_MAX, eps);
}
