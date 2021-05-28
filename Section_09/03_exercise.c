#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int elem1 = *((int *) a);
    int elem2 = *((int *) b);
    if (elem1 > elem2)
        return 1;
    if (elem1 < elem2)
        return -1;
    return 0;
}

int main() {
    int N;
    long int G;
    if (scanf("%d %li", &N, &G)) {};
    long int T[N];
    for (int i = 0; i < N; i++)
        if (scanf("%li", &T[i])) {};
    qsort(T, sizeof(T) / sizeof(*T), sizeof(*T), compare);
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (T[i] <= G)
            count++;
        else if (T[i] > G)
            break;
    }
    int arr[count + 1][30];
    int rem;
    int final_result = 30;
    for (int i = 0; i < count; i++)
        for (int j = 0; j < 30; j++) {
            if (T[i] != 0) {
                rem = T[i] % 2;
                T[i] /= 2;
                arr[i][j] = rem;
            } else
                arr[i][j] = 0;
        }
    for (int i = 0; i < 30; i++)
        if (G != 0) {
            rem = G % 2;
            G /= 2;
            arr[count][i] = rem;
        } else
            arr[count][i] = 0;
    int flag = 1;
    int result;
    for (int i = 0; i < 29; i++)
        if (arr[count][i] == 1) {
            result = 0;
            for (int j = count - 1; j >= 0; j--)
                if (arr[j][i] == 1) {
                    flag = 1;
                    for (int k = 0; k < 29; k++)
                        if (arr[count][k] < arr[j][k]) {
                            flag = 0;
                            break;
                        }
                    if (flag)
                        result++;
                }
            if (result < final_result)
                final_result = result;
        }
    printf("%d", final_result);
    return 0;
}