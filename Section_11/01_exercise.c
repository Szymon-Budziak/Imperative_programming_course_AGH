#include <stdio.h>
#include <math.h>

double count_distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

int axis_of_symmetry(double *x, double *y, int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        int idx = 2 * i + 1;
        int x_idx = 2 * i;
        int y_idx = (2 * i + 2) % (2 * n);
        x[idx] = (x[x_idx] + x[y_idx]) / 2;
        y[idx] = (y[x_idx] + y[y_idx]) / 2;
    }
    for (int i = 0; i < n; i++) {
        int add = 1;
        double point_1x = x[i];
        double point_1y = y[i];
        double point_2x = x[i + n];
        double point_2y = y[i + n];
        for (int j = 1; j < n; j++) {
            double point_3x = x[(i + j) % (2 * n)];
            double point_3y = y[(i + j) % (2 * n)];
            double point_4x = x[i - j];
            double point_4y = y[i - j];
            if (i - j < 0) {
                int idx_4 = i - j;
                idx_4 += 2 * n;
                point_4x = x[idx_4];
                point_4y = y[idx_4];
            }
            double dist_1 = count_distance(point_1x, point_1y, point_3x, point_3y);
            double dist_2 = count_distance(point_1x, point_1y, point_4x, point_4y);
            double dist_3 = count_distance(point_2x, point_2y, point_3x, point_3y);
            double dist_4 = count_distance(point_2x, point_2y, point_4x, point_4y);
            if (dist_1 != dist_2 || dist_3 != dist_4) {
                add = 0;
                break;
            }
        }
        result += add;
    }
    return result;
}

int main() {
    int t, n;
    if (scanf("%d", &t)) {};
    double x[200000];
    double y[200000];
    int result[t];
    for (int i = 0; i < t; i++) {
        if (scanf("%d", &n)) {};
        for (int j = 0; j < n; j++) {
            if (scanf("%lf", &x[2 * j])) {};
            if (scanf("%lf", &y[2 * j])) {};
        }
        result[i] = axis_of_symmetry(x, y, n);
    }
    for (int i = 0; i < t; i++)
        printf("%d\n", result[i]);
    return 0;
}