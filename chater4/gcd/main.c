/*
 * p191. 3. The greatest common divisor(g.c.d) of two nonnegative integers is the
 * largest integer that divides evenly into both. In the third century B.C., the
 * Greek mathematician Euclid discovered that the greatest common divisor of x
 * and y can always be computed as follows:
 *
 * If x is evenly divisible by y, then y is the greatest common divisor.
 * Otherwise, the greatest common divisor of x and y is always equal to the
 * greatest common divisor of y and the remainder of x divided by y.
 *
 * Use Euclid insight to write a recursive function GCD(X, Y) that computes the
 * greatest common divisor x and y.
 */
#include <stdio.h>

int gcd(int x, int y);

/*
 * function: gcd
 * Usage: int(x, y)
 * ------------
 */
int gcd(int x, int y) {
    if (x % y == 0) {
        return y;
    }
    return gcd(y, x % y);
}


int main() {
    int result;
    result = gcd(16, 28);
    printf("GCD=%d\n", result);  // GCD=4
    return 0;
}
