// Qno.2 --- Write a program to find the root of the following equation using the Newton Raphson method {y = x - e-x}

#include <stdio.h>
#include <math.h>

//to calculate the value y = x - e^(-x)
double calculate_y(double x) {
    return x - exp(-x);
}

//to calculate the derivative
double calculate_dy(double x) {
    return 1 + exp(-x);
}

int main() {

    double initial_guess = 1;

    double tolerance = 0.0001;

    int max_iterations = 50;

    double x = initial_guess;

    int i;
    for (i = 0; i < max_iterations; i++) {
        double y = calculate_y(x);
        double dy = calculate_dy(x);

        // Calculates the next approximation using the Newton-Raphson formula
        double new_x = x - y / dy;

        if (fabs(new_x - x) < tolerance) {
            printf("Root of the equation is: %lf\n", new_x);
            return 0;
        }

        x = new_x;
    }

    printf("Root not found within the specified tolerance and iterations.\n");
    return 1;
}