#include <bits/stdc++.h>
using namespace std;

typedef struct town
{
    long long teleport;
    bool visited;
    long long first_visited;
};

void solve(std::istream &ist, std::ostream &ost)
{
    /* ------- 宣言と入力 ------- */

    long long N, K;
    ist >> N >> K;

    vector<struct town> A;

    for (int i = 0; i < N; i++)
    {
        struct town tmp;
        A.emplace_back(tmp);

        int input;
        ist >> input;

        A.at(i).teleport = input;
        A.at(i).visited = false;
        A.at(i).first_visited = 0;
    }

    /* ------- 計算 ------- */

    long long count = 0;
    long long visiting = 0;

    long long loop_start;
    long long loop_size;

    while (1)
    {
        if (count == K)
        {
            ost << visiting + 1 << endl;
            return;
        }

        if (A.at(visiting).visited)
        {
            loop_start = A.at(visiting).first_visited;
            loop_size = count - A.at(visiting).first_visited;
            break;
            
        }
        A.at(visiting).visited = true;
        A.at(visiting).first_visited = count;
        count++;
        visiting = A.at(visiting).teleport - 1;
    }

    K -= loop_start;
    K %= loop_size;

    for (long long i = 0; i < K; i++)
    {
        visiting = A.at(visiting).teleport - 1;
    }

    ost << visiting + 1 << endl;
}

#ifndef WOMAIN
int main()
{
    solve(std::cin, std::cout);
    return 0;
}
#endif
