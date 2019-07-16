#include <stdio.h>

int func2(int m, int n)
{
    int k = m % n;

    if (k != 0)
    {
        func2(n, k);
    }
    else
    {
        return n;
    }
}

int main(void)
{
    printf("%d\n", func2(20, 15));
}