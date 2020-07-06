#include <bits/stdc++.h>
using namespace std;

void input_name(vector<string> &player_names, int player_num)
{
    string name;

    for (int i = 0; i < player_num; i++)
    {
        cout << "Input player " << i+1 << " name --> ";
        cin >> name;
        player_names.emplace_back(name);
    }

    cout << endl;
}

//TODO bufの名前変更
void display(vector<string> player, vector<vector<int>> hole_statuses, int special_hole_1, int special_hole_2)
{
    cout << "-----------------------------" << endl;
    cout << "| player: " << player.at(0);

    //TODO 18が表すもの調査
    for (int i = 0; i < 18 - player.at(0).length(); i++)
    {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "|                           |" << endl;

    cout << "|       3     2     1       |" << endl;
    cout << "|      [" << hole_statuses.at(0).at(2) << "]   [" << hole_statuses.at(0).at(1) << "]   [" << hole_statuses.at(0).at(0) << "]      |" << endl;
    cout << "| [" << special_hole_1 << "]                   [" << special_hole_2 << "] |" << endl;
    cout << "|      [" << hole_statuses.at(1).at(0) << "]   [" << hole_statuses.at(1).at(1) << "]   [" << hole_statuses.at(1).at(2) << "]      |" << endl;
    cout << "|       1     2     3       |" << endl;

    cout << "|                           |" << endl;
    cout << "| player: " << player.at(1);
    for (int i = 0; i < 18 - player.at(1).length(); i++)
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
    vector<string> player_names;
    int player_num = 2;      // playerの人数
    int hole_num = 3;        // 穴の数
    int first_stone_num = 3; // 初期状態における穴一つあたりの石の数

    input_name(player_names, player_num);

    cout << "Game Start!" << endl;
    cout << endl;

    /* ボードの初期状態を設定 */
    vector<vector<int>> hole_statuses;
    for (int p = 0; p < player_num; p++)
    {
        hole_statuses.emplace_back(0);
        for (int s = 0; s < hole_num; s++)
        {
            hole_statuses.at(p).emplace_back(first_stone_num);
        }
    }

    int special_hole_1 = 0;
    int special_hole_2 = 0;

    /* 先手の設定 */
    int active_player = 0;

    /* ゲーム開始 */
    for (int lap = 0;; lap++)
    {
        /* lap表示 */
        int input_sow;
        int sow;

        cout << "--- lap " << lap + 1 << " ------------------------------------------------" << endl;
        cout << endl;

        /* 状態表示 */
        display(player_names, hole_statuses, special_hole_1, special_hole_2);

        cout << player_names.at(active_player) << "'s turn." << endl;

        /* 自陣のマスを選択 */
        cout << "Select your place --> ";

        while (1)
        {
            cin >> sow;

            if (ceil(sow) != floor(sow) || !(1 <= sow && sow <= hole_num))
            {
                cout << "Input number 1 to 3. --> ";
            }
            else if (hole_statuses.at(active_player).at(sow - 1) == 0)
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
        int stone_num = hole_statuses.at(active_player).at(sow - 1);
        int *now_operate_place;
        now_operate_place = &hole_statuses.at(active_player).at(sow - 1);

        hole_statuses.at(active_player).at(sow - 1) = 0;

        for (int i = 0; i < stone_num; i++)
        {
            // FIXME
            if (now_operate_place == &hole_statuses.at(0).at(0))
            {
                now_operate_place = &hole_statuses.at(0).at(1);
            }
            else if (now_operate_place == &hole_statuses.at(0).at(1))
            {
                now_operate_place = &hole_statuses.at(0).at(2);
            }
            else if (now_operate_place == &hole_statuses.at(0).at(2))
            {
                now_operate_place = &special_hole_1;
            }
            else if (now_operate_place == &special_hole_1)
            {
                now_operate_place = &hole_statuses.at(1).at(0);
            }
            else if (now_operate_place == &hole_statuses.at(1).at(0))
            {
                now_operate_place = &hole_statuses.at(1).at(1);
            }
            else if (now_operate_place == &hole_statuses.at(1).at(1))
            {
                now_operate_place = &hole_statuses.at(1).at(2);
            }
            else if (now_operate_place == &hole_statuses.at(1).at(2))
            {
                now_operate_place = &special_hole_2;
            }
            else if (now_operate_place == &special_hole_2)
            {
                now_operate_place = &hole_statuses.at(0).at(0);
            }
            (*now_operate_place)++;
        }

        cout << endl;

        /* 終了判定 */
        bool hole_empty = true;
        for (int i = 0; i < hole_num; i++)
        {
            if (hole_statuses.at(active_player).at(i) != 0)
            {
                hole_empty = false;
            }
        }

        if (hole_empty)
        {
            /* 終了状態表示 */
            cout << "--- LAST STATE ------------------------------------" << endl;
            cout << endl;

            display(player_names, hole_statuses, special_hole_1, special_hole_2);

            cout << player_names.at(active_player) << " win!" << endl;

            cout << endl;

            break;
        }

        /* 次ターン判定 */
        if (now_operate_place != &special_hole_1 && now_operate_place != &special_hole_2)
        {
            // active_player を次の人にする(1大きい番号を持つ player)。
            active_player = (active_player + 1) % player_names.size();
        }
    }

    return 0;
}