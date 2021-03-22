#include <stdio.h>

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

int transfer_number(int number)
{
    int result = 0;
    int digit = 0;
    if (number == 1)
        return 0;
    while (number != 1 && number != 4)
    {
        while (number > 0)
        {
            digit = number % 10;
            result += (digit * digit);
            number /= 10;
        }
        number = result;
        result = 0;
    }
    if (number == 1)
        return 1;
    else
        return 0;
}

int main()
{
    int L, U, K;
    scanf("%d %d %d", &L, &U, &K);
    int result = 0, summary = 0;
    int flag = -1;
    for (int i = L; i <= U; i++)
    {
        result = transfer_number(i);
        if (result == 1 && is_prime_number(i) == 1)
            summary++;
        if (summary == K)
        {
            printf("%d\n", i);
            flag = 1;
            break;
        }
    }
    if (flag == -1)
    {
        printf("%d\n", flag);
    }
    return 0;
}