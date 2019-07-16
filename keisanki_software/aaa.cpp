#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int h = 0;
    long long int i = 0;

    while (h == 0 || h == 1 || h == 3 || h == 4 || h == 5 || h == 9)
    {
        long long int p = pow((12 + i), 2);
        h = p % 11;
        i++;
    }

    cout << i << " " << h << endl;
    return 0;
}