#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n))
    {
    };
    int T[n][n];
    int value = 1;
    int row = 0;
    int col = n - 1;
    int j = 0;
    int i = 0;
    while (row <= col)
    {
        for (j = row; j <= col; j++)
        {
            T[row][j] = value;
            value++;
        }
        row++;
        for (j = row; j <= col; j++)
        {
            T[j][col] = value;
            value++;
        }
        col--;
        for (j = col; j >= row - 1; j--)
        {
            T[col + 1][j] = value;
            value++;
        }
        for (j = col; j >= row; j--)
        {
            T[j][row - 1] = value;
            value++;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", T[i][j]);
        printf("\n");
    }
}