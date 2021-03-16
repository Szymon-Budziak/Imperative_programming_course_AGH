#include <stdio.h>

int pan_balance(int *T, int w, int cur_weight, int p)
{
    if (w == cur_weight)
        return 1;
    if (cur_weight > w || sizeof(T) == p)
        return 0;
    return (0 ||
            pan_balance(T, w, cur_weight + T[p], p++) ||
            pan_balance(T, w + T[p], cur_weight, p++));
}

int main()
{
    int n = 0, w = 0, p = 0;
    int cur_weight = 0, result = 0;
    scanf("%d %d", &n, &w);
    int T[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &T[i]);
        result += T[i];
    }
    if (n < 0 || w < 0 || result < w)
        printf("NO\n");
    else if (pan_balance(T, w, cur_weight, p) == 1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}