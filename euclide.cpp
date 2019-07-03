#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num1, num2;
    cout << "Input 2 number. --> ";
    cin >> num1 >> num2;

    if (num1 > num2)
    {
        int tmp;
        tmp = num1;
        num1 = num2;
        num2 = tmp;
    }

    int remainder = num2 % num1;
    while (remainder != 0)
    {
        num2 = num1;
        num1 = remainder;
        remainder = num2 % num1;
    }

    cout << "GCD is " << num1 << "." << endl;
    return 0;
}