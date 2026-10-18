// 0134 · Seleção de intervalos
// Exercício E800 · ★☆☆

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *cliente;
    int ini, fim; // minutos desde a abertura, [ini, fim)
} Horario;

int por_fim(const void *a, const void *b) {
    const Horario *x = a;
    const Horario *y = b;
    return (x->fim > y->fim) - (x->fim < y->fim);
}

int main(void) {
    Horario h[] = {
        {"Rita", 60, 150}, {"Lia", 0, 45},    {"Bia", 30, 90},
        {"Gabi", 150, 180}, {"Nina", 100, 120}, {"Duda", 45, 100},
        {"Mel", 120, 200},
    };
    int n = 7;

    qsort(h, n, sizeof h[0], por_fim);
    int livre_em = 0;
    for (int i = 0; i < n; i++) {
        if (h[i].ini >= livre_em) {
            printf("%s (%d a %d)\n", h[i].cliente, h[i].ini, h[i].fim);
            livre_em = h[i].fim;
        }
    }
    return 0;
}
