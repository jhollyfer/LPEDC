// Lista · Módulo 15 · Tabelas hash
// Exercício P1507 · ★☆☆ · O hash djb2 dos nomes

#include <stdio.h>

#define M 16

// djb2: começa em 5381 e faz h = h * 33 + c para cada caractere
unsigned long long djb2(const char *s) {
    unsigned long long h = 5381;
    for (; *s != '\0'; s++) {
        h = h * 33 + (unsigned char)*s;
    }
    return h;
}

int main(void) {
    const char *nomes[] = {"ana", "bia", "caio", "davi", "eva", "abc", "acb"};
    for (int i = 0; i < 7; i++) {
        unsigned long long h = djb2(nomes[i]);
        printf("%-5s %llu -> balde %llu\n", nomes[i], h, h % M);
    }
    return 0;
}
