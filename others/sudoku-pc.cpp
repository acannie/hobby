#include <iostream>
#include <cmath>
#include <string>

#define SUDOKU_NUM 3

using namespace std;

int main()
{
    int NUM = pow(SUDOKU_NUM, 2);
    int masu[9][9];

    /* 初期数字の入力 */
    for (int i = 0; i < NUM; i++)
    {
        cout << "Input the numbers in the ";
        if (i == 0)
        {
            cout << "1st";
        }
        else if (i == 1)
        {
            cout << "2nd";
        }
        else if (i == 2)
        {
            cout << "3rd";
        }
        else
        {
            cout << i + 1 << "th";
        }
        cout << " column. --> ";

        for (int j = 0; j < NUM; j++)
        {
            cin >> masu[i][j];
        }
    }

    cout << endl;

    /* 初期状態の出力 */
    cout << "-------------------" << endl;
    for (int i = 0; i < NUM; i++)
    {
        cout << "|";
        for (int j = 0; j < NUM; j++)
        {
            if (masu[i][j] != 0)
            {
                cout << masu[i][j];
            }
            else
            {
                cout << " ";
            }

            if ((j + 1) % SUDOKU_NUM == 0)
            {
                cout << "|";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
        if ((i + 1) % SUDOKU_NUM == 0)
        {
            cout << "-------------------" << endl;
        }
    }

    /* 各マスの値可能性をメモする配列 */
    bool possibility[NUM][NUM][NUM];

    /* 初期入力値のあるマス目の処理 */
    for (int i = 0; i < NUM; i++)
    {
        for (int j = 0; j < NUM; j++)
        {
            for (int k = 0; k < NUM; k++)
            {
                if (masu[i][j] != 0)
                {
                    possibility[i][j][k] = false;
                }
                possibility[i][j][masu[i][j]] = true;
            }
        }
    }

    /* 計算 */
    while (1)
    {
        /* 可能性更新 */
        for (int i = 0; i < NUM; i++)
        {
            for (int j = 0; j < NUM; j++)
            {
                /* 埋まっていないマス目の処理 */
                if (masu[i][j] == 0)
                {

                    /* 横サーチ */
                    for (int yoko = 0; yoko < NUM; yoko++)
                    {
                        if (masu[i][yoko] != 0)
                        {
                            possibility[i][j][masu[i][yoko]] = false;
                        }
                    }

                    /* 縦サーチ */
                    for (int tate = 0; tate < NUM; tate++)
                    {
                    }

                    /* 箱サーチ */
                }
            }
        }

        /* 可能性が一意に定まるマス目の処理 */
        //行き詰まったら相補完処理へ

        /* 相補完処理 */

        /*  */

        /* 終了条件 */


    }

    return 0;
}