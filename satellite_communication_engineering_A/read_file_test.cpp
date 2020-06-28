#include <bits/stdc++.h>
using namespace std;

int main()
{
    // fileの読み込み
    ifstream ifs("./satellite_abstract.txt");
    if (ifs.fail())
    {
        cerr << "Failed to open file." << endl;
        return -1;
    }

    string input_str;

    while (getline(ifs, input_str))
    {
        cout << input_str << endl;
    }

    return 0;
}