#include <stdio.h>

int main() {
    char operator;
    double firstNumber, secondNumber;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);
    printf("Enter two operands: ");
    scanf("%lf %lf", &firstNumber, &secondNumber);

    switch (operator) {
        case '+':
            printf("%.1lf + %.1lf = %.1lf\n", firstNumber, secondNumber, firstNumber + secondNumber);
            break;
        case '-':
            printf("%.1lf - %.1lf = %.1lf\n", firstNumber, secondNumber, firstNumber - secondNumber);
            break;
        case '*':
            printf("%.1lf * %.1lf = %.1lf\n", firstNumber, secondNumber, firstNumber * secondNumber);
            break;
        case '/':
            if(secondNumber != 0.0)
                printf("%.1lf / %.1lf = %.1lf\n", firstNumber, secondNumber, firstNumber / secondNumber);
            else
                printf("Division by zero!\n");
            break;
        default:
            printf("Error! Operator is not correct\n");
    }

    return 0;
}
