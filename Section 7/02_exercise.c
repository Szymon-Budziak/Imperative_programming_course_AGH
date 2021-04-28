#include <stdio.h>
#include <stdlib.h>

int comparison(int number1, int number2)
{
    if (number1 > number2)
        return number1;
    return number2;
}

int find_max_section(int **T, int n, int k, int i, int j)
{
    int max_section = 0;

    // top
    int summary = 0;
    for (int m = 0; m<k; m++)
        summary += T[(i-m+n)%n][j];
    max_section = comparison(summary, max_section);

    // top right
    summary = 0;
    for (int m = 0; m<k; m++)
        summary += T[(i-m+n)%n][(j+m+n)%n];
    max_section = comparison(summary, max_section);

    // right
    summary = 0;
    for (int m = 0; m<k; m++)
        summary += T[i][(j+m+n)%n];
    max_section = comparison(summary, max_section);

    // bottom right
    summary = 0;
    for (int m = 0; m<k; m++)
        summary += T[(i+m+n)%n][(j+m+n)%n];
    max_section = comparison(summary, max_section);

    // bottom
    summary = 0;
    for (int m = 0; m<k; m++)
        summary += T[(i+m+n)%n][j];
    max_section = comparison(summary, max_section);

    // bottom left
    summary = 0;
    for (int m = 0; m<k; m++)
        summary += T[(i-m+2*n)%n][(j-m+2*n)%n];
    max_section = comparison(summary, max_section);

    // left
    summary = 0;
    for (int m = 0; m<k; m++)
        summary += T[i][(j-m+n)%n];
    max_section = comparison(summary, max_section);

    // top left
    summary = 0;
    for (int m = 0; m<k; m++)
        summary += T[(j-m+n)%n][(j-m+n)%n];
    max_section = comparison(summary, max_section);
    return max_section;
}


int main()
{
    int n, k;
    if(scanf("%d %d", &n, &k)){};
    int **T = malloc(n * sizeof(int *));
    for (int i=0; i<n; i++)
    {
        T[i] = malloc(n * sizeof(int));
        for (int j=0; j<n; j++)
            if(scanf("%d", &T[i][j]));
    }
    int max_section = 0;
    int actual_section;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        {
            actual_section = find_max_section(T, n, k, i, j);
            max_section = comparison(actual_section, max_section);
        }
    printf("%d", max_section);
    for (int i=0; i<n; i++)
        free(T[i]);
    free(T);
    return 0;
}
