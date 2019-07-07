#include <stdio.h>
#include <math.h>

//nを素因数分解しfactor[100]にまとめる関数
void factorization(int n, int factor[100])
{
    int nn = n;
    int i;
    int j = 0;

    for (i = 2; i <= n; i++)
    {
        while (nn % i == 0)
        {
            factor[j] = i;
            j++;
            nn = nn / i;
        }
    }
}

//素因数の個数を数える関数
int countfactor(int n)
{
    int nn = n;
    int i;
    int count = 0;

    for (i = 2; i <= n; i++)
    {
        while (nn % i == 0)
        {
            count++;
            nn = nn / i;
        }
    }
    return count;
}

int main()
{
    int euler;
    int n;
    int nfactor[100];
    int count = 1;

    //配列の初期化
    int i;
    for (i = 0; i < 100; i++)
        nfactor[i] = 0;

    //整数の入力
    printf("Input number. ---> ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Error. Input an enteger greater than 1.\n");
        return 0;
    }
    else if (n == 1)
    {
        euler = 1;
    }
    else if (n >= 2)
    {
        //素因数分解
        factorization(n, nfactor);

        /*
        printf("Factors of %d is ", n);
        
        int j;
        for(j=0; j<countfactor(n); j++){
            printf("%d ", nfactor[j]);
        }
        printf("\n");
        */

        //n以下の一つ一つの整数について互いに素か確かめていく
        int k, l;
        int factor[100][100];

        //配列の初期化
        for (k = 0; k < 100; k++)
            for (l = 0; l < 100; l++)
                factor[k][l] = 0;

        //素因数分解
        for (k = 2; k < n; k++)
            factorization(k, factor[k]);

        int flg[100];
        int iflag;
        for (iflag = 0; iflag < 100; iflag++)
            flg[iflag] = 0;

        /*
        for(k=2; k<n; k++){
            printf("Factor of %d is ", k);
            for(l=0; l<countfactor(k); l++){
                printf("%d ", factor[k][l]);
            }
            printf("\n");
        }
        */

        //素因数を一つ一つ比較し一致すればフラグを立てる
        int ii, jj, kk;
        for (ii = 0; ii < countfactor(n); ii++)
        {
            for (jj = 2; jj < n; jj++)
            {
                for (kk = 0; kk < countfactor(jj); kk++)
                {
                    if (nfactor[ii] == factor[jj][kk])
                    {
                        flg[jj] = 1;
                    }
                }
            }
        }

        //フラグが立っていない整数の個数を数え答えを導く
        int icount;
        for (icount = 0; icount < n; icount++)
        {
            if (flg[icount] == 1)
                count++;
        }
        euler = n - count;
    }

    printf("The Euler's totient of the you inputed is %d.\n", euler);

    return 0;
}
