#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> C, vector<vector<int>> A, vector<int> buy, int i)
{
    helper(C, A, buy, i + 1);
    buy.emplace_back(i);
    helper(C, A, buy, i + 1);
}

// void helper(vector<int> C, vector<vector<int>> A, int i, vector<int> point, int &cost, int N, int M, int X)
// {
//     helper(C, A, i + 1, point, cost, N, M, X);

//     for (int j = 0; j < M; j++)
//     {
//         point.at(j) += A.at(i).at(j);
//     }
//     cost += C.at(i);

//     helper(C, A, i + 1, point, cost, N, M, X);
// }

void solve(std::istream &ist, std::ostream &ost)
{
    /* ------- 宣言と入力 ------- */

    int N, M, X;
    ist >> N >> M >> X;

    vector<int> C;
    vector<vector<int>> A;

    for (int i = 0; i < N; i++)
    {
        int input_C;
        ist >> input_C;
        C.emplace_back(input_C);

        A.emplace_back(0);
        for (int j = 0; j < M; j++)
        {
            int input_A;
            ist >> input_A;
            A.at(i).emplace_back(input_A);
        }
    }

    /* ------- 計算 ------- */

    int min_price = 0;
    vector<int> point;
    for (int i = 0; i < M; i++)
    {
        point.emplace_back(0);
    }

    helper(min_price, point, C, A, N, M, X);

    //ost << ans << endl;
}

#ifndef WOMAIN
int main()
{
    solve(std::cin, std::cout);
    return 0;
}
#endif
