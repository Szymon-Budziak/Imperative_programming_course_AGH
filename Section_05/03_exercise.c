#include <stdio.h>
#include <stdlib.h>

void print_solution(int *rows, int *cols, int count)
{
    printf("%d\n", count);
    for (int i = 0; i < count; i++)
    {
        printf("%d %d\n", rows[i], cols[i]);
    }
}

int main(void)
{
    int n, k;
    if (scanf("%d %d", &n, &k))
    {
    };
    int T[n][n];
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (scanf("%d", &T[i][j]))
            {
            };
    int *rows = malloc(n * n * sizeof(int));
    int *cols = malloc(n * n * sizeof(int));
    int count = 0;
    for (i = 1; i < n; i++)
        for (j = 1; j < n; j++)
            for (int l = 1; l < n; l++)
            {
                if (i + l >= n || j + l >= n || i - l < 0 || j - l < 0)
                    break;
                int summary = 0;
                int num_of_elems = 1;
                for (int a = i - l; a <= i + l; a++)
                    for (int b = j - l; b <= j + l; b++)
                    {
                        if (a != i || b != j)
                        {
                            summary += T[a][b];
                            num_of_elems++;
                        }
                    }
                if (summary == k && num_of_elems % 2 == 1)
                {
                    rows[count] = i;
                    cols[count] = j;
                    count++;
                }
            }
    print_solution(rows, cols, count);
    free(rows);
    free(cols);
}