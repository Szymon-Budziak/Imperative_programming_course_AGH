#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char string[51];
    if (scanf("%s", string)) {};
    int length = strlen(string);
    int j = length - 1;
    int *result = (int *) calloc(length, sizeof(int));
    result[j] = 1;
    for (int i = j - 1; i > -1; i--)
        if (string[j] <= string[i]) {
            result[i] = 1;
            j = i;
        }
    for (int i = 0; i < length; i++)
        if (result[i] == 1)
            printf("%c", string[i]);
    free(result);
    return 0;
}