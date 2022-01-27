#include <iostream>
#include <random>
#include <clocale>

int digit(int x, int n) {
    int result;
    while (n != 0) {
        result = x % 10;
        x /= 10;
        n--;
    }
    return result;
}

void radixsort(int *p, int s, int n) {
    int *p1;
    p1 = (int*)malloc(s * sizeof(int));
    for (int i = 1, k; i <= n; i++) {
        k = 0;
        for (int j = 0; j != s; j++) {
            if (digit(p[j], i) == 0) {
                p1[k] = p[j];
                k += 1;
            }
        }
        for (int j = 0; j != s; j++) {
            if (digit(p[j], i) == 1) {
                p1[k] = p[j];
                k += 1;
            }
        }
        for (int j = 0; j != s; j++) {
            if (digit(p[j], i) == 2) {
                p1[k] = p[j];
                k += 1;
            }
        }
        for (int j = 0; j != s; j++) {
            if (digit(p[j], i) == 3) {
                p1[k] = p[j];
                k += 1;
            }
        }
        for (int j = 0; j != s; j++) {
            if (digit(p[j], i) == 4) {
                p1[k] = p[j];
                k += 1;
            }
        }
        for (int j = 0; j != s; j++) {
            if (digit(p[j], i) == 5) {
                p1[k] = p[j];
                k += 1;
            }
        }
        for (int j = 0; j != s; j++) {
            if (digit(p[j], i) == 6) {
                p1[k] = p[j];
                k += 1;
            }
        }
        for (int j = 0; j != s; j++) {
            if (digit(p[j], i) == 7) {
                p1[k] = p[j];
                k += 1;
            }
        }
        for (int j = 0; j != s; j++) {
            if (digit(p[j], i) == 8) {
                p1[k] = p[j];
                k += 1;
            }
        }
        for (int j = 0; j != s; j++) {
            if (digit(p[j], i) == 9) {
                p1[k] = p[j];
                k += 1;
            }
        }
        for (int i = 0; i != s; i++) p[i] = p1[i];
    }
    free(p1);
}

int main() {
    int max, n = 1, s, *p;
    std::setlocale(LC_CTYPE, "Russian");
    std::uniform_int_distribution<> uid(0, 2874730), uid1(2, 40);
    std::mt19937 gen;
    std::random_device rd;
    gen.seed(rd());
    s = uid1(gen);
    std::cout << "Размер случайно генерируемого массива равен: " << s << std::endl << std::endl;
    p = (int*)malloc(s * sizeof(int));
    for (int i = 0; i != s; i++) {
        std::random_device rd;
        gen.seed(rd());
        p[i] = uid(gen);
    }
    std::cout << "Случайно сгенерированный массив: " << std::endl << std::endl;
    for (int i = 0; i != s; i++) {
        std::cout << "| " << p[i] << " ";
        if (i % 2 == 1) std::cout << "|" << std::endl;
    }
    max = p[0];
    for (int j = 1; j != s; j += 1) {
        if (p[j] > max) max = p[j];
    }
    while ((max /= 10) > 0) n++;
    radixsort(p, s, n);
    std::cout << std::endl << "Этот же массив, отсортированный по убыванию: " << std::endl << std::endl;
    for (int i = 0; i != s; i++) {
        std::cout << "| " << p[i] << " ";
        if (i % 2 == 1) std::cout << "|" << std::endl;
    }
    std::cout << std::endl << std::endl;
    return 0;
}