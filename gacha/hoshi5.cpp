//100回の単発ガチャで星5が1体出る確率

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double kakuritsu = 1.000000;

    for (int i = 0; i < 99; i++)
    {
        kakuritsu *= ((double)99) / 100;
    }

    for (int i = 0; i < 1; i++)
    {
        kakuritsu *= ((double)1) / 100;
    }

    kakuritsu = kakuritsu * 100;

    kakuritsu = kakuritsu * 100;

    cout << kakuritsu << "%" << endl;
}