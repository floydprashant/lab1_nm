// Qno.1 --- Write a program to find the root of the following equation using the Bisection method {y = x - e-x}.

#include <stdio.h>
#include <math.h>

double function(double x) {
    return x - exp(-x);
}

int main() {
    double xu = 1;
    double xl = 0;
    double xm;
    double error;

    
    double ansXu = function(xu);
    double ansXl = function(xl);
    
    printf("Value for xu = %lf\n", ansXu);
    printf("Value for xl = %lf\n", ansXl);

    // Checks if interval is valid
    if (ansXu * ansXl > 0) {
        printf("No root in this interval.\n");
        return 1;
    }

    do {
        xm = (xl + xu) / 2;
        double ansXm = function(xm);
        
        printf("\nXm = %lf", xm);
        printf("\nf(xm) = %lf", ansXm);

        
        if (ansXm < 0) {
            xl = xm;
        } else {
            xu = xm;
        }

        error = fabs((xu - xl) / xm); //calculating the relative error
        printf("\nError = %lf", error);

    } while (error > 0.05);

    printf("\nRoot found at x = %lf\n", xm);
    
    return 0;
}
