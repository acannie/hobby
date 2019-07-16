#include <iostream>
using namespace std;

int func1(int n)
{
    int c;
    int n1 = 1, n2 = 1;

    if (n == 0)
    {
        c = 1;
    }
    else if (n == 1)
    {
        c = 1;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            c = n1 + n2;
            n2 = n1;
            n1 = c;
        }
    }

    printf("%d : %d\n", n, c);
    return c;
}

int main(void)
{
    func1(0);
    func1(1);
    func1(2);
    func1(3);
    func1(4);
    func1(5);

    return 0;
}