#include <stdio.h>

int check_number(int n)
{
    int last;
    int prev = 10;
    while (n > 0)
    {
        last = n % 10;
        n /= 10;
        if (last > prev)
        {
            return 0;
        }
        prev = last;
    }
    return 1;
}

int is_prime_number(int n)
{
    if (n == 2 || n == 3)
    {
        return 1;
    }
    else if (n < 2 || n % 2 == 0 || n % 3 == 0)
    {
        return 0;
    }
    else
    {
        int i = 5;
        while (i * i <= n)
        {
            if (n % i == 0)
            {
                return 0;
            }
            i += 2;
            if (n % i == 0)
            {
                return 0;
            }
            i += 4;
        }
        return 1;
    }
}

int main()
{
    int n;
    int i;
    scanf("%d", &n);
    for (i = 2; i <= n; i++)
    {
        if (is_prime_number(i) == 1 && check_number(i) == 1)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}