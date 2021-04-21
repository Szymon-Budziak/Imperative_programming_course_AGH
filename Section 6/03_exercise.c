#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    if (scanf("%d %d", &n, &m))
    {
    };
    int **T = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        T[i] = malloc(n * sizeof(int));
    int val1, val2;
    for (int i = 0; i < m; i++)
    {
        if (scanf("%d", &val1))
        {
        };
        if (scanf("%d", &val2))
        {
        };
        T[val1 - 1][val2 - 1] = 1;
    }
    int result = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
            {
                if (T[i][j] == 1 && T[i][k] == 1 && T[j][k] == 1)
                    result++;
                else if (T[i][j] == 0 && T[i][k] == 0 && T[j][k] == 0)
                    result++;
            }
    printf("%d\n", result);
    free(T);
    return 0;
}