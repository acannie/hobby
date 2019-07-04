#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int suretsu[] = {5, 9, 3, 1, 2, 8, 4, 7, 6};
    int N = sizeof(suretsu) / sizeof(suretsu[0]);

    /* ---------------------------------------------------- */

    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j > i; j--)
        {
            if (suretsu[j - 1] > suretsu[j])
            {
                /* 入れ替え */
                int tmp = suretsu[j - 1];
                suretsu[j - 1] = suretsu[j];
                suretsu[j] = tmp;
            }
        }
    }

    /* ---------------------------------------------------- */

    for (int i = 0; i < N; i++)
    {
        cout << suretsu[i] << " ";
    }

    cout << endl;

    return 0;
}