#include <iostream>
#include <cmath>
using namespace std;

int getDigit(int n) //桁数を返す関数
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}

void decomposition(int n, int digit[]) //桁をバラす関数
{
    int n_new = n;

    for (int i = 0; i < getDigit(n); i++)
    {
        digit[i] = n_new % 10;
        n_new = n_new / 10;
    }
}

int addCalculation(int n, int digit[]) //与えられた桁バラ配列に対して回文計算を行う関数
{
    int ans;

    for (int i = 0; i < getDigit(n); i++)
    {
        ans = ans + (pow(10, i) + pow(10, getDigit(n) - i - 1)) * digit[i];
    }

    return ans;
}

void showAddCalculation(int num, int digit[]){
    
}

bool palindrome(int n) //引数が回文であるか判定する関数
{
    int digit[getDigit(n)];
    decomposition(n, digit);

    bool flg = true;
    for (int i = 0; i < getDigit(n) / 2; i++)
    {
        if (digit[i] != digit[getDigit(n) - 1])
        {
            flg = false;
        }
    }

    return flg;
}

int main()
{
    int maxnum;
    cin >> maxnum;

    for (int num = 0; num < maxnum; num++)
    {
        int digit[getDigit(num)];
        decomposition(num, digit);

        int n = num;
        bool flg = false;

        for (int i = 0; i < 10; i++)
        {
            
            if (palindrome(n) == true)
            {
                flg = true;
                break;
            }
            else
            {
                n = addCalculation(n, digit);
            }
        }
        if(flg == false){
            cout << num << endl;
            showAddCalculation(num, digit);
        }
    }

    return 0;
}