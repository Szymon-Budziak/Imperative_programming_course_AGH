#include <stdio.h>

int main()
{
    int n;
    if (scanf("%d", &n))
    {
    };
    int T[n][n];
    int is_empty = 0;
    int number;
    for (int a = 0; a < n; a++)
        for (int b = 0; b < n; b++)
        {
            if (scanf("%d", &number))
            {
            };
            T[a][b] = number;
            is_empty |= number;
        }
    if (!is_empty)
    {
        printf("%d\n", n * n);
        return 0;
    }
    int max_field = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int length = 1, max_length = 0;
            while (j + max_length < n && T[i][j + max_length] != 1)
            {
                int height = 1, max_height = 0;
                while (i + max_height < n && T[i + max_height][j] != 1)
                {
                    int field = height * length;
                    int flag = 1;
                    for (int k = i; k < i + height; k++)
                    {
                        for (int l = j; l < j + length; l++)
                        {
                            if (T[k][l] == 1)
                            {
                                flag = 0;
                                break;
                            }
                        }
                    }
                    if (field > max_field && flag == 1)
                    {
                        max_field = field;
                    }
                    height++;
                    max_height++;
                }
                length++;
                max_length++;
            }
        }
    printf("%d\n", max_field);
    return 0;
}