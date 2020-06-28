#include <bits/stdc++.h>
using namespace std;

void solve(std::istream &ist, std::ostream &ost)
{
    /* ------- 宣言と入力 ------- */

    string S, T;
    ist >> S >> T;

    /* ------- 計算 ------- */

    bool ans = true;

    if (S.length() + 1 != T.length())
    {
        ans = false;
    }

    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] != T[i])
        {
            ans = false;
        }
    }

    if (ans)
    {
        ost << "Yes" << endl;
        return;
    }
    ost << "No" << endl;
}

#ifndef WOMAIN
int main()
{
    solve(std::cin, std::cout);
    return 0;
}
#endif
