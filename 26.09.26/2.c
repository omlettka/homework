#include <iostream>

// Рекурсивный алгоритм Евклида
int gcd_euclid_rec(int a, int b) {
    if (b == 0) return a;
    return gcd_euclid_rec(b, a % b);
}

// Итеративный вариант (без рекурсии)
int gcd_euclid_iter(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    std::cout << "НОД(64, 57) = " << gcd_euclid_rec(64, 57) << std::endl;  // 1
    std::cout << "НОД(48, 18) = " << gcd_euclid_iter(48, 18) << std::endl; // 6
    return 0;
}