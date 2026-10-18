// 0134 · Seleção de intervalos
// Exercício E804 · ★★★

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *time;
    int ini, fim; // [ini, fim), em horas
} Jogo;

int por_fim(const void *a, const void *b) {
    const Jogo *x = a, *y = b;
    if (x->fim != y->fim) {
        return (x->fim > y->fim) - (x->fim < y->fim);
    }
    return (x->ini > y->ini) - (x->ini < y->ini); // empate: quem começa antes

}

int main(void) {
    Jogo j[] = {
        {"Leões", 8, 10},   {"Tubarões", 8, 11}, {"Águias", 9, 12},
        {"Lobos", 10, 12},  {"Falcões", 11, 13}, {"Panteras", 12, 14},
        {"Touros", 10, 15}, {"Corujas", 13, 16}, {"Raposas", 14, 16},
        {"Ursos", 15, 17},
    };
    int n = 10;
    int livre_em[2] = {0, 0}; // as duas quadras
    int aceitos = 0;

    qsort(j, n, sizeof j[0], por_fim);
    for (int i = 0; i < n; i++) {
        // das quadras livres, a que ficou livre MAIS TARDE (desperdiça menos)
        int q = -1;
        for (int k = 0; k < 2; k++) {
            if (livre_em[k] <= j[i].ini && (q < 0 || livre_em[k] > livre_em[q])) {
                q = k;
            }
        }
        if (q < 0) {
            printf("%2dh-%2dh recusado  %s\n", j[i].ini, j[i].fim, j[i].time);
        } else {
            livre_em[q] = j[i].fim;
            aceitos++;
            printf("%2dh-%2dh quadra %d  %s\n", j[i].ini, j[i].fim, q + 1, j[i].time);
        }
    }
    printf("Jogos aceitos: %d de %d\n", aceitos, n);
    return 0;
}
