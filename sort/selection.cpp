#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int suretsu[] = {1, 7, 8, 5, 3, 9, 6, 4, 2};
    int N = sizeof(suretsu) / sizeof(suretsu[0]);

    /* ---------------------------------------------------- */

    for (int i = 0; i < N; i++)
    {
        /* 最小値を探す */
        int min = suretsu[i];
        int jmin = i;

        for (int j = i; j < N; j++)
        {
            if (suretsu[j] < min)
            {
                min = suretsu[j];
                jmin = j;
            }
        }

        /* 数列を詰める */
        for (int j = jmin; j > i; j--)
        {
            suretsu[j] = suretsu[j - 1];
        }

        /* 最小値を挿入 */
        suretsu[i] = min;
    }

    /* ---------------------------------------------------- */

    for (int i = 0; i < N; i++)
    {
        cout << suretsu[i] << " ";
    }

    cout << endl;

    return 0;
}