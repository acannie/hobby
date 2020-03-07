#include <bits/stdc++.h>
using namespace std;

int main()
{
    /* ------- 宣言と入力 ------- */

    int A, B;

    cin >> A >> B;

    /* ------- 計算 ------- */

    int ans_A = ceil((double)A / 0.08);
    int ans_B = ceil((double)B / 0.1);

    int ans_max = max(ans_A, ans_B);

    double tax_max;
    int judge;

    if (ans_A > ans_B)
    {
        tax_max = 0.1;
        judge = B;
    }
    else
    {
        tax_max = 0.08;
        judge = A;
    }

    int tmp = floor((double)ans_max * tax_max);

    if (floor((double)ans_max * tax_max) == judge)
    {
        cout << max(ans_A, ans_B) << endl;
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;
}