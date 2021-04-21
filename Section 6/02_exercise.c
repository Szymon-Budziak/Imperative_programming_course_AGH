#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_value_in_roman(char string)
{
    char T[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int values[] = {1, 5, 10, 50, 100, 500, 1000};
    long unsigned int len = sizeof(values) / sizeof(int);
    for (int i = 0; i < len; i++)
    {
        if (string == T[i])
            return values[i];
    }
    return -1;
}

int convert_to_decimal(char string[])
{
    int result = 0;
    long unsigned int length = strlen(string);
    for (int i = 0; i < length; i++)
    {
        int number1 = check_value_in_roman(string[i]);
        if (i + 1 < length)
        {
            int number2 = check_value_in_roman(string[i + 1]);
            if (number1 >= number2)
                result += number1;
            else
            {
                result += (number2 - number1);
                i++;
            }
        }
        else
            result += number1;
    }
    return result;
}

void convert_to_roman(int number)
{
    char *T[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    int len = sizeof(values) / sizeof(int);
    while (number != 0)
    {
        for (int i = 0; i < len; i++)
            if (number >= values[i])
            {
                printf("%s", T[i]);
                number -= values[i];
                break;
            }
    }
    printf("\n");
}

int main()
{
    char *string1 = malloc(10 * sizeof(char));
    char *string2 = malloc(10 * sizeof(char));
    if (scanf("%s %s", string1, string2))
    {
    };
    int value1, value2;
    value1 = convert_to_decimal(string1);
    value2 = convert_to_decimal(string2);
    int value = value1 + value2;
    convert_to_roman(value);
    free(string1);
    free(string2);
    return 0;
}