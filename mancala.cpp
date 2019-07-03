#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void hyouji(string player[3], int space[3][4], int buf1, int buf2)
{
    cout << "-----------------------------" << endl;
    cout << "| player: " << player[1];

    for (int i = 0; i < 18 - player[1].length(); i++)
    {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "|                           |" << endl;

    cout << "|       3     2     1       |" << endl;
    cout << "|      [" << space[1][3] << "]   [" << space[1][2] << "]   [" << space[1][1] << "]      |" << endl;
    cout << "| [" << buf1 << "]                   [" << buf2 << "] |" << endl;
    cout << "|      [" << space[2][1] << "]   [" << space[2][2] << "]   [" << space[2][3] << "]      |" << endl;
    cout << "|       1     2     3       |" << endl;

    cout << "|                           |" << endl;
    cout << "| player: " << player[2];
    for (int i = 0; i < 18 - player[2].length(); i++)
    {
        cout << " ";
    }
    cout << "|" << endl;

    cout << "-----------------------------" << endl;

    cout << endl;
}

int main()
{
    /* プレイヤー名の入力 */
    string player[3];

    cout << "Input player1 name --> ";
    cin >> player[1];
    cout << "Input player2 name --> ";
    cin >> player[2];
    cout << endl;

    cout << "Game Start!" << endl;
    cout << endl;

    /* ボードの初期状態を設定 */
    int space[3][4] = {{0, 0, 0, 0}, {0, 3, 3, 3}, {0, 3, 3, 3}};
    int buf1 = 0;
    int buf2 = 0;

    /* 先手の設定 */
    int active_player = 1;

    /* ゲーム開始 */
    for (int i = 1;; i++)
    {
        /* lap表示 */
        bool flg_buf = false;
        int input_sow;
        int sow;

        cout << "--- lap " << i << " ------------------------------------------------" << endl;
        cout << endl;

        /* 状態表示 */
        hyouji(player, space, buf1, buf2);

        cout << player[active_player] << "'s turn." << endl;

        /* 自陣のマスを選択 */
        cout << "Select your place --> ";
        while (1)
        {
            cin >> sow;

            if ((sow != 1) && (sow != 2) && (sow != 3))
            {
                cout << "Input number 1 to 3. --> ";
            }
            else if (space[active_player][sow] == 0)
            {
                cout << "No stone there. Input again. --> ";
            }
            else
            {
                cout << endl;
                break;
            }
        }

        /* 状態を更新 */
        int stone_num = space[active_player][sow];
        int *now_place;

        now_place = &space[active_player][sow];

        space[active_player][sow] = 0;

        while (stone_num > 0)
        {
            //条件要検討
            if (now_place == &space[1][1])
            {
                now_place = &space[1][2];
                stone_num--;
                space[1][2]++;
                flg_buf = false;
            }
            else if (now_place == &space[1][2])
            {
                now_place = &space[1][3];
                stone_num--;
                space[1][3]++;
                flg_buf = false;
            }
            else if (now_place == &space[1][3])
            {
                now_place = &buf1;
                stone_num--;
                buf1++;
                flg_buf = true;
            }
            else if (now_place == &buf1)
            {
                now_place = &space[2][1];
                stone_num--;
                space[2][1]++;
                flg_buf = false;
            }
            else if (now_place == &space[2][1])
            {
                now_place = &space[2][2];
                stone_num--;
                space[2][2]++;
                flg_buf = false;
            }
            else if (now_place == &space[2][2])
            {
                now_place = &space[2][3];
                stone_num--;
                space[2][3]++;
                flg_buf = false;
            }
            else if (now_place == &space[2][3])
            {
                now_place = &buf2;
                stone_num--;
                buf2++;
                flg_buf = true;
            }
            else if (now_place == &buf2)
            {
                now_place = &space[1][1];
                stone_num--;
                space[1][1]++;
                flg_buf = false;
            }
        }

        cout << endl;

        /* 終了判定 */
        if ((space[1][1] == 0) && (space[1][2] == 0) && (space[1][3] == 0))
        {
            /* 終了状態表示 */
            cout << "--- LAST STATE ------------------------------------" << endl;
            cout << endl;

            hyouji(player, space, buf1, buf2);

            cout << player[1] << " win!" << endl;
            cout << endl;

            break;
        }
        else if ((space[2][1] == 0) && (space[2][2] == 0) && (space[2][3] == 0))
        {
            /* 終了状態表示 */
            cout << "--- LAST STATE ------------------------------------" << endl;
            cout << endl;

            hyouji(player, space, buf1, buf2);

            cout << player[2] << " win!" << endl;
            cout << endl;

            break;
        }

        /* 再ターン判定 */
        if (flg_buf == false)
        {
            if (active_player == 1)
            {
                active_player = 2;
            }
            else
            {
                active_player = 1;
            }
        }
    }

    return 0;
}