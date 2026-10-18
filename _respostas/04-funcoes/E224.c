// 0038 · Recursão na prática: Fibonacci, Hanói e Euclides
// Exercício E224 · ★☆☆

#include <stdio.h>

unsigned long long movimentos(int n) {
    if (n == 0) {
        return 0;
    }
    return 2 * movimentos(n - 1) + 1;
}

int main(void) {
    printf("3 discos: %llu\n", movimentos(3));
    printf("10 discos: %llu\n", movimentos(10));
    printf("20 discos: %llu\n", movimentos(20));
    printf("64 discos: %llu\n", movimentos(64));
    return 0;
}
