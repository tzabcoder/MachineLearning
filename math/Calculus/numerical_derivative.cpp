#include <iostream>
#include <vector>

/**
 * @brief returns the function value at x
 * y = x^2 - 2x - 1
 */
double f(double x) {
    return (x * x) - (2 * x) - 1;
}

/**
 * @brief Uses the finite difference method to compute the derivative
 * at x. Computes the slope of the secant line at each iteration as
 * h approaches 0, where h represents the change in x. Stores each
 * approximation.
 *
 * @param x value to compute the derivative
 * @param h change in x
 * @param n number of times to iterate as h->0
 * @param f function to compute f'(x)
 * @return derivative approximations
 */
std::vector<double> finite_difference(double x, double h, int n, double (*f)(double)) {
    std::vector<double> derivatives;

    // iterate so h approaches 0
    for (int i = 0; i < n; i++) {
        double d_dx = (f(x + h) - f(x)) / h;
        derivatives.push_back(d_dx);

        // h -> 0
        h /= 2;
    }

    return derivatives;
}

/**
 * @brief Uses the central difference method to compute the derivative
 * of f at x. Stores the central difference approximation.
 *
 * @param x value to compute the derivative
 * @param h change in x
 * @param n number of times to iterate as h->0
 * @param f function to compute f'(x)
 * @return derivative approximations
 */
std::vector<double> central_difference(double x, double h, int n, double (*d)(double)) {
    std::vector<double> derivatives;

    // iterate so h approaches 0
    for (int i = 0; i < n; i++) {
        double d_dx = (f(x + h) - f(x - h)) / (2 * h);
        derivatives.push_back(d_dx);

        // h -> 0
        h /= 2;
    }

    return derivatives;
}

int main() {
    double x = 2;
    double h = 0.1;
    int n = 20;

    std::vector<double> f_d = finite_difference(x, h, n, &f);
    std::vector<double> c_d = central_difference(x, h, n, &f);

    // Compare the approximation convergence rate
    for (int i = 0; i < n; i++) {
        std::cout << f_d[i] << " " << c_d[i] << std::endl;
    }

    return 0;
}