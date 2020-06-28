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
    // std::ifstream t("/home/acannie/github/hobby/satellite_communication_engineering_A/satellite_abstract.txt");
    // std::ifstream t("/home/acannie/github/hobby/satellite_communication_engineering_A/low_entropy.txt");
    std::ifstream t("/home/acannie/github/hobby/satellite_communication_engineering_A/high_entropy.txt");
    std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
    return str;
}

void haffman_code_allocator_allocate_sum_side_1(unordered_map<char, string> &haffman_allocation, vector<char> char_list, int depth)
{
    // sum側(すでに符号を割り当てているすべての文字)の割り当て符号は、その末尾に1を追加したものに置き換える
    for (int j = 0; j < depth; j++)
    {
        haffman_allocation.at(char_list.at(j)) += '1';
    }
    // next char側の割り当て符号を0にする
    haffman_allocation.insert(make_pair(char_list.at(depth), "0"));
}

void haffman_code_allocator_allocate_sum_side_0(unordered_map<char, string> &haffman_allocation, vector<char> char_list, int depth)
{
    // sum側(すでに符号を割り当てているすべての文字)の割り当て符号は、その末尾に0を追加したものに置き換える
    for (int j = 0; j < depth; j++)
    {
        haffman_allocation.at(char_list.at(j)) += '0';
    }
    // next char側の割り当て符号を1にする
    haffman_allocation.insert(make_pair(char_list.at(depth), "1"));
}

void compression_coding_allocator(unordered_map<char, int> char_count, unordered_map<char, string> &haffman_allocation)
{
    // FIXME ラムダ式でchar_countから直接char_listを生成する
    // つまり、multimapを使わない方法にする

    // sortのためchar_countのvalueをkeyとするmultimapを作る
    multimap<int, char> char_count_reverse;
    for (auto char_count_pair : char_count)
    {
        char_count_reverse.insert(make_pair(char_count_pair.second, char_count_pair.first));
    }

    // 出現回数順(昇順)に文字を格納したvector型の変数を作成
    vector<char> char_list;
    for (auto char_count_reverse_pair : char_count_reverse)
    {
        char_list.emplace_back(char_count_reverse_pair.second);
    }

    // 出現回数が最も小さい文字と2番目に小さい文字である、char_listの先頭2文字を取り出す
    // のちにより出現回数が大きい文字の出現回数と比較するため、和をsumに格納する
    int freq_sum = char_count.at(char_list.at(0)) + char_count.at(char_list.at(1));
    haffman_allocation.insert(make_pair(char_list.at(0), "1"));
    haffman_allocation.insert(make_pair(char_list.at(1), "0"));

    // 文字の出現回数でトーナメント表を作り、出現回数が多いほうの文字に符号0を、少ないほうの文字に符号1を割り当てる
    // FIXME 木なので再帰構造に書き換える
    for (int i = 2; i < char_list.size(); i++)
    {
        int next_char_freq = char_count.at(char_list.at(i));

        // FIXME 関数haffman_code_allocator_allocate_sum_side_0とhaffman_code_allocator_allocate_sum_side_1を統合
        if (freq_sum <= next_char_freq)
        {
            haffman_code_allocator_allocate_sum_side_1(haffman_allocation, char_list, i);
        }
        else
        {
            haffman_code_allocator_allocate_sum_side_0(haffman_allocation, char_list, i);
        }

        freq_sum += next_char_freq;
    }
}

void ordinal_coding_allocator(unordered_set<char> char_set, unordered_map<char, string> &ordinal_allocation)
{
    int n = 0;
    for (auto c : char_set)
    {
        ordinal_allocation.emplace(make_pair(c, get_binary_code_str(n, char_set.size())));
        n++;
    }
}

double get_entropy(unordered_map<char, int> char_count, int txt_file_size)
{
    double entropy = 0;

    for (auto char_count_pair : char_count)
    {
        double appearance_probability = (double)char_count_pair.second / (double)txt_file_size;
        entropy += -appearance_probability * log2(appearance_probability);
    }
    return entropy;
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

    // 順番に割り当てる
    unordered_map<char, string> ordinal_allocation;
    ordinal_coding_allocator(char_set, ordinal_allocation);

    // 圧縮コードの割り当て
    unordered_map<char, string> haffman_allocation;
    compression_coding_allocator(char_count, haffman_allocation);

    // 符号化
    string ordinal_coding;
    string haffman_coding;
    for (auto c : file_txt)
    {
        ordinal_coding += ordinal_allocation.at(c);
        haffman_coding += haffman_allocation.at(c);
    }

    cout << "the entropy is " << get_entropy(char_count, file_txt.length()) << endl;
    cout << "the compression rate is " << (double)haffman_coding.length() / (double)ordinal_coding.length() << endl;

    return 0;
}