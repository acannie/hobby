#include <iostream>
#include <string>
#include <utf8.h>
using namespace std;

int main()
{
    string japanese;

    japanese = u8'あいうえお';

    cout << japanese << endl;

    cout << 'かきくけこ' << endl;

    return 0;
}