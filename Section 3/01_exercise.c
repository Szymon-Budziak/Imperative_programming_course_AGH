#include <stdio.h>
#include <math.h>

int partition(int T[], int p, int r)
{
    int pivot = T[r];
    int i = p - 1;
    int temp;
    for (int j = p; j < r; j++)
    {
        if (T[j] <= pivot)
        {
            i++;
            temp = T[i];
            T[i] = T[j];
            T[j] = temp;
        }
    }
    temp = T[i + 1];
    T[i + 1] = T[r];
    T[r] = temp;
    return i + 1;
}

void quicksort(int T[], int p, int r)
{
    while (p < r)
    {
        int q = partition(T, p, r);
        quicksort(T, p, q - 1);
        p = q + 1;
    }
}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    int T[N];
    int result = 0, copy = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &T[i]);
        result += T[i];
    }
    quicksort(T, 0, N - 1);
    for (int j = 0; j < K; j++)
    {
        if (T[N - 1] < T[N - 2])
        {
            int index = N - 1;
            int prev_index = N - 2;
            while (T[index] < T[prev_index])
            {
                int temp = T[index];
                T[index] = T[prev_index];
                T[prev_index] = temp;
                index--;
                prev_index--;
            }
        }
        copy = T[N - 1];
        T[N - 1] = floor(T[N - 1] / 2);
        result -= (copy - T[N - 1]);
    }
    printf("%d\n", result);
    return 0;
}