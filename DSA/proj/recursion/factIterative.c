#include <stdio.h>

long int factorial(int A) {
    if (A == 0) {
        return 1;
    } else {
        return A * factorial(A - 1);
    }
}

int main() {
    int n;
    long int fact = 0;
    printf("Enter the number: ");
    scanf_s("%d", &n);
    fact = factorial(n);
    printf("The factorial is %ld\n", fact);
    return 0;
}

