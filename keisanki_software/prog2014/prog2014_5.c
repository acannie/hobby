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
    int k;
    for (k = 1; k < m; k++)
    {

        int i;

        for (i = 0; i < n; i++)
        {
            int temp = x[i];
            int j = i;

            while (x[temp] < x[j - 1])
            {
                x[j] = x[j - 1];
                j--;
            }

            x[j] = x[temp];
        }

        printf("%d: ", m - 1);

        for (int j = 0; j < n; j++)
        {
            printf("%d", x[j]);
        }
        printf("\n");
    }
}