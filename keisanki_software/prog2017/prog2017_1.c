#include <stdio.h>
#define N 4

double func1(double, double *, int);
//double func2(double, double *, int);

int main(void)
{
    int i;
    double a[N + 1], x = 2.0;

    for (i = 0; i < N + 1; i++)
    {
        a[i] = (double)i + 1.0;
    }

    printf("f(%.1f)=%.2f\n", x, func1(x, a, N));
    return 0;
}

double func1(double x, double a[], int n)
{
    int i, j;
    double f = 0.0, g;

    for (i = 0; i <= n; i++)
    {
        g = a[i];
        for (j = 0; j < i; j++)
        {
            g *= x; //乗算演算
        }
        f += g; //加算演算
    }
    return f;
}

/*
double func2(double x, double a[], int k)
{
    if (k == N)
    {
        return a[N];
    }
    else
    {
        return func2(x, a, N - k + 1) * x + a[N - k];
    }
}
*/