// Qno.3 --- Write a program to find the root of the following equation using the False Position Method {y = x - e-x}

#include <stdio.h>
#include <math.h>

//to calculate the value of the equation y = x - e^(-x)
double f(double x) {
    return x - exp(-x);
}

double false_position(double a, double b, double tolerance, int max_iterations) {
    double fa = f(a);
    double fb = f(b);

    // to check whether the function has opposite signs at the endpoints or not
    if (fa * fb >= 0) {
        printf("Function has the same sign at points a and b.\n");
        return a;
    }

    double c;
    int i;
    for (i = 0; i < max_iterations; i++) {
        c = b - (fb * (b - a)) / (fb - fa);
        double fc = f(c);

        if (fabs(fc) < tolerance) {
            return c;
        }

        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }

    printf("Exceeded maximum iterations. No solution found.\n");
    return c;
}

int main() {
    double a = -1.0;
    double b = 2.0;
    double tolerance = 0.05;
    int max_iterations = 50;

    double root = false_position(a, b, tolerance, max_iterations);
    printf("Root of the equation is: %.10lf\n", root);

    return 0;
}