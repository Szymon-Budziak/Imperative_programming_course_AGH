#include <stdio.h>
#include <string.h>

int xor_gate(int n, int m, int number, int T[m][2], char bits_1[n]) {
    int a, b;
    if (T[number - 1][0] < 0)
        a = bits_1[(-1) * T[number - 1][0] - 1] - 48;
    else
        a = xor_gate(n, m, T[number - 1][0], T, bits_1);
    if (T[number - 1][1] < 0)
        b = bits_1[(-1) * T[number - 1][1] - 1] - 48;
    else
        b = xor_gate(n, m, T[number - 1][1], T, bits_1);
    if (a != b)
        return 1;
    return 0;
}

int main() {
    int n, m, number;
    if (scanf("%d %d %d", &n, &m, &number)) {};
    int T[m][2];
    char bits_1[n];
    char bits_2[n];
    for (int i = 0; i < m; i++)
        if (scanf("%d %d", &T[i][0], &T[i][1])) {};
    if (scanf("%s %s", bits_1, bits_2));
    int count = 0;
    while (strcmp(bits_1, bits_2)) {
        count += xor_gate(n, m, number, T, bits_1);
        for (int i = n - 1; i >= 0; i--)
            if (bits_1[i] == '0') {
                bits_1[i] = '1';
                break;
            } else
                bits_1[i] = '0';
    }
    count += xor_gate(n, m, number, T, bits_1);
    printf("%d", count);
    return 0;
}