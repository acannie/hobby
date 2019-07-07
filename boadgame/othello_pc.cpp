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

    /* 初期状態表示 */
    /*     cout << "    ";
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
    */

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
        int i_select;
        int j_select;

        cout << "Please select a cell (i, j)." << endl;

        while (1)
        {
            cout << "i j --> ";
            cin >> i_select >> j_select;

            bool error = true;

            if (cell[i_select][j_select] == 'n')
            {
                error = true;

                /* サーチ */

                /* 右サーチ */
                if (j_select < NUM - 1)
                {

                    for (int j = j_select + 1; j <= NUM; j++)
                    {
                        if (cell[i_select][j] == 'n')
                        {
                            break;
                        }
                        else if (cell[i_select][j] == ally)
                        {
                            if (j == (j_select + 1))
                            {
                                break;
                            }
                            else
                            {
                                error = false;

                                for (int j_change = j_select + 1; j_change < j; j_change++)
                                {
                                    cell[i_select][j_change] = ally;
                                }
                                break;
                            }
                        }
                    }
                }

                /* 左サーチ */
                if (j_select > 2)
                {

                    for (int j = j_select - 1; j >= 1; j--)
                    {
                        if (cell[i_select][j] == 'n')
                        {
                            break;
                        }
                        else if (cell[i_select][j] == ally)
                        {
                            if (j == (j_select - 1))
                            {
                                break;
                            }
                            else
                            {
                                error = false;

                                for (int j_change = j_select - 1; j_change > j; j_change--)
                                {
                                    cell[i_select][j_change] = ally;
                                }
                                break;
                            }
                        }
                    }
                }

                /* 下サーチ */
                if (i_select < NUM - 1)
                {
                    for (int i = i_select + 1; i <= NUM; i++)
                    {
                        if (cell[i][j_select] == 'n')
                        {
                            break;
                        }
                        else if (cell[i][j_select] == ally)
                        {
                            if (i == (i_select + 1))
                            {
                                break;
                            }
                            else
                            {
                                error = false;

                                for (int i_change = i_select + 1; i_change < i; i_change++)
                                {
                                    cell[i_change][j_select] = ally;
                                }
                                break;
                            }
                        }
                    }
                }

                /* 上サーチ */
                if (i_select > 2)
                {
                    for (int i = i_select - 1; i >= 1; i--)
                    {
                        if (cell[i][j_select] == 'n')
                        {
                            break;
                        }
                        else if (cell[i][j_select] == ally)
                        {
                            if (i == (i_select - 1))
                            {
                                break;
                            }
                            else
                            {
                                error = false;

                                for (int i_change = i_select - 1; i_change > i; i_change--)
                                {
                                    cell[i_change][j_select] = ally;
                                }
                                break;
                            }
                        }
                    }
                }

                /* 右下サーチ */
                if (!((i_select > NUM - 1) || (j_select > NUM - 1)))
                {
                    for (int k = 1; k <= min(NUM - i_select, NUM - j_select); k++)
                    {
                        if (cell[i_select + k][j_select + k] == 'n')
                        {
                            break;
                        }
                        else if (cell[i_select][j_select] == ally)
                        {
                            if (k == 1)
                            {
                                break;
                            }
                            else
                            {
                                error = false;

                                for (int k_change = 1; k_change < min(NUM - i_select, NUM - j_select); k_change++)
                                {
                                    cell[i_select + k][j_select + k] = ally;
                                }
                            }
                        }
                    }
                }

                /* 右上サーチ */
                if (!((i_select < 2) || (j_select > NUM - 1)))
                {
                    for (int i = i_select - 1; i >= 1; i--)
                    {
                        for (int j = j_select + 1; j <= NUM; j++)
                        {
                            if (cell[i][j] == 'n')
                            {
                                goto loopend2;
                            }
                            else if (cell[i][j] == ally)
                            {
                                if ((i == (i_select - 1)) && (j == (j_select + 1)))
                                {
                                    goto loopend2;
                                }
                                else
                                {
                                    error = false;

                                    for (int i_change = i_select - 1; i_change > i; i_change--)
                                    {
                                        for (int j_change = j_select + 1; j_change < j; j_change++)
                                        {
                                            cell[i_change][j_change] = ally;
                                        }
                                    }
                                    goto loopend2;
                                }
                            }
                        }
                    }
                }
            loopend2:

                /* 左下サーチ */
                if (!((i_select > NUM - 1) || (j_select < 2)))
                {
                    for (int i = i_select + 1; i <= NUM; i++)
                    {
                        for (int j = j_select - 1; j >= 1; j--)
                        {
                            if (cell[i][j] == 'n')
                            {
                                goto loopend3;
                            }
                            else if (cell[i][j] == ally)
                            {
                                if ((i == (i_select + 1)) && (j == (j_select - 1)))
                                {
                                    goto loopend3;
                                }
                                else
                                {
                                    error = false;

                                    for (int i_change = i_select + 1; i_change < i; i_change++)
                                    {
                                        for (int j_change = j_select - 1; j_change > j; j_change--)
                                        {
                                            cell[i_change][j_change] = ally;
                                        }
                                    }
                                    goto loopend3;
                                }
                            }
                        }
                    }
                }
            loopend3:

                /* 左上サーチ */
                if (!((i_select < 2) || (j_select < 2)))
                {
                    for (int i = i_select - 1; i >= 1; i--)
                    {
                        for (int j = j_select - 1; j >= 1; j--)
                        {
                            if (cell[i][j] == 'n')
                            {
                                goto loopend4;
                            }
                            else if (cell[i][j] == ally)
                            {
                                if ((i == (i_select - 1)) && (j == (j_select - 1)))
                                {
                                    goto loopend4;
                                }
                                else
                                {
                                    error = false;

                                    for (int i_change = i_select - 1; i_change > i; i_change--)
                                    {
                                        for (int j_change = j_select - 1; j_change > j; j_change--)
                                        {
                                            cell[i_change][j_change] = ally;
                                        }
                                    }
                                    goto loopend4;
                                }
                            }
                        }
                    }
                }
            loopend4:
                goto errorcheck;
            }

        /* エラーチェック */
        errorcheck:

            if (error == true)
            {
                cout << "Error! Please select again." << endl;
            }
            else
            {
                cell[i_select][j_select] = ally;
                break;
            }
        }

        /* 終了・ターン判定 */
        /*if(){
            hyouji(cell);
        */

        /* ターン更新 */
        if (active_player == true)
        {
            active_player = false;
        }
        else
        {
            active_player = true;
        }
    }

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