#include <stdio.h>
#include <math.h>

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
    int n = 0;
    int m = 0;
    int k = 0;
    int p = 0;
    int i = 0;
    int number = 0;
    int T[20];
    scanf("%d %d", &m, &n);
    while (pow(2, k) < n)
    {
        int x = pow(2, k) - 1;
        if (is_prime_number(x) == 1)
        {
            number = (pow(2, k - 1) * (pow(2, k) - 1));
            if (number >= m && number <= n)
            {
                T[i] = number;
                i += 1;
                p += 1;
            }
        }
        k += 1;
    }
    printf("%d\n", p);
    for (int j = 0; j < i; j++)
    {
        printf("%d ", T[j]);
    }
    return 0;
}