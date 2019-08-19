#include <stdio.h>

int fib1(int n);

int main()
{
    int n;
    int i;
    n = 10;

    for (i = 1; i < n; i++)
    {
        printf("%d:%d\n", i, fib1(i));
    }
    return 0;
}

int fib1(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fib1(n - 1) + fib1(n - 2);
    }
}