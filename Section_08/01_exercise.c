#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long long int S;
    if (scanf("%lli", &S)) {};
    int length = floor(log10(S)) + 1;
    int *T = (int *) calloc(length, sizeof(int));
    long long int result = 1;
    for (int i = 1; i < length; i++) {
        result *= 10;
        result++;
    }
    for (int i = 0; i < length; i++) {
        while (S - result >= 0) {
            S -= result;
            T[i]++;
            if (T[i] > 9) {
                printf("-1");
                free(T);
                return 0;
            }
        }
        result /= 10;
    }
    for (int i = 0; i < length; i++) {
        if (T[i] == 0 && i == 0)
            continue;
        printf("%d", T[i]);
    }
    free(T);
    return 0;
}