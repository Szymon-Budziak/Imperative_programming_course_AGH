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
    int N = 0, K = 0;
    scanf("%d %d", &N, &K);
    int T[N];
    int result = 0;
    for (int i = 0; i < N; i++)
        scanf("%d", &T[i]);
    qsort(T, sizeof(T) / sizeof(*T), sizeof(*T), compare);
    int j = 0;
    while (j < N)
    {
        int k = j;
        int count = 0;
        while (T[k] == T[j] && k != N)
        {
            k++;
            count++;
        }
        if (T[j - 1] + K >= T[j] && j != 0)
            result += count;
        else if (T[k] - K <= T[k - 1] && k != N)
            result += count;
        j = k;
    }
    printf("%d\n", result);
    return 0;
}