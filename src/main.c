#include <stdio.h>
#include "calculator.h"

int main() {
    double num1, num2;
    char operator;
    double result;

    printf("Enter an operation (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    result = calculate(num1, num2, operator);

    if (result != 0xDEADBEEF) {
        printf("Result: %.2lf\n", result);
    } else {
        printf("Error: Invalid operation or division by zero.\n");
    }

    return 0;
}
