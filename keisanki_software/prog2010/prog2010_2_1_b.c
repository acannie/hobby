#include <stdio.h>

int func1(int n)
{
    int c;
    if (n == 0)
    {
        c = 1;
    }
    else if (n == 1)
    {
        c = 1;
    }
    else
    {
        c = func1(n - 1) + func1(n - 2);
    }
    printf("%d : %d\n", n, c);
    return c;
}

int main(void)
{
    func1(4);
    return 0;
}