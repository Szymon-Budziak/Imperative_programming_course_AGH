#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int elem1 = *((int *)a);
    int elem2 = *((int *)b);
    if (elem1 > elem2)
        return 1;
    if (elem1 < elem2)
        return -1;
    return 0;
}

int main()
{
    int N;
    scanf("%d", &N);
    if (N<2 | N> 100)
        return 0;
    int t1[N][N];
    int t2[N * N];
    for (int a = 0; a < N; a++)
    {
        for (int b = 0; b < N; b++)
            scanf("%d", &t1[a][b]);
    }
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            t2[k] = t1[i][j];
            k++;
        }
    }
    qsort(t2, sizeof(t2) / sizeof(*t2), sizeof(*t2), compare);
    for (int x = 0; x < N * N; x++)
    {
        if (t2[x] != t2[x + 1])
            printf("%d ", t2[x]);
    }
    printf("\n");
    return 0;
}