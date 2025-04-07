#include <iostream>

using std::cout, std::endl;

double quadratic(double x)
{
    double a = 1, b = -2, c = 2, y;
    y = a * x * x + b * x + c;
    return y;
}
double linear(double x)
{
    double a = 2, b = -2, y;
    y = a * x + b;
    return y;
}

double newton(double x, double (*f)(double), double (*df)(double))
{
    double tolerance = 0.000000001;
    int max_iter = 10, iter = 0;
    while (f(x) * f(x) > tolerance)
    {
        if (df(x) != 0)
            x = x - f(x) / df(x);
        else
        {
            x += tolerance;
        }
        iter++;
        if (iter > max_iter)
        {
            cout << "Max iteration occurred!" << endl;
            break;
        }
    }
    return x;
}

int main()
{
    double (*f)(double);
    f = quadratic;
    double (*df)(double);
    df = linear;
    double root1 = newton(0, f, df);
    double root2 = newton(10, f, df);
    cout << root1 << endl
         << root2 << endl;
    return 0;
}