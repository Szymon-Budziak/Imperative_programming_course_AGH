#include <stdio.h>
#include <limits.h>

int pull_the_ball(int *red, int *green, int *blue, int index) {
    if (red[index] > green[index] && red[index] > blue[index])
        return green[index] + blue[index];
    else if (green[index] > red[index] && green[index] > blue[index])
        return red[index] + blue[index];
    else
        return red[index] + green[index];
}

int main() {
    int n;
    if (scanf("%d", &n)) {};
    if (n < 3) {
        printf("-1");
        return 0;
    }
    int red[53] = {0};
    int green[53] = {0};
    int blue[53] = {0};
    int red_count = 0, green_count = 0, blue_count = 0;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &red[i])) {};
        red_count += red[i];
    }
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &green[i])) {};
        green_count += green[i];
    }
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &blue[i])) {};
        blue_count += blue[i];
    }
    int min_count = INT_MAX;
    for (int r = 0; r < n; r++) {
        if (red_count == 0)
            r = n + 1;
        for (int g = 0; g < n; g++) {
            if (green_count == 0)
                g = n + 2;
            for (int b = 0; b < n; b++) {
                if (blue_count == 0)
                    b = n + 3;
                if (r == g || r == b || g == b)
                    continue;
                int count = green[r] + blue[r] + red[g] + blue[g] + red[b] + green[b];
                for (int i = 0; i < n; i++) {
                    if (i == r || i == g || i == b)
                        continue;
                    count += pull_the_ball(red, green, blue, i);
                }
                if (count < min_count)
                    min_count = count;
            }
        }
    }
    printf("%d", min_count);
    return 0;
}