#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, l;
    if(scanf("%d %d %d", &n, &k, &l)){};
    int **T = malloc(n * sizeof(int *));
    int **P = malloc(k * sizeof(int *));
    for (int i=0; i<n; i++)
    {
        T[i] = malloc(n * sizeof(int));
        for (int j=0; j<n; j++)
            if(scanf("%d", &T[i][j])){};
    }
    for (int i=0; i<k; i++)
    {
        P[i] = malloc(l * sizeof(int));
        for (int j=0; j<l; j++)
            if(scanf("%d", &P[i][j])){};
    }
    int max_result = 0;
    for (int i=0; i<n-k; i++)
        for (int j=0; j<n-l; j++)
        {
            int result = 0;
            for (int a=0; a<k; a++)
                for (int b=0; b<l; b++)
                {
                    if (P[a][b] == 1)
                    {
                        result += T[i+a][j+b];
                    }
                }
            if (result > max_result)
                max_result = result;
        }
    printf("%d", max_result);
    free(T);
    free(P);
    return 0;
}
