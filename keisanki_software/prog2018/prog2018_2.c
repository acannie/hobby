#include <stdio.h>

double func1(double x[], int n)
{
    int i;
    double a = 0.0;
    for (i = 0; i < n; i++)
    {
        a += x[i];
    }
    return a;
}

double func2(double x[], double a, int n)
{
    int i;
    double b = 0.0;
    for (i = 0; i < n; i++)
    {
        // b += (x[i] - a) * (x[i] - a);
        b += x[i] * x[i];
    }

    // return b / (double)n;
    // return (b - 2 * a * func1(x, n) + n * a * a) / (double)n;
    return b / (double)n - a * a;
}

double func3(double x[], int n)
{
    if (n == 1)
    {
        return x[0];
    }
    else
    {
        return func2(x, n - 1, x[n - 1]);
    }
}

int main()
{
    double x[] = {4.1, 6.4, 4.3, 6.8, 3.4};
    double a = 0.0;
    int n = sizeof(x) / sizeof(x[0]);

    a = func1(x, n) / (double)n;
    // a = func3(x, n) / (double)n;

    printf("%.2f\n", func2(x, a, n));
    return 0;
}