#include <stdio.h>
#include <stdlib.h>


long long binary_gcd(long long a, long long b) {

    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;

    int a_is_even = !(a & 1);
    int b_is_even = !(b & 1);

    if (a_is_even && b_is_even) {
        return binary_gcd(a >> 1, b >> 1) << 1;
    }
    else if (a_is_even && !b_is_even) {
        return binary_gcd(a >> 1, b);
    }
    else if (!a_is_even && b_is_even) {
        return binary_gcd(a, b >> 1);
    }
    else {
        long long diff = (a > b) ? (a - b) : (b - a);
        long long min_val = (a < b) ? a : b;
        return binary_gcd(diff, min_val);
    }
}

int main(int argc, char *argv[]) {

    long long a = atoll(argv[1]);
    long long b = atoll(argv[2]);

    long long result = binary_gcd(a, b);

    printf("НОД(%lld, %lld) = %lld\n", a, b, result);

    return 0;
}