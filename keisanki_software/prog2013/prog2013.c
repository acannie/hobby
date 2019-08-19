#include <stdio.h>
#include <stdlib.h>

int pwr1(int x, int y);
int pwr2(int x, int y);

int main()
{
    int x, y;

    printf("Input X and Y : ");
    scanf("%d %d", &x, &y);

    if (y < 0)
    {
        fprintf(stderr, "exponent error!\n");
        exit(0);
    }

    printf("%d^%d=%d", x, y, pwr1(x, y));

    return 0;
}

int pwr1(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }
    else
    {
        return x * pwr1(x, y - 1);
    }
}

int pwr2(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }

    if (y % 2 == 0)
    {
        return pwr2(x * x, y / 2);
    }
    else
    {
        return x * pwr2(x * x, (y - 1) / 2);
    }
}
