#include <stdio.h>

// Recursive function to find the Nth Fibonacci number
int fibonacci(int n) {
    // Base cases: F(0) = 0, F(1) = 1
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    // Recursive step: F(n) = F(n-1) + F(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 10;  // Example: Find the 10th Fibonacci number
    int result = fibonacci(n);

    printf("The %dth Fibonacci number is %d\n", n, result);

    return 0;
}

