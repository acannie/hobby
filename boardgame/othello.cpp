#include <bits/stdc++.h>

#define NUM 8

using namespace std;

// TODO template
std::string join(const vector<string> &vec, const char *delim)
{
    stringstream res;
    copy(vec.begin(), vec.end(), ostream_iterator<string>(res, delim));
    return res.str();
}

int check(char (&cell)[NUM + 1][NUM + 1], int col, int row, char ally_symbol, char rival_symbol, int c_delta, int r_delta)
{
    if (cell[row][col] != ' ')
        return -1;

    int c = col + c_delta;
    int r = row + r_delta;
    int count = 0;
    while ((1 <= r && r <= NUM) && (1 <= c && c <= NUM))
    {
        if (cell[r][c] != rival_symbol)
        {
            // at least 1 rival symbol must appear
            if (cell[r][c] == ally_symbol && count > 0)
            {
                return count;
            }

            break;
        }

        count++;
        c += c_delta;
        r += r_delta;
    }
    return -1;
}

bool try_and_set_direction(char (&cell)[NUM + 1][NUM + 1], int col, int row, char ally_symbol, char rival_symbol, int c_delta, int r_delta)
{
    int count = check(cell, col, row, ally_symbol, rival_symbol, c_delta, r_delta);

    if (count < 0)
    {
        return false;
    }

    for (int k = 1; k <= count; k++)
    {
        cell[row + k * r_delta][col + k * c_delta] = ally_symbol;
    }
    return true;
}

bool try_and_set(char (&cell)[NUM + 1][NUM + 1], int col, int row, char ally_symbol, char rival_symbol)
{
    if (cell[row][col] != ' ')
    {
        return false;
    }

    /* サーチ */
    bool success = false;

    for (int r_delta = -1; r_delta <= 1; r_delta++)
    {
        for (int c_delta = -1; c_delta <= 1; c_delta++)
        {
            if (r_delta == 0 && c_delta == 0)
            {
                continue;
            }
            success = try_and_set_direction(cell, col, row, ally_symbol, rival_symbol, c_delta, r_delta) || success;
        }
    }

    if (success)
    {
        cell[row][col] = ally_symbol;
    }

    return success;
}

void display(char cell[NUM + 1][NUM + 1])
{
    string show;
    vector<std::string> row;
    std::transform(std::begin(cell[0]), std::end(cell[0]), std::back_inserter(row),
                   [](char c) { return std::string() + c; });
    show += join(row, "   ");
    show += "\n";
    show += "  ---------------------------------\n";

    for (int i = 1; i <= NUM; i++)
    {
        vector<std::string> row;
        std::transform(std::begin(cell[i]), std::end(cell[i]), std::back_inserter(row),
                       [](char c) { return std::string() + c; });
        show += join(row, " | ");
        show += "\n";
        show += "  ---------------------------------\n";
    }
    show += "\n";
    cout << show;
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
    std::fill(cell[0], cell[NUM + 1], ' ');

    for (int i = 0; i <= NUM; i++)
    {
        cell[0][i] = '0' + i;
        cell[i][0] = '0' + i;
    }
    cell[0][0] = ' ';

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
        display(cell);

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
        char ally_symbol;
        char rival_symbol;

        if (active_player == true)
        {
            ally_symbol = 'o';
            rival_symbol = 'x';
        }
        else
        {
            ally_symbol = 'x';
            rival_symbol = 'o';
        }

        /* 入力マス設定 */
        int col;
        int row;

        cout << "Please select a cell (col, row)." << endl;

        bool success = false;

        while (!success)
        {
            cout << "(col, row) --> ";
            cin >> col >> row;

            success = try_and_set(cell, col, row, ally_symbol, rival_symbol);

            /* エラーチェック */
            if (!success)
            {
                cout << "Error! Please select again." << endl;
            }
        } //1ターン終了

        /* TODO 終了・ターン判定 */

        /* ターン更新 */
        active_player = !active_player;

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

    display(cell);

    if (o_count != x_count)
    {
        string winner = o_count > x_count ? player_o : player_x;
        cout << winner << " wins!" << endl;
    }
    else
    {
        cout << "draw" << endl;
    }

    return 0;
}