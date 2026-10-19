#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef union {
    uint64_t full;
    struct {
        uint32_t low;
        uint32_t high;
    } half;
} Number64;

typedef struct {
    uint64_t low;
    uint64_t high;
} Number128;

Number128 multiply_64(uint64_t x, uint64_t y) {
    Number64 X, Y;
    X.full = x;
    Y.full = y;

    uint64_t p1 = (uint64_t)X.half.high * Y.half.high;
    uint64_t p2 = (uint64_t)X.half.low * Y.half.low;
    
    uint64_t sumX = (uint64_t)X.half.high + X.half.low;
    uint64_t sumY = (uint64_t)Y.half.high + Y.half.low;
    uint64_t p3 = sumX * sumY;

    uint64_t middle = p3 - p1 - p2;

    Number128 result;
    result.low = p2 + (middle << 32);
    uint64_t carry = (result.low < p2) ? 1 : 0;
    
    result.high = p1 + (middle >> 32) + carry;

    return result;
}

bool is_zero(Number128 n) {
    return n.low == 0 && n.high == 0;
}

void div_mod_10(Number128 n, Number128 *quot, uint32_t *rem) {
    quot->low = 0;
    quot->high = 0;
    uint64_t r = 0;

    for (int i = 127; i >= 0; i--) {
        int bit = 0;
        if (i >= 64) {
            bit = (n.high >> (i - 64)) & 1;
        } else {
            bit = (n.low >> i) & 1;
        }

        r = (r << 1) | bit;
        if (r >= 10) {
            r -= 10;
            if (i >= 64) {
                quot->high |= ((uint64_t)1 << (i - 64));
            } else {
                quot->low |= ((uint64_t)1 << i);
            }
        }
    }
    *rem = (uint32_t)r;
}

void print_u128(Number128 n) {
    if (is_zero(n)) {
        printf("0\n");
        return;
    }

    char buf[40];
    int i = 39;
    buf[i] = '\0';

    Number128 temp = n;
    while (!is_zero(temp)) {
        uint32_t rem;
        Number128 quot;
        div_mod_10(temp, &quot, &rem);
        buf[--i] = "0123456789"[rem];
        temp = quot;
    }

    printf("%s\n", &buf[i]);
}

int main() {
    uint64_t a = 123456789012345ULL;
    uint64_t b = 987654321098765ULL;

    Number128 result = multiply_64(a, b);

    printf("Результат умножения: ");
    print_u128(result);

    return 0;
}