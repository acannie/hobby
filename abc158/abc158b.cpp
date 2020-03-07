#include <bits/stdc++.h>
using namespace std;

int main()
{
    /* ------- 宣言と入力 ------- */

    long long N, A, B;

    cin >> N >> A >> B;

    /* ------- 計算 ------- */

    long long red, blue;
    long long sum = A + B;

    long long ans = 0;

    ans += N / sum * A;

    if (N % sum < A)
    {
        ans += N % sum;
    }
    else
    {
        ans += A;
    }

    cout << ans << endl;

    return 0;
}