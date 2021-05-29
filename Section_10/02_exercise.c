#include <stdio.h>

void check_three_height(int *T, int length) {
    int is_three_height = 1;
    while (is_three_height == 1) {
        is_three_height = 0;
        for (int i = 2; i < length - 2; i++) {
            if (T[i] >= 3) {
                T[i - 2] += T[i] / 3;
                T[i + 2] += T[i] / 3;
                T[i] %= 3;
                if (T[i - 2] >= 3)
                    is_three_height = 1;
            }
        }
    }
}

int finish(int *T, int length) {
    for (int i = 0; i < length - 2; i++) {
        if (T[i + 1] != 0 && T[i] != 0)
            return 0;
        if (T[i + 1] > 1 || T[i] > 1)
            return 0;
    }
    return 1;
}

int main() {
    int n;
    if (scanf("%d", &n));
    int length = 10080;
    int T[10080] = {0};
    int p;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &p)) {};
        p += 40;
        if (scanf("%d", &T[p])) {};
    }
    check_three_height(T, length);
    int field = -1;
    for (int i = 0; i < length; i++)
        if (T[i] != 0)
            field = i - 1;
    while (finish(T, length) == 0) {
        int check = 0;
        if (T[field] > 0 && T[field + 1] > 0) {
            T[field] -= 1;
            T[field + 1] -= 1;
            T[field + 2] += 1;
            field += 2;
            check = 1;
        } else if (T[field] == 2 && T[field - 1] > 0) {
            field -= 1;
            check = 1;
        } else if (T[field] == 2 && T[field + 1] == 0) {
            T[field] -= 1;
            T[field - 2] += 1;
            T[field] -= 1;
            T[field + 1] += 1;
            field += 1;
            check = 1;
        } else if (T[field] == 3) {
            T[field - 2] += T[field] / 3;
            T[field + 2] += T[field] / 3;
            T[field] %= 3;
            field += 2;
            check = 1;
        }
        int left = -1, max_left = -1;
        for (int i = 0; i < length; i++) {
            if (T[i] && max_left == -1)
                max_left = i;
            if (T[i] && i < field)
                left = i;
        }
        if (field == max_left && check == 0)
            break;
        else if (check == 0)
            field = left;
    }
    for (int i = 0; i < length; i++) {
        if (T[i] != 0)
            printf("%d ", i - 40);
    }
    return 0;
}