#include <iostream>
#include <cmath>

using namespace std;

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

int upsidedown(int N)
{
    int N_count = N;
    int u = 0;

    for (int i = 0; i < digit(N); i++)
    {
        int n = N_count % 10;
        N_count /= 10;

        if (n == 6)
        {
            n = 9;
        }
        else if (n == 9)
        {
            n = 6;
        }
        else if (n == 3 || n == 4 || n == 7)
        {
            return 10; // Error number
        }

        u += n * pow(10, digit(N) - i - 1);
    }

    return u;
}

int main()
{
    int count = 0;

    for (long long int i = 1000; i < 10000; i++)
    {
        for (long long int j = i; j < 10000; j++)
        {
            long long int buf = i * j;
            long long int I = upsidedown(i);
            long long int J = upsidedown(j);

            if (J != 10 && I != 10 && i != upsidedown(i) && j != upsidedown(j) && i != upsidedown(j) && J * I == buf)
            {
                cout << i << " * " << j << " = " << J << " * " << I << endl;
                cout << " = " << buf << endl;

                cout << endl;
                count++;
            }
        }
    }

    cout << count << " examples were found." << endl;

    return 0;
}