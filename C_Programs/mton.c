#include <stdio.h>

void calculateSumAndAverage(int m, int n, double *sum, double *average) {
    int total = 0;
    int count = 0;

    for (int i = m; i <= n; i++) {
        total += i;
        count++;
    }

    *sum = total;
    *average = (double)total / count;
}

int main() {
    int m, n;
    double sum, average;

    printf("Enter the starting number (m): ");
    scanf("%d", &m);

    printf("Enter the ending number (n): ");
    scanf("%d", &n);

    calculateSumAndAverage(m, n, &sum, &average);

    printf("Sum of numbers from %d to %d is: %.2lf\n", m, n, sum);
    printf("Average of numbers from %d to %d is: %.2lf\n", m, n, average);

    return 0;
}

