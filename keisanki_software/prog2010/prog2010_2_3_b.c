#include <stdio.h>

int func3(int n, int a, int b)
{
    if (n == 0)
    {
        printf("%d: %d\n", n, a);
        return a;
    }
    else
    {
        printf("%d: %d: %d\n", n, a, b);
        return func3(n - 1, b, a + b);
    }
}

int func2(int n)
{
    return func3(n, 1, 1);
}

int main()
{
    /* func2の実行 */
    func2(5);

    /* 返り値の確認 */
    int a = func2(5);
    printf("\nreturn of func3(n, 1, 1) is %d.\n", a);

    return 0;
}