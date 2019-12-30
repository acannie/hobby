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

int check(char (&cell)[NUM + 1][NUM + 1], int i_sel, int j_sel, char ally_symbol, char rival_symbol, int x_delta, int y_delta)
{
    if (cell[i_sel][j_sel] != ' ')
        return -1;

    int i = i_sel + y_delta;
    int j = j_sel + x_delta;
    int count = 0;
    while ((1 <= j && j <= NUM) && (1 <= i && i <= NUM))
    {
        if (cell[i][j] != rival_symbol)
        {
            // at least 1 rival symbol must appear
            if (cell[i][j] == ally_symbol && count > 0)
            {
                return count;
            }

            break;
        }

        count++;
        i += y_delta;
        j += x_delta;
    }
    return -1;
}

bool try_and_set_direction(char (&cell)[NUM + 1][NUM + 1], int i_sel, int j_sel, char ally_symbol, char rival_symbol, int x_delta, int y_delta)
{
    int count = check(cell, i_sel, j_sel, ally_symbol, rival_symbol, x_delta, y_delta);

    if (count < 0)
    {
        return false;
    }

    int i = i_sel;
    int j = j_sel;
    for (int k = 1; k <= count; k++)
    {
        cell[i + k * y_delta][j + k * x_delta] = ally_symbol;
    }
    return true;
}

bool try_and_set(char (&cell)[NUM + 1][NUM + 1], int i_sel, int j_sel, char ally_symbol, char rival_symbol)
{
    if (cell[i_sel][j_sel] != ' ')
    {
        return true;
    }

    /* サーチ */
    bool success = false;

    for (int x_delta = -1; x_delta <= 1; x_delta++)
    {
        for (int y_delta = -1; y_delta <= 1; y_delta++)
        {
            if (x_delta == 0 && y_delta == 0)
            {
                continue;
            }
            success = try_and_set_direction(cell, i_sel, j_sel, ally_symbol, rival_symbol, x_delta, y_delta) || success;
        }
    }

    if (success)
    {
        cell[i_sel][j_sel] = ally_symbol;
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
        int i_sel;
        int j_sel;

        cout << "Please select a cell (i, j)." << endl;

        bool success = false;

        while (!success)
        {
            cout << "i j --> ";
            cin >> i_sel >> j_sel;

            success = try_and_set(cell, i_sel, j_sel, ally_symbol, rival_symbol);

            /* エラーチェック */
            if (!success)
            {
                cout << "Error! Please select again." << endl;
            }
            else
            {
                cell[i_sel][j_sel] = ally_symbol;
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

    display(cell);

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