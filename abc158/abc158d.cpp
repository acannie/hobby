#include <bits/stdc++.h>
using namespace std;

typedef struct TFC
{
    int T;
    int F;
    string C;
};

int main()
{
    /* ------- 宣言と入力 ------- */

    string S;
    int Q;

    cin >> S;
    cin >> Q;

    struct TFC Q_uery[Q];

    for (int i = 0; i < Q; i++)
    {
        cin >> Q_uery[i].T;
        if (Q_uery[i].T == 2)
        {
            cin >> Q_uery[i].F;
            cin >> Q_uery[i].C;
        }
    }

    /* ------- 計算 ------- */

    bool mode = true;

    for (int i = 0; i < Q; i++)
    {
        if (Q_uery[i].T == 1)
        {
            mode != mode;
        }
        else
        {
            if (Q_uery[i].F == 1 && mode == true)
            {
                S = Q_uery[i].C + S;
            }
            else if (Q_uery[i].F == 1 && mode == false)
            {
                S = S + Q_uery[i].C;
            }
            else if (Q_uery[i].F == 2 && mode == true)
            {
                S = S + Q_uery[i].C;
            }
            else if (Q_uery[i].F == 2 && mode == false)
            {
                S = Q_uery[i].C + S;
            }
        }
    }

    if (mode == true)
    {
        cout << S << endl;
    }
    else
    {
        int len = S.length();
        for (int i = 0; i < len; i++)
        {
            cout << S[len - 1 - i];
        }
        cout << endl;
    }

    return 0;
}