#include <iostream>
#include <cmath>
#include <string>

#define N 15
#define M 8
// int M = ceil((double)N / 2);

#define tate 0
#define yoko 1

using namespace std;

typedef struct
{
    int key[M + 1];
    int count;

    int sum;
    int lack;

    bool done;
} key_informations;

void hyouji(key_informations num[2][N + 1], char value[N + 1][N + 1])
{
    //縦条件を表示
    for (int j = 1; j <= M; j++)
    {
        // 空白を表示
        for (int i = 0; i < M; i++)
        {
            cout << "   ";
        }

        //縦条件を表示
        for (int i = 1; i <= N; i++)
        {
            if (j - (M - num[tate][i].count) <= 0)
            {
                cout << "   ";
            }
            else if (to_string(num[tate][i].key[j - (M - num[tate][i].count)]).length() == 1)
            {
                cout << "  " << num[tate][i].key[j - (M - num[tate][i].count)];
            }
            else
            {
                cout << " " << num[tate][i].key[j - (M - num[tate][i].count)];
            }
        }
        cout << endl;
    }

    // 上線表示
    for (int j = 0; j < M; j++)
    {
        cout << "   ";
    }

    cout << "-";

    for (int j = 0; j < N; j++)
    {
        cout << "---";
    }

    cout << "-" << endl;

    // 横条件と値を表示
    for (int i = 1; i <= N; i++)
    {
        // 横条件を表示

        for (int j = 1; j <= M - num[yoko][i].count; j++)
        {
            cout << "   ";
        }

        if (num[yoko][i].count != 0)
        {
            for (int j = M - num[yoko][i].count + 1; j <= M; j++)
            {
                if (to_string(num[yoko][i].key[j - (M - num[yoko][i].count)]).length() == 1)
                {
                    cout << "  " << num[yoko][i].key[j - (M - num[yoko][i].count)];
                }
                else
                {
                    cout << " " << num[yoko][i].key[j - (M - num[yoko][i].count)];
                }
            }
            cout << "|";
        }
        else
        {
            cout << "  0|";
        }

        // 値を表示
        for (int jj = 1; jj <= N; jj++)
        {
            if (value[i][jj] != 0)
            {
                if (value[i][jj] == '0')
                {
                    cout << "  ";
                }
                else
                {
                    cout << " " << value[i][jj];
                }
            }
            else
            {
                cout << "   ";
            }
        }

        cout << "|" << endl;
    }

    // 下線表示
    for (int j = 0; j < M; j++)
    {
        cout << "   ";
    }

    cout << "-";

    for (int j = 0; j < N; j++)
    {
        cout << "---";
    }

    cout << "- " << endl;
}

int main()
{
    // 縦横の長さを設定

    /*
    int N;

    cout << "Input N. --> ";
    cin >> N;
    */

    // 変数の宣言と初期化

    key_informations num[2][N + 1] = {};

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            num[i][j].done = false;
        }
    }

    // 縦の代入

    cout << "Input tate. If finish, input 99." << endl;
    //dainyu(tate);

    for (int i = 1; i <= N; i++)
    {
        num[tate][i].count = 0;

        bool zf = false;

        for (int j = 1; j <= M; j++)
        {
            cin >> num[tate][i].key[j];

            if (num[tate][i].key[j] == 99)
            {
                num[tate][i].key[j] = 0;
                num[tate][i].sum -= 1;
                break;
            }
            else if (num[tate][i].key[j] == 0)
            {
                num[tate][i].count = 0;
                zf = true;
            }

            num[tate][i].sum += num[tate][i].key[j] + 1;

            num[tate][i].count++;
        }
    }

    // 横の代入

    cout << "Input yoko. If finish, input 99." << endl;

    //dainyu(yoko);

    for (int i = 1; i <= N; i++)
    {
        num[yoko][i].count = 0;

        bool zf = false;

        for (int j = 1; j <= M; j++)
        {
            cin >> num[yoko][i].key[j];

            if (num[yoko][i].key[j] == 99)
            {
                num[yoko][i].key[j] = 0;
                num[yoko][i].sum -= 1;
                break;
            }
            else if (num[yoko][i].key[j] == 0)
            {
                num[yoko][i].count = 0;
                zf = true;
            }

            num[yoko][i].sum += num[yoko][i].key[j] + 1;

            num[yoko][i].count++;
        }
    }

    // lackを設定
    for (int tateyoko = 0; tateyoko <= 1; tateyoko++)
    {
        for (int i = 1; i <= N; i++)
        {
            num[tateyoko][i].lack = 1 - num[tateyoko][i].sum;
        }
    }

    // 初期状態を表示

    char value[N + 1][N + 1] = {};
    hyouji(num, value);

    // 計算
    while (1)
    {
        bool endflg = true;

        // 縦

        for (int i = 1; i <= N; i++)
        {
            if (num[tate][i].done != false)
            {
                int start = 1;
                int kosuu;

                for (int j = 0; j < num[tate][i].lack; j++)
                {
                    value[j][i] = '0';
                }

                for (int katamari = 1; katamari <= num[tate][i].count; katamari++)
                {
                    for (kosuu = start; kosuu < num[tate][i].key[katamari]; kosuu++)
                    {
                        value[kosuu][i] = 'o';
                    }

                    if (kosuu < N)
                    {
                        start += num[tate][i].key[katamari] + 1;
                        value[start][i] = 'x';
                    }
                }

                if ()
                {
                    num[tate][i].done = true;
                }
            }
        }

        // 終了条件
        if (endflg == true)
        {
            //hyouji(key, count, value);

            cout << "This is the answer." << endl;
            break;
        }
    }

    return 0;
}