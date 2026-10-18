// 0117 · Limite inferior da ordenação
// Exercício E697 · ★☆☆

#include <stdio.h>

// menor h com 2^h >= x, só com inteiros
int teto_log2(unsigned long long x) {
    int h = 0;
    unsigned long long folhas = 1; // 2^h
    while (folhas < x) {
        folhas *= 2;
        h++;
    }
    return h;
}

int main(void) {
    unsigned long long fat = 1;
    printf(" n                   n!  limite\n");
    for (int n = 1; n <= 20; n++) {
        fat *= n;
        printf("%2d %20llu  %6d\n", n, fat, teto_log2(fat));
    }
    return 0;
}
