#include <stdio.h>
#include <string.h>

int is_prime_number(int n) {
    if (n == 2 || n == 3) {
        return 1;
    } else if (n < 2 || n % 2 == 0 || n % 3 == 0) {
        return 0;
    } else {
        int i = 5;
        while (i * i <= n) {
            if (n % i == 0) {
                return 0;
            }
            i += 2;
            if (n % i == 0) {
                return 0;
            }
            i += 4;
        }
        return 1;
    }
}

int main() {
    char s[48];
    if (scanf("%s", s)) {};
    int length = strlen(s);
    int best_string[length];
    for (int i = 0; i < length; i++)
        best_string[i] = s[i];
    int actual_string[length];
    int distance;
    for (int i = 0; i < length; i++)
        for (int j = 0; j < length; j++)
            if (i != j) {
                if (j < i)
                    distance = length - i + j;
                else
                    distance = j - i;
                if (is_prime_number(distance)) {
                    int multiplier = 0;
                    int flag = 0;
                    for (int k = 0; k < length; k++) {
                        actual_string[k] = s[(i + multiplier * distance) % length];
                        multiplier++;
                    }
                    for (int k = 0; k < length; k++) {
                        if (actual_string[k] < best_string[k]) {
                            flag = 1;
                            break;
                        } else if (actual_string[k] > best_string[k])
                            break;
                    }
                    if (flag)
                        for (int k = 0; k < length; k++)
                            best_string[k] = actual_string[k];
                }
            }
    for (int i = 0; i < length; i++)
        printf("%c", best_string[i]);
}