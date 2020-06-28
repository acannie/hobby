#include <bits/stdc++.h>
using namespace std;

int get_digit(int n)
{
    int digit = 0;
    while (n > 0)
    {
        n /= 10;
        digit++;
    }
    return digit;
}

int get_digit_binary(int n)
{
    int digit = 0;
    while (n > 0)
    {
        n /= 2;
        digit++;
    }
    return digit;
}

string get_binary_code_str(int n, int size)
{
    int binary_code = 0;
    for (int i = 0; n > 0; i++)
    {
        binary_code = binary_code + (n % 2) * pow(10, i);
        n /= 2;
    }

    string binary_code_str;
    int loop_count = get_digit_binary(size) - get_digit(binary_code);

    for (int i = 0; i < loop_count; i++)
    {
        binary_code_str += '0';
    }

    if (get_digit(binary_code) != 0)
    {
        binary_code_str += to_string(binary_code);
    }
    return binary_code_str;
}

string get_text()
{
    std::ifstream t("/home/acannie/github/hobby/satellite_communication_engineering_A/satellite_abstract.txt");
    std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
    return str;
}

void compression_coding_allocation(multimap<int, char> char_count_reverse, unordered_map<char, string> &haffman_allocation)
{
    int comparison = 0;
    for (auto it = char_count_reverse.begin(); it != prev(char_count_reverse.end()); it++)
    {
        haffman_allocation.insert(make_pair((*it).second, ""));

        haffman_allocation.at((*it).second) += '1';

        if ((*it).first + comparison <= (*(next(it))).first)
        {
            for (auto it2 = char_count_reverse.begin(); it2 != it; it2++)
            {
                haffman_allocation.at((*it2).second) += '0';
            }
            haffman_allocation.at((*(next(it))).second) += '1';
        }
        else
        {
            for (auto it2 = char_count_reverse.begin(); it2 != it; it2++)
            {
                haffman_allocation.at((*it2).second) += '1';
            }
            haffman_allocation.at((*(next(it))).second) += '0';
        }

        comparison = (*it).first + (*(next(it))).first;
    }
}

int main()
{
    string file_txt = get_text();

    //各文字の出現回数カウント、文字のset作成
    unordered_map<char, int> char_count;
    unordered_set<char> char_set;

    for (auto c : file_txt)
    {
        if (char_count.find(c) == char_count.end())
        {
            char_count.insert(make_pair(c, 0));
        }

        char_count.at(c)++;
        char_set.emplace(c);
    }

    // sortのためchar_countのvalueをkeyとするmultimapを作る
    multimap<int, char> char_count_reverse;
    for (auto char_count_pair : char_count)
    {
        char_count_reverse.insert(make_pair(char_count_pair.second, char_count_pair.first));
    }

    // 順番に割り当てる
    unordered_map<char, string> ordinal_allocation;
    int n = 0;
    for (auto c : char_set)
    {
        ordinal_allocation.emplace(make_pair(c, get_binary_code_str(n, char_set.size())));
        n++;
    }

    // 圧縮コードの割り当て
    unordered_map<char, string> haffman_allocation;
    compression_coding_allocation(char_count_reverse, haffman_allocation);

    // 符号化
    string ordinal_coding;
    string haffman_coding;
    for (auto c : file_txt)
    {
        ordinal_coding += ordinal_allocation.at(c);
        haffman_coding += ordinal_allocation.at(c);
    }

    double compression_rate = haffman_coding.length() / ordinal_coding.length();
    cout << compression_rate << endl;

    return 0;
}