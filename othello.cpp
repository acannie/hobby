#include <iostream>
#include <cmath>
#include <string>

#define NUM 8

using namespace std;

void hyouji(char cell[NUM + 1][NUM + 1])
{
    cout << "    ";
    for (int i = 1; i <= NUM; i++)
    {
        cout << i << "   ";
    }
    cout << endl;

    cout << "  ---------------------------------" << endl;

    for (int i = 1; i <= NUM; i++)
    {
        cout << i << " |";
        for (int j = 1; j <= NUM; j++)
        {
            if (cell[i][j] == 'o')
            {
                cout << " o |";
            }
            else if (cell[i][j] == 'x')
            {
                cout << " x |";
            }
            else
            {
                cout << "   |";
            }
        }
        cout << endl;
        cout << "  ---------------------------------" << endl;
    }

    cout << endl;
}

int main()
{
    cout << "Welcome to OTHELLO!" << endl;
    cout << endl;

    /* プレイヤー名入力・設定 */
    string player_o, player_x;

    cout << "Input player o name. --> ";
    cin >> player_o;
    cout << "Input player x name. --> ";
    cin >> player_x;
    cout << endl;

    /* 初期状態設定 */
    char cell[NUM + 1][NUM + 1];

    for (int i = 1; i <= NUM; i++)
    {
        for (int j = 1; j <= NUM; j++)
        {
            cell[i][j] = 'n';
        }
    }
    cell[4][4] = 'o';
    cell[5][5] = 'o';
    cell[4][5] = 'x';
    cell[5][4] = 'x';

    /* ゲームスタート */
    bool active_player = true; //trueがplayer o、falseがplayer x
    int lap = 1;

    while (1)
    {
        /* ターン表示 */
        cout << "--- lap " << lap << " ----------------------------------------------" << endl;
        cout << endl;

        /* 更新済み状態表示 */
        hyouji(cell);

        /* ターン表示 */
        if (active_player == true)
        {
            cout << player_o << "'s turn. [o]" << endl;
        }
        else
        {
            cout << player_x << "'s turn. [x]" << endl;
        }
        cout << endl;

        /* 敵味方設定 */
        char ally;
        char enemy;

        if (active_player == true)
        {
            ally = 'o';
            enemy = 'x';
        }
        else
        {
            ally = 'x';
            enemy = 'o';
        }

        /* 入力マス設定 */
        int i_sel;
        int j_sel;

        cout << "Please select a cell (i, j)." << endl;

        bool error = true;

        while (error == true)
        {
            cout << "i j --> ";
            cin >> i_sel >> j_sel;

            if (cell[i_sel][j_sel] == 'n')
            {
                /* サーチ */

                /* 右サーチ */
                if (j_sel < NUM - 1)
                {
                    for (int k = 1; k <= (NUM - j_sel); k++)
                    {
                        if (cell[i_sel][j_sel + k] == 'n')
                        {
                            break;
                        }
                        else if ((cell[i_sel][j_sel + k] == ally) && (k != 1))
                        {
                            error = false;

                            for (int k_change = 1; k_change < k; k_change++)
                            {
                                cell[i_sel][j_sel + k_change] = ally;
                            }
                            break;
                        }
                    }
                }

                /* 左サーチ */
                if (j_sel > 2)
                {
                    for (int k = 1; k <= (j_sel - 1); k++)
                    {
                        if (cell[i_sel][j_sel - k] == 'n')
                        {
                            break;
                        }
                        else if ((cell[i_sel][j_sel - k] == ally) && (k != 1))
                        {
                            error = false;

                            for (int k_change = 1; k_change < k; k_change++)
                            {
                                cell[i_sel][j_sel - k_change] = ally;
                            }
                            break;
                        }
                    }
                }

                /* 下サーチ */
                if (i_sel < NUM - 1)
                {
                    for (int k = 1; k <= (NUM - i_sel); k++)
                    {
                        if (cell[i_sel + k][j_sel] == 'n')
                        {
                            break;
                        }
                        else if ((cell[i_sel + k][j_sel] == ally) && (k != 1))
                        {
                            error = false;

                            for (int k_change = 1; k_change < k; k_change++)
                            {
                                cell[i_sel + k_change][j_sel] = ally;
                            }
                            break;
                        }
                    }
                }

                /* 上サーチ */
                if (i_sel > 2)
                {
                    for (int k = 1; k <= (i_sel - 1); k++)
                    {
                        if (cell[i_sel - k][j_sel] == 'n')
                        {
                            break;
                        }
                        else if ((cell[i_sel - k][j_sel] == ally) && (k != 1))
                        {
                            error = false;

                            for (int k_change = 1; k_change < k; k_change++)
                            {
                                cell[i_sel - k_change][j_sel] = ally;
                            }
                            break;
                        }
                    }
                }

                /* 右下サーチ */
                if (!((i_sel > NUM - 2) || (j_sel > NUM - 2)))
                {
                    for (int k = 1; k <= min(NUM - i_sel, NUM - j_sel); k++)
                    {
                        if (cell[i_sel + k][j_sel + k] == 'n')
                        {
                            break;
                        }
                        else if ((cell[i_sel + k][j_sel + k] == ally) && (k != 1))
                        {

                            error = false;

                            for (int k_change = 1; k_change < k; k_change++)
                            {
                                cell[i_sel + k_change][j_sel + k_change] = ally;
                            }
                            break;
                        }
                    }
                }

                /* 右上サーチ */
                if (!((i_sel < 2) || (j_sel > NUM - 2)))
                {
                    for (int k = 1; k <= min(i_sel - 1, NUM - j_sel); k++)
                    {
                        if (cell[i_sel - k][j_sel + k] == 'n')
                        {
                            break;
                        }
                        else if ((cell[i_sel - k][j_sel + k] == ally) && (k != 1))
                        {
                            error = false;

                            for (int k_change = 1; k_change < k; k_change++)
                            {
                                cell[i_sel - k_change][j_sel + k_change] = ally;
                            }
                            break;
                        }
                    }
                }

                /* 左下サーチ */
                if (!((i_sel > NUM - 2) || (j_sel < 2)))
                {
                    for (int k = 1; k <= min(NUM - i_sel, j_sel - 1); k++)
                    {
                        if (cell[i_sel + k][j_sel - k] == 'n')
                        {
                            break;
                        }
                        else if ((cell[i_sel + k][j_sel - k] == ally) && (k != 1))
                        {
                            error = false;

                            for (int k_change = 1; k_change < k; k_change++)
                            {
                                cell[i_sel + k_change][j_sel - k_change] = ally;
                            }
                            break;
                        }
                    }
                }

                /* 左上サーチ */
                if (!((i_sel < 2) || (j_sel < 2)))
                {
                    for (int k = 1; k <= min(i_sel - 1, j_sel - 1); k++)
                    {
                        if (cell[i_sel - k][j_sel - k] == 'n')
                        {
                            break;
                        }
                        else if ((cell[i_sel - k][j_sel - k] == ally) && (k != 1))
                        {
                            error = false;

                            for (int k_change = 1; k_change < k; k_change++)
                            {
                                cell[i_sel - k_change][j_sel - k_change] = ally;
                            }
                            break;
                        }
                    }
                }
            }

            /* エラーチェック */
            if (error == true)
            {
                cout << "Error! Please sel again." << endl;
            }
            else
            {
                cell[i_sel][j_sel] = ally;
            }
        } //1ターン終了

        /* 終了・ターン判定 */

        /* ターン更新 */
        if (active_player == true)
        {
            active_player = false;
        }
        else
        {
            active_player = true;
        }

        /* ターン更新 */
        lap++;

    } //ゲーム終了

    /* 終了状態表示 */

    /* 勝利判定 */
    int o_count = 0;
    int x_count = 0;

    for (int i = 1; i <= NUM; i++)
    {
        for (int j = 1; j <= NUM; j++)
        {
            if (cell[i][j] == 'o')
            {
                o_count++;
            }
            if (cell[i][j] == 'x')
            {
                x_count++;
            }
        }
    }

    hyouji(cell);

    if (o_count > x_count)
    {
        cout << player_o << " win!" << endl;
    }
    else if (x_count > o_count)
    {
        cout << player_x << " win!" << endl;
    }
    else
    {
        cout << "hikiwake!" << endl;
    }

    return 0;
}