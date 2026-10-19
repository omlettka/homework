#include <stdio.h>
#include <stdint.h>

typedef union {
    uint64_t full;
    struct {
        uint32_t low;
        uint32_t high;
    } half;
} Number64;

unsigned __int128 karatsuba_64(uint64_t x, uint64_t y) {
    if (x <= 0xFFFFFFFFFFFFFFFFULL && (x >> 32) == 0 && y <= 0xFFFFFFFFFFFFFFFFULL && (y >> 32) == 0) {
        return (unsigned __int128)x * y;
    }

    Number64 X, Y;
    X.full = x;
    Y.full = y;


    // Шаг 2: Вычисляем три произведения Карацубы
    unsigned __int128 p1 = (unsigned __int128)X.half.high * Y.half.high; // A1 * B1
    unsigned __int128 p2 = (unsigned __int128)X.half.low * Y.half.low; // A0 * B0
    
    // Суммы половинок (могут потребовать 65-й бит, поэтому кастуем к 64-битным)
    uint64_t sumX = X.half.high + X.half.low;
    uint64_t sumY = Y.half.high + Y.half.low;
    unsigned __int128 p3 = (unsigned __int128)sumX * sumY; // (A1 + A0) * (B1 + B0)

    // Шаг 3: Находим средний член
    unsigned __int128 middle = p3 - p1 - p2;

    // Шаг 4: Сборка финального 128-битного результата со сдвигом на 32 и 64 бита
    return (p1 << 64) + (middle << 32) + p2;
}

// Функция для красивого вывода 128-битного числа
void print_u128(unsigned __int128 n) {
    if (n == 0) {
        printf("0\n");
        return;
    }
    char buf[40];
    int i = 39;
    buf[i] = '\0';
    while (n > 0) {
        buf[--i] = "0123456789"[n % 10];
        n /= 10;
    }
    printf("%s\n", &buf[i]);
}

int main() {
    // Пример: перемножаем два больших 64-битных числа
    uint64_t a = 123456789012345ULL;
    uint64_t b = 987654321098765ULL;

    unsigned __int128 result = karatsuba_64(a, b);
    unsigned __int128 expected = (unsigned __int128)a * b;

    printf("Результат Карацубы:   ");
    print_u128(result);

    printf("Ожидаемый результат: ");
    print_u128(expected);

    return 0;
}
