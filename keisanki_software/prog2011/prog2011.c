#include <stdio.h>

void downheap(int a[], int leaf, int root)
{
    int i, temp;
    i = root * 2 + 1;

    while (i <= leaf)
    {
        if (i < leaf && a[i] < a[i + 1])
        {
            i++;
        }

        if (a[root] >= a[i])
        {
            break;
        }

        temp = a[root];
        a[root] = a[i];
        a[i] = temp;
        
        root = i;

        i = root * 2 + 1;
    }
}

int main(void)
{
    int array[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    int i, root, leaf = 9;
    root = (leaf - 1) / 2;

    while (root >= 0)
    {
        downheap(array, leaf, root);
        root--;
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d,", array[i]);
    }

    return 0;
}