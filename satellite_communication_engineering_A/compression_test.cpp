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

string get_binary_code_str(int n, int size)
{
    int binary_code = 0;
    for (int i = 0; n > 0; i++)
    {
        binary_code = binary_code + (n % 2) * pow(10, i);
        n /= 2;
    }

    string binary_code_str;

    for (int i = 0; i < size - get_digit(binary_code); i++)
    {
        binary_code_str += '0';
    }

    binary_code_str += to_string(binary_code);

    return binary_code_str;
}

int main()
{
    // fileの読み込み
    ifstream ifs("satellite_abstract.txt");
    if (ifs.fail())
    {
        cerr << "Failed to open file." << endl;
        return -1;
    }

    string input_str;
    vector<string> txt_data;
    while (getline(ifs, input_str))
    {
        txt_data.emplace_back(input_str);
    }

    // 各文字の出現回数カウント、文字のset作成
    unordered_map<char, int> char_count;
    unordered_set<char> char_set;
    int total_txt_len = 0;

    for (auto str : txt_data)
    {
        total_txt_len += str.length();

        for (auto c : str)
        {
            if (char_count.find(c) == char_count.end())
            {
                char_count.insert(make_pair(c, 0));
            }

            char_count.at(c)++;
            char_set.emplace(c);
        }
    }

    // sortのためchar_countのvalueをkeyとするmultimapを作る
    multimap<int, char> char_count_reverse;
    for (auto char_count_pair : char_count)
    {
        char_count_reverse.insert(make_pair(char_count_pair.second, char_count_pair.first));
    }

    // 一般的な割り当て
    unordered_map<char, string> common_allocation;
    int n = 0;
    for (auto c : char_set)
    {
        common_allocation.emplace(make_pair(c, get_binary_code_str(n, char_set.size())));
        n++;
    }

    // 圧縮コードの割り当て
    unordered_map<char, string> haffman_allocation;
    int comparison = 0;
    for (auto it = char_count_reverse.begin(); it != char_count_reverse.end() - 1; it++)
    {
        haffman_allocation.insert(make_pair((*it).second, ""));
        if ((*it).first + comparison <= (*(it + 1)).first)
        {
            for(auto it2 = char_count_reverse.begin(); it2 != it; it2++){
                haffman_allocation.at((*it2).second) += '0';
            }
            haffman_allocation.at((*it + 1).second) += '1';
        }
        else
        {
            for(auto it2 = char_count_reverse.begin(); it2 != it; it2++){
                haffman_allocation.at((*it2).second) += '1';
            }
            haffman_allocation.at((*it + 1).second) += '0';
        }

        comparison = (*it).first + (*(it + 1)).first;
    }

    // 符号化
    string common_coding;
    string haffman_coding;
    for (auto str : txt_data)
    {
        for (auto c : str)
        {
            common_coding += common_allocation.at(c);
            haffman_coding += common_allocation.at(c);
        }
    }

    double compression_rate = haffman_coding.length() / common_coding.length();
    cout << compression_rate << endl;

    return 0;

    // FILE *input_txt_file;
    // char file_name[] = "satellite_abstract.txt";

    // input_txt_file = fopen(file_name, "r");

    // if (input_txt_file == NULL)
    // {
    //     cout << "cannot open the file: " << file_name << endl;
    //     return 0;
    // }
}