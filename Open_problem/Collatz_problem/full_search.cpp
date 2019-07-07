/* コラッツの問題 */

/* 「nが偶数の場合、nを2で割る」、
「nが奇数の場合、nに3をかけて1を足す」
という操作を繰り返す。
nがどんな自然数であっても必ず1に到達する。 */

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    for (int i = 1; i < 100000; i++)
    {
        int num = i;
        while (num != 1)
        {
            if ((num % 2) == 0)
            {
                num = num / 2;
            }
            else
            {
                num = 3 * num + 1;
            }
        }

        cout << i << " is OK!" << endl;
    }

    return 0;
}