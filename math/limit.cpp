#include <cmath>
#include <limits>
#include <iostream>

/**
 * @brief returns the value of the function (f) at x.
 * The function is: y = x^2 + 2x - 1
 */
double f_1(double x) {
    return (x * x) - (2 * x) - 1;
}

/**
 * @brief returns the value of the function (f) at x.
 * The function is: y = x / (2x - 1)
 */
double f_2(double x) {
    return x / (2 * x - 1);
}

/**
 * @brief returns the value of the function (f) at x.
 * The function is: y = (x^2 - 3) / (4x - 5)
 */
double f_3(double x) {
    return (x * x - 3) / (4 * x - 5);
}

/**
 * @brief Evaluates the limit of the function (f) numerically
 * as x approaches a. Runs n iterations for left-sided and right-
 * sided limits using the step size to allow x to approach a. The
 * tolerance is used to validate that the lrft- and right-sided
 * limits are equivalent.
 *
 * @param a evaluate the limit as x approaches a
 * @param n number of iterations to run
 * @param step size of iteration increments
 * @param tol tolerance when comparing left, and right-sided limits
 * @param f function to evaluate the limit
 *
 * @return value of the limit, null if limit DNE
 */
double numerical_limit(double a, int n, double step, double tol, double (*f)(double)) {
    double l_limit = 0.0; // left-sided limit approximation
    double r_limit = 0.0; // right-sided limit approximation

    // Iterate toward a (from left and right)
    for (int i = 0; i < n; i++) {
        l_limit = f(a - step);
        r_limit = f(a + step);

        // Update the step
        // Use halving to improve numerical stability
        step /= 2.0;
    }

    // Overall limit as x->a
    // Default to limit DNE
    double limit = std::numeric_limits<double>::quiet_NaN();

    if (std::abs(r_limit - l_limit) <= tol) {
        // Use the average of the left and right limit
        limit = (l_limit + r_limit) / 2.0;
    }

    return limit;
}

int main() {
    // Lim as x->2
    double lim_1 = numerical_limit(2, 10, 0.1, 0.001, &f_1);
    std::cout << lim_1 << std::endl;

    // Lim as x->5
    double lim_2 = numerical_limit(5, 10, 0.1, 0.001, &f_2);
    std::cout << lim_2 << std::endl;

    // Lim as x->3
    double lim_3 = numerical_limit(3, 10, 0.1, 0.001, &f_3);
    std::cout << lim_3 << std::endl;

    return 0;
}