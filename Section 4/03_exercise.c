#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, r, rad;
    scanf("%d %d", &n, &r);
    int F[n][n];
    int T[n][n];
    for (int a = 0; a < n; a++)
        for (int b = 0; b < n; b++)
            scanf("%d", &F[a][b]);
    int i;
    int j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            int count = 0;
            for (int k = 0; k < n; k++)
            {
                if (k - i > r)
                    break;
                for (int m = 0; m < n; m++)
                {
                    if (k == i && m == j && F[k][m] == 1)
                        count++;
                    else if (abs(k - i) <= r && abs(m - j) <= r && F[k][m] == 1)
                        count++;
                    else if (m - j > r)
                        break;
                }
            }
            printf("%d ", count);
        }
        printf("\n");
    }
    return 0;
}