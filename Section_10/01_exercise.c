#include <stdio.h>
#include <string.h>

int check(int value[], int length) {
    for (int i = 0; i < length; i++)
        if (value[i] != 0)
            return 0;
    return 1;
}

int is_odd(int value[], int length) {
    if (value[length - 1] % 2 == 1)
        return 1;
    else
        return 0;
}

void operation_1(int value[], int length) {
    int remaining = 1;
    int i = length - 1;
    while (i >= 0 && remaining == 1) {
        value[i]++;
        value[i] %= 10;
        if (value[i] != 0)
            remaining = 0;
    }
}

int operation_2(int value[], int length) {
    int remaining = 0;
    int new_remaining;
    for (int i = 0; i < length; i++) {
        new_remaining = (value[i] + remaining * 10) % 2;
        value[i] = (value[i] + remaining * 10) / 2;
        remaining = new_remaining;
    }
    return remaining;
}

int main() {
    char amount[30];
    if (scanf("%s", amount));
    int length = strlen(amount);
    int value_1[30], value_2[30];
    for (int i = 0; i < length; i++) {
        value_1[i] = amount[i] - '0';
        value_2[i] = amount[i] - '0';
    }
    int result_1[100] = {0}, result_2[100] = {0};
    int i = 0;
    int flag_1 = 1, flag_2 = 1;
    while (i < 100 && (check(value_1, length) == 0)) {
        result_1[i] = is_odd(value_1, length);
        if (result_1[i] == 1 && i % 2 == 1)
            operation_1(value_1, length);
        operation_2(value_1, length);
        i++;
    }
    if (check(value_1, length) == 0)
        flag_1 = 0;
    i = 0;
    while (i < 100 && check(value_2, length) == 0) {
        result_2[i] = is_odd(value_2, length);
        if (result_2[i] == 1 && i % 2 == 0)
            operation_1(value_2, length);
        operation_2(value_2, length);
        i++;
    }
    if (check(value_2, length) == 0)
        flag_2 = 0;
    if (flag_1 == 1) {
        for (int j = 0; j < 100; j++)
            if (result_1[j] == 1)
                printf("%d ", j);
    } else
        printf("NO");
    printf("\n");
    if (flag_2 == 1) {
        for (int j = 0; j < 100; j++)
            if (result_2[j] == 1)
                printf("%d ", j);
    } else
        printf("NO");
    return 0;
}