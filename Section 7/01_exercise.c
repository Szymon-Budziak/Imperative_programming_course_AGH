#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count = 0;

void print_binary_string(int *T, int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%d", T[i]);
    }
    printf("\n");
}

int find_exact_binary_string(int *T, int N)
{
    for (int i = 1; i < N; i++)
    {
        if (T[i - 1] == T[i] && T[i] == 1)
            return 0;
    }
    return 1;
}

void generate_all_binary_strings(int *T, int N, int i, int K)
{
    if (N == i)
    {
        if (find_exact_binary_string(T, N) == 1)
            count++;
        if (count == K)
        {
            print_binary_string(T, N);
            exit(0);
        }
        return;
    }
    T[i] = 0;
    generate_all_binary_strings(T, N, i + 1, K);
    T[i] = 1;
    generate_all_binary_strings(T, N, i + 1, K);
}

int main()
{
    int N, K;
    if (scanf("%d %d", &N, &K))
    {
    };
    int *T = malloc(pow(2, N) * sizeof(int));
    generate_all_binary_strings(T, N, 0, K);
    if (count != K)
    {
        int x = -1;
        printf("%d", x);
    }
    free(T);
    return 0;
}