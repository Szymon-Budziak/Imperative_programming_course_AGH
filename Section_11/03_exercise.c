#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

void operations(char result[], char actual[], int idx, int *length, int *flag, long int s, long int t) {
    if (s == t) {
        if (*length > idx) {
            actual[idx] = '\0';
            strcpy(result, actual);
            *flag = 1;
            *length = idx;
        }
    } else if (s < 0 || s > t)
        return;
    else {
        if (s != 1 && s < sqrt(LONG_MAX)) {
            actual[idx] = '*';
            operations(result, actual, idx + 1, length, flag, s * s, t);
        }
        if (s < LONG_MAX / 2) {
            actual[idx] = '+';
            operations(result, actual, idx + 1, length, flag, s * 2, t);
        }
    }
}

int main() {
    long int s, t;
    if (scanf("%li %li", &s, &t)) {};
    int flag = 0;
    int length = log2(pow(10, 9)) + 1;
    char result[length];
    char actual[length];
    operations(result, actual, 0, &length, &flag, s, t);
    actual[0] = '/';
    operations(result, actual, 1, &length, &flag, 1, t);
    if (flag)
        printf("%s", result);
    else
        printf("NO");
    return 0;
}