#include <stdio.h>

int x[5] = {5, 4, 3, 2, 1};
int n = sizeof(x) / sizeof(x[0]);

void sort(int m);

int main(void)
{
    sort(n);
    return 0;
}

void sort(int m)
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (int j = m; j > i; j--)
        {
            if (x[j] < x[j - 1])
            {
                int temp = x[j];
                x[j] = x[j - 1];
                x[j - 1] = temp;
            }
        }
    }

    printf("%d: ", m - 1);

    for (int j = 0; j < n; j++)
    {
        printf("%d", x[j]);
    }
    printf("\n");
}
