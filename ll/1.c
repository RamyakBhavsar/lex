// AIM: Reusability and Consistency in Large Projects:

// Step 1: Define Constants and Functions in a Header File:
//math_utils.h

#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#define EULER_CONSTANT 2.71828
#define MAX_ITERATIONS 1000

int multiply(int a, int b);
double exponential(double x);

#endif

// Step 2: Implement Functions in a Source File:
//math_utils.c

#include "math_utils.h"

int multiply(int a, int b) {
    return a * b;
}

double exponential(double x) {
    double result = 1.0;
    for (int i = 1; i <= MAX_ITERATIONS; i++) {
        result += (pow(x, i) / factorial(i));
    }
    return result;
}

int factorial(int n) {
    if (n == 0) return 1;
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Step 3: Use Reusable Code in Another Module:
//1_main.c

#include <stdio.h>
#include "math_utils.h"

int main() {
    int product = multiply(4, 5);
    double exp_value = exponential(1.0); // Calculate e^1 (Euler's number)
    
    printf("Result of multiplication: %d\n", product);
    printf("Exponential of 1.0: %.5f\n", exp_value);
    
    return 0;
}


// Run:
gcc k:/dlp_prac/1_main.c k:/dlp_prac/math_utils.c -o k:/dlp_prac/output/1_main.exe
cd k:/dlp_prac/output
./1_main.exe