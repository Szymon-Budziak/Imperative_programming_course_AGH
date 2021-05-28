#include <stdio.h>

int main()
{
    int n = 0, result = 0;
    scanf("%d", &n);
    int T[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &T[i]);
        result += T[i];
    }
    int summary = 0, d = -1;
    for (int j = 0; j < n; j++)
    {
        summary += T[j];
        if ((summary - T[j]) * 2 == (result - T[j]))
        {
            d = j;
            break;
        }
    }
    printf("%d\n", d);
    return 0;
}