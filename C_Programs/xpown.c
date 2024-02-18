#include <stdio.h>

double power(double x, int n) {
    double res = 1.0;

    if (n < 0) {
        x = 1/x;
        n--;
    }

    for (int i = 0; i < n; i++) {
        res *= x;
    }

    return res;
}

int main() {
    double x;
    int n;

    printf("Enter the base (x): ");
    scanf("%lf", &x);
    printf("Enter the exponent (n): ");
    scanf("%d", &n);

    double res = power(x, n);

    printf("%.2lf^%d = %.6lf\n", x, n, res);

    return 0;
}

