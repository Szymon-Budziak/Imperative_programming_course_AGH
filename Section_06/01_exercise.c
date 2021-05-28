#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int find_x_distance(int x1, int x2)
{
    if (x1 > x2)
        return x1;
    return x2;
}

int find_y_distance(int y1, int y2)
{
    if (y1 > y2)
        return y1;
    return y2;
}

int main()
{
    int N;
    if (scanf("%d", &N))
    {
    };
    int *T = malloc(4 * N * sizeof(int));
    int i;
    int min_x = INT_MAX;
    int max_x = INT_MIN;
    int min_y = INT_MAX;
    int max_y = INT_MIN;
    int coord;
    for (i = 0; i < 4 * N; i++)
    {
        if (scanf("%d", &coord))
        {
        };
        if (i % 2 == 0 && coord < min_x)
            min_x = coord;
        else if (i % 2 == 0 && coord > max_x)
            max_x = coord;
        else if (i % 2 == 1 && coord < min_y)
            min_y = coord;
        else if (i % 2 == 1 && coord > max_y)
            max_y = coord;
        T[i] = coord;
    }
    for (i = 0; i < 4 * N; i++)
    {
        if (i % 2 == 0)
            T[i] += abs(min_x);
        else
            T[i] += abs(min_y);
    }
    int rows = abs(max_y) + abs(min_y);
    int cols = abs(max_x) + abs(min_x);
    int area[rows][cols];
    int a;
    int b;
    for (a = 0; a < rows; a++)
        for (b = 0; b < cols; b++)
            area[a][b] = 0;
    i = 0, a = 0, b = 0;
    int m;
    int n;
    while (i < 4 * N)
    {
        int x_distance = find_x_distance(T[i], T[i + 2]);
        int y_distance = find_y_distance(T[i + 1], T[i + 3]);
        if (T[i] < T[i + 2])
            a = T[i];
        else
            a = T[i + 2];
        if (T[i + 1] < T[i + 3])
            b = T[i + 1];
        else
            b = T[i + 3];
        for (m = b; m < y_distance; m++)
            for (n = a; n < x_distance; n++)
                if (area[m][n] == 0)
                    area[m][n] = 1;
                else
                {
                    area[m][n] = 0;
                }
        i += 4;
    }
    int count = 0;
    for (a = 0; a < rows; a++)
        for (b = 0; b < cols; b++)
        {
            if (area[a][b] == 1)
                count++;
        }
    printf("%d\n", count);
    free(T);
    return 0;
}