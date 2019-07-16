#include <stdio.h>

int main()
{
    int a[] = {1, 2, 3, 4, 6, 9, 12, 18, 36};
    int n = sizeof(a) / sizeof(a[0]);

    int s = a[0];

    int x = 4;

    int i;
    for (i = 1; i <= n; i++)
    {
        s = s * x + a[i];
    }

    printf("%d\n", s);

    return 0;
}