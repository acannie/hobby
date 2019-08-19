#include <stdio.h>

int x[5] = {5, 1, 4, 3, 2};
int n = sizeof(x) / sizeof(x[0]);

void sort(int m);

int main(void)
{
    sort(n);
    return 0;
}

void sort(int m)
{
    int i, j, temp;

    if (m > 1)
    {
        sort(m - 1);
        temp = x[m - 1];
        i = m - 2;

        while (x[i] > temp)
        {
            x[i + 1] = x[i];
            i--;
        }

        x[i + 1] = temp;
        printf("%d: ", m - 1);

        for (int j = 0; j < n; j++)
        {
            printf("%d", x[j]);
        }
        printf("\n");
    }
}