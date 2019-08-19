#include <stdio.h>

int func1(int m, int n);
int func2(int m, int n);
void swap(int *m, int *n);

int func1(int m, int n)
{
    int i = n;
    for (i = n; i > 0; i--)
    {
        if (m % i == 0 && n % i == 0)
        {
            return i;
        }
    }
}

int func2(int m, int n)
{
    int k;
    while (n != 0)
    {
        k = m % n;
        m = n;
        n = k;
    }
}

void swap(int *m, int *n)
{
    int tmp;

    tmp = *m;
    *m = *n;
    *n = tmp;
}

int main()
{
    int x, y, ans;

    printf("Input x and y : ");
    scanf("%d %d", &x, &y);

    if (x < y)
    {
        swap(&x, &y);
    }

    printf("Ans=%d\n", func1(x, y));
    return 0;
}