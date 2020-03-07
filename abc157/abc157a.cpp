#include <bits/stdc++.h>
using namespace std;

int main()
{
    /* ------- 宣言と入力 ------- */

    int N;

    cin >> N;

    /* ------- 計算 ------- */
    
    //int ans = (int)ceil((double)N/2);
    int ans = (N + 1) / 2;

    cout << ans << endl;

    return 0;
}