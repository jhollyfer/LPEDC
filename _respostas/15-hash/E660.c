// 0110 · A ideia e a função hash
// Exercício E660 · ★★★

#include <stdio.h>
#include <stdbool.h>

#define N 8

unsigned hash_pol(const char *s) {
    unsigned h = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        h = h * 31 + (unsigned char)s[i];
    }
    return h;
}

// m serve se nenhum par de palavras cai no mesmo balde
bool sem_colisao(const unsigned h[], int n, int m) {
    bool usado[64] = {false};
    for (int i = 0; i < n; i++) {
        unsigned b = h[i] % (unsigned)m;
        if (usado[b]) {
            return false;
        }
        usado[b] = true;
    }
    return true;
}

int main(void) {
    const char *palavras[N] = {"int", "char", "if", "else", "for", "while", "return", "void"};
    unsigned h[N];
    for (int i = 0; i < N; i++) {
        h[i] = hash_pol(palavras[i]);
    }

    int m = 8;
    while (m < 64 && !sem_colisao(h, N, m)) {
        m++;
    }
    printf("m = %d\n", m);
    for (int i = 0; i < N; i++) {
        printf("%s -> %u\n", palavras[i], h[i] % (unsigned)m);
    }
    return 0;
}
