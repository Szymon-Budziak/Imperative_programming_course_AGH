#include <stdio.h>

int Fibonacci(int n)
{
    int a = 0;
    int b = 1;
    int c;
    while (a * b < n)
    {
        c = a + b;
        a = b;
        b = c;
    }
    if (a * b == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int result = Fibonacci(n);
    if (result == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}