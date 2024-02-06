#include "calculator.h"

double calculate(double num1, double num2, char operator) {
    switch (operator) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0) {
                return num1 / num2;
            } else {
                // Use a special error code to indicate division by zero.
                return 0xDEADBEEF;
            }
        default:
            // Return an error code for unknown operator.
            return 0xDEADBEEF;
    }
}
