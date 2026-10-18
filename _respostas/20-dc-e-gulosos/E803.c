// 0134 · Seleção de intervalos
// Exercício E803 · ★★★

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *banda;
    int ini, fim; // [ini, fim), em horas
} Show;

int por_fim(const void *a, const void *b) {
    const Show *x = a, *y = b;
    return (x->fim > y->fim) - (x->fim < y->fim);
}

int main(void) {
    Show s[] = {
        {"Forró do Zé", 14, 16}, {"Samba da Vila", 16, 18}, {"Rock Raiz", 15, 19},
        {"MPB Nova", 18, 20},    {"Pagode 10", 17, 21},     {"Axé Total", 20, 22},
        {"Funk Sul", 21, 23},    {"Brega Chic", 22, 24},
    };
    int n = 8;

    qsort(s, n, sizeof s[0], por_fim);
    int livre_em = 0;
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (s[i].ini >= livre_em) {   // [ini, fim): encostar é permitido
            printf("%dh-%dh %s\n", s[i].ini, s[i].fim, s[i].banda);
            total++;
            livre_em = s[i].fim;      // só quem foi aceito ocupa o palco
        }
    }
    printf("Shows no palco: %d\n", total);
    return 0;
}
