#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int T[500];
    T[0] = 1;
    int count = 0;
    int digits = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= digits; j++)
        {
            T[j] = (T[j] * i) + count;
            count = T[j] / 10;
            T[j] %= 10;
        }
        while (count > 0 && digits < 500)
        {
            digits++;
            T[digits] = count % 10;
            count /= 10;
        }
    }
    int k = digits;
    for (k; k >= 0; k--)
        printf("%d", T[k]);
    printf("\n");
    return 0;
}