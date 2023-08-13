#include <stdio.h>
#include <math.h>

// Define the functions f(x) and g(x)
double f(double x) {
    return sqrt(x);
}

double g(double x) {
    return x * x;
}

// Define the function h(x) = f(x) - g(x)
double h(double x) {
    return f(x) - g(x);
}

// Bisection method to find the intersection
double bisection(double a, double b, double tol) {
    if (h(a) * h(b) >= 0) {
        printf("Bisection method requires a change of sign in the interval.\n");
        return -1;
    }

    double c = a;
    while ((b - a) >= tol) {
        c = (a + b) / 2;
        if (h(c) == 0.0) break;
        if (h(c) * h(a) < 0) b = c;
        else a = c;
    }

    return c;
}

int main() {
    double a, b, tol = 1e-6, c = 0.0;
    int n;

    printf("Enter the values for a, b: ");
    scanf("%lf %lf", &a, &b);
    printf("Enter the value for n (number of intervals, must be even): ");
    scanf("%d", &n);

    

    // Finding intersection
    double intersect = bisection(a, b, tol);
    printf("Intersection of f(x) and g(x) occurs at x = %.6lf\n", intersect);

    // Simpson's method
    double h_step = (intersect - c) / n; // Step size
    double sumOdds = 0.0, sumEvens = 0.0;
    for (int i = 1; i < n; i += 2) sumOdds += h(c + i * h_step);
    for (int i = 2; i < n - 1; i += 2) sumEvens += h(c + i * h_step);

    double integration_simpson = (h_step / 3) * (h(c) + h(intersect) + 4 * sumOdds + 2 * sumEvens);

    printf("Simpson's approximation for the integral of h(x) from %lf to %lf is %9.6lf\n", c, intersect, integration_simpson);

    return 0;
}

