#include "calculator.h"

int add(int lhs, int rhs) { return lhs + rhs; }

int subtract(int lhs, int rhs) { return lhs - rhs; }

int multiply(int lhs, int rhs) { return lhs * rhs; }

int divide(double dividend, double divisor, double *out)
{
    if (divisor == 0.0) {
        return -1;
    }
    *out = dividend / divisor;
    return 0;
}
