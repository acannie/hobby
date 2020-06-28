#include <bits/stdc++.h>
using namespace std;

void solve(std::istream& ist, std::ostream& ost)
{
    /* ------- 宣言と入力 ------- */

    int N;
    ist >> N;

    vector<int> a;

    for(int i = 0; i < N; i++)
    {
        int input;
        ist >> input;
        a.emplace_back(input);
    }

    /* ------- 計算 ------- */

    //ost << ans << endl;

}

#ifndef WOMAIN
int main()
{
    solve(std::cin, std::cout);
    return 0;
}
#endif
