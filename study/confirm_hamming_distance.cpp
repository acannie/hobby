#include <bits/stdc++.h>
using namespace std;

void solve(std::istream &ist, std::ostream &ost)
{

    vector<vector<int>> information;

    for (int i = 0; i < 16; i++)
    {
        information.emplace_back(0);
        int n = i;
        for (int j = 0; j < 4; j++)
        {
            information.at(i).emplace(information.at(i).begin(), n % 2);
            n /= 2;
        }
    }

    vector<vector<int>> G;

    vector<vector<int>> code;

    for()

    vector<vector<int>> G;
    for (int i = 0; i < 16; i++)
    {
        G.emplace_back(0);
    }

    G.at(0) = {0, 0, 0, 0, 0, 0, 0};
    G.at(1) = {0, 0, 0, 0, 0, 0, 0};
    G.at(2) = {0, 0, 0, 0, 0, 0, 0};
    G.at(3) = {0, 0, 0, 0, 0, 0, 0};
    G.at(4) = {0, 0, 0, 0, 0, 0, 0};
    G.at(5) = {0, 0, 0, 0, 0, 0, 0};
    G.at(6) = {0, 0, 0, 0, 0, 0, 0};
    G.at(7) = {0, 0, 0, 0, 0, 0, 0};
    G.at(8) = {0, 0, 0, 0, 0, 0, 0};
    G.at(9) = {0, 0, 0, 0, 0, 0, 0};
    G.at(10) = {0, 0, 0, 0, 0, 0, 0};
    G.at(11) = {0, 0, 0, 0, 0, 0, 0};
    G.at(12) = {0, 0, 0, 0, 0, 0, 0};
    G.at(13) = {0, 0, 0, 0, 0, 0, 0};
    G.at(14) = {0, 0, 0, 0, 0, 0, 0};
    G.at(15) = {0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 16 - 1; i++)
    {
        for (int j = i + 1; j < 16; j++)
        {
            int count = 0;
            for (int c = 0; c < 7; c++)
            {
                if (G.at(i).at(c) != G.at(j).at(c))
                {
                    count++;
                }
            }
            if (count < 3)
            {
                ost << "NG" << endl;
                return;
            }
        }
    }

    ost << "OK" << endl;
}

#ifndef WOMAIN
int main()
{
    solve(std::cin, std::cout);
    return 0;
}
#endif
