#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int suretsu[] = {5, 9, 3, 1, 2, 8, 4, 7, 6};

    int N = sizeof(suretsu) / sizeof(suretsu[0]);

    /* ---------------------------------------------------- */

    for (int i = 1; i < N; i++)
    {
        int target = suretsu[i];

        int small;
        int j_small;

        /* 行き止まりを探す */
        for (int j = i; j >= -1; j--)
        {
            if ((target > suretsu[j]) || (j == -1))
            {
                small = suretsu[j + 1];
                j_small = j + 1;
                break;
            }
        }

        /* 列を詰める */
        for (int j = i; j > j_small; j--)
        {
            suretsu[j] = suretsu[j - 1];
        }

        /* 挿入する */
        suretsu[j_small] = target;
    }

    /* ---------------------------------------------------- */

    for (int i = 0; i < N; i++)
    {
        cout << suretsu[i] << " ";
    }

    cout << endl;

    return 0;
}