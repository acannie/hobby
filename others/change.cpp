#include <iostream>
#include <cmath>
using namespace std;

struct change_list
{
    int money;
    int need;
    int exist;
    bool bill;
};

// 桁数を求める関数
int ketasu(int n)
{
    int count = 0;

    while (n > 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}

// 計算するプログラム
int aaa(struct change_list a, int margin)
{
    int lack;

    if (a.exist < a.need + margin)
    {
        lack = a.need + margin - a.exist;
    }

    cout << a.money << "===" << lack / 50 + 1 << endl;

    return 0;
}

int main()
{
    int money_type = 9;
    int bar = 50;

    struct change_list Ringerhut[money_type];

    int buf = 10000;
    for (int i = 0; i < money_type; i++)
    {
        Ringerhut[i].money = buf;

        if (i % 2 == 0)
        {
            buf /= 2;
        }
        else
        {
            buf /= 5;
        }
    }

    cout << "Input the current number of each money." << endl;

    for (int i = 0; i < money_type; i++)
    {
        for (int i = 0; i < 5 - ketasu(Ringerhut[i].money); i++)
        {
            cout << " ";
        }

        cout << Ringerhut[i].money << " --> ";
        cin >> Ringerhut[i].exist;

        if (Ringerhut[i].money >= 1000)
        {
            Ringerhut[i].bill = true;
        }
        else
        {
            Ringerhut[i].bill = false;
        }
    }

    Ringerhut[0].need = 0;
    Ringerhut[1].need = 10;
    Ringerhut[2].need = 32;
    Ringerhut[3].need = 50;
    Ringerhut[4].need = 351;
    Ringerhut[5].need = 100;
    Ringerhut[6].need = 200;
    Ringerhut[7].need = 100;
    Ringerhut[8].need = 400;

    /*
    Ringerhut[0].margin = 0;
    Ringerhut[1].margin = 4;
    Ringerhut[2].margin = 12;
    Ringerhut[3].margin = 15;
    Ringerhut[4].margin = 50;
    Ringerhut[5].margin = 15;
    Ringerhut[6].margin = 50;
    Ringerhut[7].margin = 15;
    Ringerhut[8].margin = 50;
    */

    // 計算

    int exchange = 0;

    for (int i = 0; i < money_type; i++)
    {
        if (Ringerhut[i].money == 5000)
        {
            exchange += aaa(Ringerhut[i], 4);
        }
        else if (Ringerhut[i].money == 1000)
        {
            exchange += aaa(Ringerhut[i], 10);
        }
        else if (Ringerhut[i].bill == false)
        {
            if (Ringerhut[i].money / pow(10, ketasu(Ringerhut[i].money)) == 1)
            {
                exchange += aaa(Ringerhut[i], 50);
            }
            else
            {
                exchange += aaa(Ringerhut[i], 15);
            }
        }
    }

    if (exchange < Ringerhut[0].money * Ringerhut[0].exist)
    {
        cout << "bring" << exchange / 10000 + 1 << Ringerhut[0].money << "bills." << endl;
    }

    return 0;
}