#include <stdio.h>

#define N 2

struct complex
{
    double re;
    double im;
};
typedef struct complex _Comp;

void multi(int x, _Comp a[][N], _Comp b[][N], _Comp c[][N])
{
    int i, j, k;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            for (int k = 0; k < x; k++)
            {
                c[i][k].re += a[i][j].re * b[j][k].re - a[i][j].im * b[j][k].im;
                c[i][k].im += a[i][j].re * b[j][k].im + a[i][j].im * b[j][k].re; //（ア）
            }
        }
    }
}

void swap_complex(_Comp *a, _Comp *b)
{
    _Comp temp;
    temp = *a; //（イ）
    *a = *b; //（ウ）
    *b = temp; //（エ）
}

int main(void)
{
    int i, j;

    _Comp *p;
    _Comp mat1[][N] = {{{2.0, 1.0}, {1.0, 3.0}}, {{3.0, 1.0}, {2.0, 3.0}}};
    _Comp mat2[][N] = {{{3.0, 1.0}, {2.0, 2.0}}, {{0.0, 2.0}, {1.0, 0.0}}};
    _Comp seki[][N] = {{{0.0, 0.0}, {0.0, 0.0}}, {{0.0, 0.0}, {0.0, 0.0}}};

    p = &mat1[0][0];

    printf("%p, %d, %p\n", p, sizeof(mat1[0][0]), &mat1[0][1]);
    printf("%p\n", p + 3);

    for (i = 0; i < N * N; i++)
    {
        printf("%4.1lf+%4.1lfi\n", (*(p + i)).re, (*(p + i + 1 / 2)).im); //（オ）
    }

    multi(N, mat1, mat2, seki);

    printf("%4.1lf+%4.1lfi\n", seki[1][1].re, seki[1][1].im);

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            swap_complex(&mat1[i][j], &mat2[i][j]); //（カ）
        }
    }

    return 0;
}