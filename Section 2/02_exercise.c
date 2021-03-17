#include <stdio.h>
#include <math.h>
#include <string.h>

char value(int number)
{
    if (number >= 0 && number <= 9)
        return (char)(number + '0');
    else
        return (char)(number - 10 + 'A');
}

void reverse(char *string)
{
    int len = strlen(string);
    for (int i = 0; i < len / 2; i++)
    {
        char temporary = string[i];
        string[i] = string[len - i - 1];
        string[len - i - 1] = temporary;
    }
}

int main()
{
    int m = 0, b = 0;
    scanf("%d %d", &m, &b);
    int flag = 0;
    if (b == 10)
    {
        for (int i = 0; i <= 1000000; i++)
        {
            int original = i;
            int result = 0;
            int index = 0;
            int rem = 0;
            while (original > 0)
            {
                rem = original % 10;
                original /= 10;
                result += pow(rem, m);
                index += 1;
            }
            if (result == i && index == m)
            {
                printf("%d ", i);
                flag = 1;
            }
        }
    }
    else
    {
        for (int i = 0; i <= 1000000; i++)
        {
            char T[m + 1];
            int j = 0;
            int index = 0;
            int original = i;
            int copy = i;
            long int result = 0;
            while (original > 0)
            {
                copy = original % b;
                result += pow(copy, m);
                T[j++] = value(copy);
                original /= b;
                index += 1;
            }
            reverse(T);
            T[j] = '\0';
            if (result == i && index == m)
            {
                printf("%s ", T);
                flag = 1;
            }
        }
    }
    if (flag == 0)
        printf("NO");
    return 0;
}