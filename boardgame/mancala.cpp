#include <bits/stdc++.h>

using namespace std;

void input_name(vector<string> &player_names)
{
    string name;
    cout << "Input player1 name --> ";
    cin >> name;
    player_names.emplace_back(name);
    cout << "Input player2 name --> ";
    cin >> name;
    player_names.emplace_back(name);
    cout << endl;
}

//TODO bufの名前変更
void display(vector<string> player, vector<vector<int>> space, int buf1, int buf2)
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
    cout << "|      [" << space.at(0).at(2) << "]   [" << space.at(0).at(1) << "]   [" << space.at(0).at(0) << "]      |" << endl;
    cout << "| [" << buf1 << "]                   [" << buf2 << "] |" << endl;
    cout << "|      [" << space.at(1).at(0) << "]   [" << space.at(1).at(1) << "]   [" << space.at(1).at(2) << "]      |" << endl;
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
    vector<string> player;
    input_name(player);

    cout << "Game Start!" << endl;
    cout << endl;

    /* ボードの初期状態を設定 */
    vector<vector<int>> space;
    for (int p = 0; p < 2; p++)
    {
        space.emplace_back(0);
        for (int s = 0; s < 3; s++)
        {
            space.at(p).emplace_back(3);
        }
    }

    int buf1 = 0;
    int buf2 = 0;

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
        display(player, space, buf1, buf2);

        cout << player.at(active_player) << "'s turn." << endl;

        /* 自陣のマスを選択 */
        cout << "Select your place --> ";

        while (1)
        {
            cin >> sow;

            if ((sow != 1) && (sow != 2) && (sow != 3))
            {
                cout << "Input number 1 to 3. --> ";
            }
            else if (space.at(active_player).at(sow - 1) == 0)
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
        int stone_num = space.at(active_player).at(sow - 1);
        int *now_operate_place;
        now_operate_place = &space.at(active_player).at(sow - 1);

        space.at(active_player).at(sow - 1) = 0;

        for (int i = 0; i < stone_num; i++)
        {
            // FIXME
            if (now_operate_place == &space.at(0).at(0))
            {
                now_operate_place = &space.at(0).at(1);
            }
            else if (now_operate_place == &space.at(0).at(1))
            {
                now_operate_place = &space.at(0).at(2);
            }
            else if (now_operate_place == &space.at(0).at(2))
            {
                now_operate_place = &buf1;
            }
            else if (now_operate_place == &buf1)
            {
                now_operate_place = &space.at(1).at(0);
            }
            else if (now_operate_place == &space.at(1).at(0))
            {
                now_operate_place = &space.at(1).at(1);
            }
            else if (now_operate_place == &space.at(1).at(1))
            {
                now_operate_place = &space.at(1).at(2);
            }
            else if (now_operate_place == &space.at(1).at(2))
            {
                now_operate_place = &buf2;
            }
            else if (now_operate_place == &buf2)
            {
                now_operate_place = &space.at(0).at(0);
            }
            (*now_operate_place)++;
        }

        cout << endl;

        /* 終了判定 */
        if ((space.at(active_player).at(0) == 0) && (space.at(active_player).at(1) == 0) && (space.at(active_player).at(2) == 0))
        {
            /* 終了状態表示 */
            cout << "--- LAST STATE ------------------------------------" << endl;
            cout << endl;

            display(player, space, buf1, buf2);

            cout << player.at(active_player) << " win!" << endl;

            cout << endl;

            break;
        }

        /* 次ターン判定 */
        if (now_operate_place != &buf1 && now_operate_place != &buf2)
        {
            // active_player を次の人にする(1大きい番号を持つ player)。
            active_player = (active_player + 1) % player.size();
        }
    }

    return 0;
}