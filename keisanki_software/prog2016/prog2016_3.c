#include <stdio.h>

int fib2(int n);

int main()
{
    int n;
    int i;
    n = 10;

    for (i = 1; i < n; i++)
    {
        printf("%d:%d\n", i, fib2(i));
    }
    return 0;
}

int fib2(int n)
{
    int n1, n2, tmp;
    int i;

    n1 = 1;
    n2 = 1;

    for (i = 2; i < n; i++)
    {
        tmp = n2;
        n2 = n1 + n2;
        n1 = tmp;

        /*tmp = n1 + n2;
        n1 = n2;
        n2 = tmp;*/
    }
    return n2;
}