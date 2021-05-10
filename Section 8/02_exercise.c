#include <stdio.h>

int main() {
    int N;
    if (scanf("%d", &N)) {};
    unsigned long long int result = 0;
    int actual;
    for (int i = 1; i <= N; i += 2) {
        actual = i;
        while (actual <= N) {
            result += i;
            actual *= 2;
        }
    }
    printf("%llu", result);
    return 0;
}