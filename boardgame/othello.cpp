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

bool try_and_set_right(char (&cell)[NUM + 1][NUM + 1], int i_sel, int j_sel, char ally_symbol, char rival_symbol)
{
    for (int k = 1; k <= (NUM - j_sel); k++)
    {
        if (cell[i_sel][j_sel + k] == ' ')
        {
            break;
        }
        else if ((cell[i_sel][j_sel + k] == ally_symbol) && (k != 1))
        {
            for (int k_change = 1; k_change < k; k_change++)
            {
                cell[i_sel][j_sel + k_change] = ally_symbol;
            }
            return true;
        }
    }
    return false;
}

bool try_and_set_left(char (&cell)[NUM + 1][NUM + 1], int i_sel, int j_sel, char ally_symbol, char rival_symbol)
{
    for (int k = 1; k <= (j_sel - 1); k++)
    {
        if (cell[i_sel][j_sel - k] == ' ')
        {
            break;
        }
        else if ((cell[i_sel][j_sel - k] == ally_symbol) && (k != 1))
        {

            for (int k_change = 1; k_change < k; k_change++)
            {
                cell[i_sel][j_sel - k_change] = ally_symbol;
            }
            return true;
        }
    }

    return false;
}

bool try_and_set_down(char (&cell)[NUM + 1][NUM + 1], int i_sel, int j_sel, char ally_symbol, char rival_symbol)
{
    for (int k = 1; k <= (NUM - i_sel); k++)
    {
        if (cell[i_sel + k][j_sel] == ' ')
        {
            break;
        }
        else if ((cell[i_sel + k][j_sel] == ally_symbol) && (k != 1))
        {

            for (int k_change = 1; k_change < k; k_change++)
            {
                cell[i_sel + k_change][j_sel] = ally_symbol;
            }
            return true;
        }
    }

    return false;
}
bool try_and_set_up(char (&cell)[NUM + 1][NUM + 1], int i_sel, int j_sel, char ally_symbol, char rival_symbol)
{
    for (int k = 1; k <= (i_sel - 1); k++)
    {
        if (cell[i_sel - k][j_sel] == ' ')
        {
            break;
        }
        else if ((cell[i_sel - k][j_sel] == ally_symbol) && (k != 1))
        {

            for (int k_change = 1; k_change < k; k_change++)
            {
                cell[i_sel - k_change][j_sel] = ally_symbol;
            }
            return true;
        }
    }
    return false;
}

bool try_and_set_right_down(char (&cell)[NUM + 1][NUM + 1], int i_sel, int j_sel, char ally_symbol, char rival_symbol)
{
    for (int k = 1; k <= min(NUM - i_sel, NUM - j_sel); k++)
    {
        if (cell[i_sel + k][j_sel + k] == ' ')
        {
            break;
        }
        else if ((cell[i_sel + k][j_sel + k] == ally_symbol) && (k != 1))
        {

            for (int k_change = 1; k_change < k; k_change++)
            {
                cell[i_sel + k_change][j_sel + k_change] = ally_symbol;
            }
            return true;
        }
    }

    return false;
}

bool try_and_set_right_up(char (&cell)[NUM + 1][NUM + 1], int i_sel, int j_sel, char ally_symbol, char rival_symbol)
{
    for (int k = 1; k <= min(i_sel - 1, NUM - j_sel); k++)
    {
        if (cell[i_sel - k][j_sel + k] == ' ')
        {
            break;
        }
        else if ((cell[i_sel - k][j_sel + k] == ally_symbol) && (k != 1))
        {

            for (int k_change = 1; k_change < k; k_change++)
            {
                cell[i_sel - k_change][j_sel + k_change] = ally_symbol;
            }
            return true;
        }
    }

    return false;
}

bool try_and_set_left_down(char (&cell)[NUM + 1][NUM + 1], int i_sel, int j_sel, char ally_symbol, char rival_symbol)
{
    for (int k = 1; k <= min(NUM - i_sel, j_sel - 1); k++)
    {
        if (cell[i_sel + k][j_sel - k] == ' ')
        {
            break;
        }
        else if ((cell[i_sel + k][j_sel - k] == ally_symbol) && (k != 1))
        {

            for (int k_change = 1; k_change < k; k_change++)
            {
                cell[i_sel + k_change][j_sel - k_change] = ally_symbol;
            }
            return true;
        }
    }

    return false;
}
bool try_and_set_left_up(char (&cell)[NUM + 1][NUM + 1], int i_sel, int j_sel, char ally_symbol, char rival_symbol)
{
    for (int k = 1; k <= min(i_sel - 1, j_sel - 1); k++)
    {
        if (cell[i_sel - k][j_sel - k] == ' ')
        {
            break;
        }
        else if ((cell[i_sel - k][j_sel - k] == ally_symbol) && (k != 1))
        {

            for (int k_change = 1; k_change < k; k_change++)
            {
                cell[i_sel - k_change][j_sel - k_change] = ally_symbol;
            }
            return true;
        }
    }
    return false;
}

bool try_and_set(char (&cell)[NUM + 1][NUM + 1], int i_sel, int j_sel, char ally_symbol, char rival_symbol)
{
    if (cell[i_sel][j_sel] != ' ')
    {
        return true;
    }

    /* サーチ */
    bool success = false;
    /* 右サーチ */
    if (j_sel < NUM - 1)
    {
        success = success || try_and_set_right(cell, i_sel, j_sel, ally_symbol, rival_symbol);
    }

    /* 左サーチ */
    if (j_sel > 2)
    {
        success = success || try_and_set_right(cell, i_sel, j_sel, ally_symbol, rival_symbol);
    }

    /* 下サーチ */
    if (i_sel < NUM - 1)
    {
        success = success || try_and_set_right(cell, i_sel, j_sel, ally_symbol, rival_symbol);
    }

    /* 上サーチ */
    if (i_sel > 2)
    {
        success = success || try_and_set_right(cell, i_sel, j_sel, ally_symbol, rival_symbol);
    }

    /* 右下サーチ */
    if (!((i_sel > NUM - 2) || (j_sel > NUM - 2)))
    {
        success = success || try_and_set_right(cell, i_sel, j_sel, ally_symbol, rival_symbol);
    }

    /* 右上サーチ */
    if (!((i_sel < 2) || (j_sel > NUM - 2)))
    {
        success = success || try_and_set_right(cell, i_sel, j_sel, ally_symbol, rival_symbol);
    }

    /* 左下サーチ */
    if (!((i_sel > NUM - 2) || (j_sel < 2)))
    {
        success = success || try_and_set_right(cell, i_sel, j_sel, ally_symbol, rival_symbol);
    }

    /* 左上サーチ */
    if (!((i_sel < 2) || (j_sel < 2)))
    {
        success = success || try_and_set_right(cell, i_sel, j_sel, ally_symbol, rival_symbol);
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