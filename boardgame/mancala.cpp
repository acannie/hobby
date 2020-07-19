#include <bits/stdc++.h>
using namespace std;

void input_name(vector<string> &player_names, int player_num)
{
    string name;

    for (int i = 0; i < player_num; i++)
    {
        cout << "Input player " << i + 1 << " name --> ";
        cin >> name;
        player_names.emplace_back(name);
    }

    cout << endl;
}

// TODO スペースの数管理
void display(vector<string> player, vector<int> hole_statuses, int player_num, int hole_num)
{
    int frame_width = 17 + (hole_num - 1) * 6;

    // 上枠表示
    for (int i = 0; i < frame_width; i++)
    {
        cout << "-";
    }
    cout << endl;

    // player1の名前を表示
    cout << "| player: " << player.at(0);
    for (int i = 0; i < frame_width - 11 - player.at(0).length(); i++)
    {
        cout << " ";
    }
    cout << "|" << endl;

    // 空白行
    cout << "|";
    for (int i = 0; i < frame_width - 2; i++)
    {
        cout << " ";
    }
    cout << "|" << endl;

    // インデックスを表示
    cout << "|       ";
    for (int i = 0; i < hole_num; i++)
    {
        cout << hole_num - i << "     ";
    }
    cout << "  |" << endl;

    // player 1 のhole statusを表示
    cout << "|      ";
    for (int i = 0; i < hole_num; i++)
    {
        cout << "[" << hole_statuses.at(((hole_num * 1) - i - 1)) << "]   ";
    }
    cout << "   |" << endl;

    // special holeを表示
    cout << "| ";
    for (int i = 0; i < player_num; i++)
    {
        cout << "[" << hole_statuses.at((hole_num + 1) * (i + 1) - 1) << "]";
        if (i != player_num - 1)
        {
            cout << "                   ";
        }
    }
    cout << " |" << endl;

    // player 2 のhole statusを表示
    cout << "|      ";
    for (int i = 0; i < hole_num; i++)
    {
        cout << "[" << hole_statuses.at((hole_num * 1) + i + 1) << "]   ";
    }
    cout << "   |" << endl;

    // インデックスを表示
    cout << "|       ";
    for (int i = 0; i < hole_num; i++)
    {
        cout << i + 1 << "     ";
    }
    cout << "  |" << endl;

    // 空白行
    cout << "|";
    for (int i = 0; i < frame_width - 2; i++)
    {
        cout << " ";
    }
    cout << "|" << endl;

    // player2の名前を表示
    cout << "| player: " << player.at(1);
    for (int i = 0; i < 18 - player.at(1).length(); i++)
    {
        cout << " ";
    }
    cout << "|" << endl;

    // 下枠表示
    for (int i = 0; i < frame_width; i++)
    {
        cout << "-";
    }
    cout << endl;
}

int main()
{
    /* プレイヤー名の入力 */
    vector<string> player_names;
    int player_num = 2;      // playerの人数
    int hole_num = 3;        // 穴の数
    int first_stone_num = 3; // 初期状態における穴一つあたりの石の数
    int total_holes = player_num * (hole_num + 1);

    input_name(player_names, player_num);

    cout << "Game Start!" << endl;
    cout << endl;

    /* ボードの初期状態を設定 */
    vector<int> hole_statuses;
    for (int i = 0; i < total_holes; i++)
    {
        if (i % (hole_num + 1) == hole_num)
        {
            hole_statuses.emplace_back(0);
        }
        else
        {
            hole_statuses.emplace_back(first_stone_num);
        }
    }

    /* 先手の設定 */
    random_device rnd;
    int active_player = rnd() % player_num;

    /* ゲーム開始 */
    for (int lap = 0;; lap++)
    {
        /* lap表示 */
        int input_select_num;
        int select_num;

        cout << "--- lap " << lap + 1 << " ------------------------------------------------" << endl;
        cout << endl;

        /* 状態表示 */
        display(player_names, hole_statuses, player_num, hole_num);

        cout << player_names.at(active_player) << "'s turn." << endl;

        /* 自陣のマスを選択 */
        cout << "Select your place --> ";

        int select_hole;

        while (1)
        {
            cin >> select_num;
            select_hole = (hole_num + 1) * active_player + select_num - 1;

            if (ceil(select_num) != floor(select_num) || !(1 <= select_num && select_num <= hole_num))
            {
                cout << "Input number 1 to " << hole_num << ". --> ";
            }
            else if (hole_statuses.at(select_hole) == 0)
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

        int stone_num = hole_statuses.at(select_hole);
        // int *select_hole_pointer;
        // select_hole_pointer = &hole_statuses.at(select_hole);

        hole_statuses.at(select_hole) = 0;

        int operating_hole;

        for (int i = 0; i < stone_num; i++)
        {
            operating_hole = (select_hole + i) % total_holes;

            if (operating_hole + 1 == total_holes)
            {
                operating_hole = 0;
            }
            else
            {
                operating_hole++;
            }

            hole_statuses.at(operating_hole)++;
        }

        cout << endl;

        /* 終了判定 */
        bool hole_empty = true;
        for (int i = 0; i < hole_num; i++)
        {
            if (hole_statuses.at(active_player * (hole_num + 1) + i) != 0)
            {
                hole_empty = false;
            }
        }

        if (hole_empty)
        {
            /* 終了状態表示 */
            cout << "--- LAST STATE ------------------------------------" << endl;
            cout << endl;

            display(player_names, hole_statuses, player_num, hole_num);

            cout << player_names.at(active_player) << " win!" << endl;

            cout << endl;

            break;
        }

        /* 次ターン判定 */
        if ((operating_hole + 1) % (hole_num + 1) != 0)
        {
            // active_player を次の人にする(1大きい番号を持つ player)。
            active_player = (active_player + 1) % player_names.size();
        }
    }

    return 0;
}