#include <bits/stdc++.h>
using namespace std;

void solve(std::istream &ist, std::ostream &ost)
{
    /* ------- 宣言と入力 ------- */

    long long A, B, C, K;
    ist >> A >> B >> C >> K;

    /* ------- 計算 ------- */

    if (K <= A)
    {
        ost << K << endl;
        return;
    }

    if (K <= A + B)
    {
        ost << A << endl;
        return;
    }

    C = K - (A + B);
    ost << A - C << endl;
}

#ifndef WOMAIN
int main()
{
    solve(std::cin, std::cout);
    return 0;
}
#endif
