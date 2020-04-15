#ifndef tools_h
#define tools_h
#define N 4
#define TARGET 16

#include <bits/stdc++.h>
using namespace std;

class PowerComponent
{
private:
public:
    int digit(int n)
    {
        int count = 0;
        while (n != 0)
        {
            n /= 10;
            count++;
        }
        return count;
    }

    void output_board(vector<vector<int>> &b)
    {
        for (int i = 0; i < N; i++)
        {
            cout << "---------------------" << endl;
            for (int j = 0; j < N; j++)
            {
                int output_num = b.at(i).at(j);
                cout << "|";
                if (output_num == 0)
                {
                    cout << "    ";
                }
                else
                {
                    for (int space = 0; space < N - digit(output_num); space++)
                    {
                        cout << " ";
                    }
                    cout << output_num;
                }
            }

            cout << "|" << endl;
        }
        cout << "---------------------" << endl;
    }

    void update_state(vector<vector<int>> &nums, int vertical, int horizontal, bool *move)
    {
        vector<vector<int>> new_nums;
        for (int i = 0; i < N; i++)
        {
            new_nums.emplace_back(0);
            for (int j = 0; j < N; j++)
            {
                new_nums.at(i).emplace_back(0);
            }
        }

        if (vertical == -1 && horizontal == 0)
        {
            //up
            for (int j = 0; j < N; j++)
            {
                queue<int> tmp1;
                for (int i = 0; i < N; i++)
                {
                    int n = nums.at(i).at(j);
                    if (n != 0)
                    {
                        tmp1.push(n);
                    }
                }

                queue<int> tmp3;
                while (!tmp1.empty())
                {
                    int tmp2 = tmp1.front();
                    tmp1.pop();

                    if (!tmp1.empty() && tmp2 == tmp1.front())
                    {
                        tmp2 *= 2;
                        tmp1.pop();
                    }

                    tmp3.push(tmp2);
                }

                int tmp3_size = tmp3.size();
                new_nums.emplace_back(0);
                for (int i = 0; i < tmp3_size; i++)
                {
                    new_nums.at(i).at(j) = tmp3.front();
                    tmp3.pop();
                }
            }
        }
        else if (vertical == 0 && horizontal == -1)
        {
            //left
            for (int i = 0; i < N; i++)
            {
                queue<int> tmp1;
                for (int j = 0; j < N; j++)
                {
                    int n = nums.at(i).at(j);
                    if (n != 0)
                    {
                        tmp1.push(n);
                    }
                }

                queue<int> tmp3;
                while (!tmp1.empty())
                {
                    int tmp2 = tmp1.front();
                    tmp1.pop();

                    if (!tmp1.empty() && tmp2 == tmp1.front())
                    {
                        tmp2 *= 2;
                        tmp1.pop();
                    }

                    tmp3.push(tmp2);
                }

                int tmp3_size = tmp3.size();
                new_nums.emplace_back(0);
                for (int j = 0; j < tmp3_size; j++)
                {
                    new_nums.at(i).at(j) = tmp3.front();
                    tmp3.pop();
                }
            }
        }
        else if (vertical == 0 && horizontal == 1)
        {
            //right
            for (int i = 0; i < N; i++)
            {
                queue<int> tmp1;
                for (int j = 0; j < N; j++)
                {
                    int n = nums.at(i).at(N - j - 1);
                    if (n != 0)
                    {
                        tmp1.push(n);
                    }
                }

                queue<int> tmp3;
                while (!tmp1.empty())
                {
                    int tmp2 = tmp1.front();
                    tmp1.pop();

                    if (!tmp1.empty() && tmp2 == tmp1.front())
                    {
                        tmp2 *= 2;
                        tmp1.pop();
                    }

                    tmp3.push(tmp2);
                }

                int tmp3_size = tmp3.size();
                new_nums.emplace_back(0);
                for (int j = 0; j < tmp3_size; j++)
                {
                    new_nums.at(i).at(N - j - 1) = tmp3.front();
                    tmp3.pop();
                }
            }
        }
        else if (vertical == 1 && horizontal == 0)
        { //down
            for (int j = 0; j < N; j++)
            {
                queue<int> tmp1;
                for (int i = 0; i < N; i++)
                {
                    int n = nums.at(N - i - 1).at(j);
                    if (n != 0)
                    {
                        tmp1.push(n);
                    }
                }

                queue<int> tmp3;
                while (!tmp1.empty())
                {
                    int tmp2 = tmp1.front();
                    tmp1.pop();

                    if (!tmp1.empty() && tmp2 == tmp1.front())
                    {
                        tmp2 *= 2;
                        tmp1.pop();
                    }

                    tmp3.push(tmp2);
                }

                int tmp3_size = tmp3.size();
                new_nums.emplace_back(0);
                for (int i = 0; i < tmp3_size; i++)
                {
                    new_nums.at(N - i - 1).at(j) = tmp3.front();
                    tmp3.pop();
                }
            }
        }

        //compare nums and new_nums
        *move = false;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (nums.at(i).at(j) != new_nums.at(i).at(j))
                {
                    *move = true;
                }
            }
        }

        nums.clear();
        for (int i = 0; i < N; i++)
        {
            nums.emplace_back(new_nums.at(i));
        }
    }

    void check(vector<vector<int>> &nums, bool *game_clear, bool *game_over)
    {
        vector<pair<int, int>> empty_space;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (nums.at(i).at(j) == 0)
                {
                    empty_space.emplace_back(make_pair(i, j));
                }
                if (nums.at(i).at(j) == TARGET)
                {
                    *game_clear = true;
                    return;
                }
            }
        }

        if (empty_space.size() == 0)
        {
            *game_over = true;
            return;
        }
    }

    void add(vector<vector<int>> &nums)
    {
        random_device rnd;
        int new_num = (rnd() % 2 + 1) * 2; //2 or 4
        vector<pair<int, int>> empty_space;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (nums.at(i).at(j) == 0)
                {
                    empty_space.emplace_back(make_pair(i, j));
                }
            }
        }

        int new_num_place = rnd() % empty_space.size();
        nums.at(empty_space.at(new_num_place).first).at(empty_space.at(new_num_place).second) = new_num;
    }

    int calc_v_h(int v_h, int i)
    {
        if (v_h == 1)
        {
            return N - i - 1;
        }
        else
        {
            return i;
        }
        return 0;
    }
};

#endif