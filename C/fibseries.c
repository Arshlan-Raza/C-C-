#include <stdio.h>

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

void printFibonacciSeries(int n) {
    printf("Fibonacci series up to %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d, ", fib(i));
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printFibonacciSeries(n);
    return 0;
}
