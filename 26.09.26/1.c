#include <stdio.h>

int logBase2(int n) {
    if (n <= 0) return -1;

    int result = 0;
    while (n > 1) {
        n >>= 1;
        result++;
    }
    return result;
}

int main() {
    printf("logBase2(64) = %d\n", logBase2(64));
    printf("logBase2(57) = %d\n", logBase2(57));
    printf("logBase2(0)  = %d\n", logBase2(0));
    return 0;
}
