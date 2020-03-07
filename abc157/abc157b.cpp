#include <bits/stdc++.h>
using namespace std;

bool judge(vector<vector<bool>> bingo)
{
    for (int i = 0; i < 3; i++)
    {
        if (bingo[i][0] && bingo[i][1] && bingo[i][2])
        {
            return true;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (bingo[0][i] && bingo[1][i] && bingo[2][i])
        {
            return true;
        }
    }

    if (bingo[0][0] && bingo[1][1] && bingo[2][2])
    {
        return true;
    }

    if (bingo[0][2] && bingo[1][1] && bingo[2][0])
    {
        return true;
    }

    return false;
}

int main()
{
    /* ------- 宣言と入力 ------- */

    vector<vector<int>> A(3, vector<int>(3));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> A[i][j];
        }
    }

    int N;

    cin >> N;

    unordered_set<int> b;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        b.insert(tmp);
    }

    /* ------- 計算 ------- */

    vector<vector<bool>> bingo(3, vector<bool>(3));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (b.find(A[i][j]) != b.end())
            {
                bingo[i][j] = true;
            }
        }
    }

    string ans = "No";

    if (judge(bingo))
    {
        ans = "Yes";
    }

    // for (int i = 0; i < 3; i++)
    // {
    //     if (bingo[i][0] && bingo[i][1] && bingo[i][2])
    //     {
    //         ans = "Yes";
    //     }
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     if (bingo[0][i] && bingo[1][i] && bingo[2][i])
    //     {
    //         ans = "Yes";
    //     }
    // }

    // if (bingo[0][0] && bingo[1][1] && bingo[2][2])
    // {
    //     ans = "Yes";
    // }

    // if (bingo[0][2] && bingo[1][1] && bingo[2][0])
    // {
    //     ans = "Yes";
    // }

    cout << ans << endl;

    return 0;
}