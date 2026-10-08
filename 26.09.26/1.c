#include <stdio.h>

int log2(int n) {
    if (n <= 0) return -1;

    int result = 0;
    while (n > 1) {
        n >>= 1;
        result++;
    }
    return result;
}

int main() {
    printf("log2(64) = %d\n", log2(64));
    printf("log2(57) = %d\n", log2(57));
    printf("log2(0)  = %d\n", log2(0));
    return 0;
}