#include <stdio.h>
#include <math.h>
#include <string.h>

char digits[] = "0123456789ABCDEF";

int convert_to_dec(char T[], int b)
{
    int decimal = 0;
    for (int i = 0; i < strlen(T); i++)
        decimal += (strchr(digits, T[i]) - digits) * pow(b, strlen(T) - 1 - i);
    return decimal;
}

int narcisstic_number(char T[], int m)
{
    int summary = 0;
    for (int i = 0; i < m; i++)
        summary += pow((strchr(digits, T[i]) - digits), m);
    return summary;
}

int main()
{
    int m = 0, b = 0;
    scanf("%d %d", &m, &b);
    if (m <= 0 || b <= 0)
        return 1;
    int flag = 0;
    int decimal, summary;
    char T[m + 1];
    char S[m + 1];
    for (int i = 0; i < m; i++)
    {
        T[i] = '0';
        S[i] = '0';
    }
    T[m] = '\0';
    S[m] = '\0';
    while (1)
    {
        decimal = convert_to_dec(T, b);
        summary = narcisstic_number(T, m);
        if (decimal == summary && T[0] != '0')
        {
            printf("%s ", T);
            flag = 1;
        }
        for (int j = m - 1; j > -1; j--)
        {
            if (T[j] != digits[b - 1])
            {
                int k = strchr(digits, T[j]) - digits + 1;
                T[j] = digits[k];
                break;
            }
            else
                T[j] = digits[0];
        }
        if (strcmp(T, S) == 0)
            break;
    }
    if (flag == 0)
        printf("NO\n");
    return 0;
}