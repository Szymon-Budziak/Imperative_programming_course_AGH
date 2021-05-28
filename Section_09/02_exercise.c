#include <stdio.h>
#include <math.h>

int main() {
    int N;
    unsigned long int M;
    if (scanf("%d %lu", &N, &M)) {};
    unsigned long int max_number = pow(2, N);
    unsigned long int count = 0, number;
    for (unsigned long int i = 1; i < max_number; i++)
        if (i % M != 0)
            for (unsigned long int j = 0; j < N; j++) {
                number = i ^ (1 << j);
                if (number % M == 0 && number != 0) {
                    count++;
                    break;
                }
            }
    printf("%lu", count);
    return 0;
}