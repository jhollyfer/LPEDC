// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2028 · ★★★ · Vigias para o dia inteiro

#include <stdio.h>

#define N 9

typedef struct {
    const char *nome;
    int ini, fim;
} Turno;

void cobre(const Turno v[], int n) {
    int t = 0, vigias = 0;
    while (t < 24) {
        int melhor = -1;
        for (int i = 0; i < n; i++) {
            if (v[i].ini <= t && (melhor < 0 || v[i].fim > v[melhor].fim)) {
                melhor = i;
            }
        }
        if (melhor < 0 || v[melhor].fim <= t) {
            printf("  Buraco: ninguém cobre depois das %dh\n", t);
            return;
        }
        printf("  %s [%d, %d]\n", v[melhor].nome, v[melhor].ini, v[melhor].fim);
        t = v[melhor].fim;
        vigias++;
    }
    printf("  Total: %d vigias\n", vigias);
}

int main(void) {
    Turno v[N] = {{"Edu", 0, 6}, {"Bia", 2, 9}, {"Gil", 5, 12}, {"Ana", 8, 14}, {"Caio", 10, 18},
                  {"Rui", 15, 20}, {"Lia", 17, 24}, {"Davi", 19, 24}, {"Teo", 0, 4}};
    printf("Todos:\n");
    cobre(v, N);
    Turno sem[N - 1];
    int k = 0;
    for (int i = 0; i < N; i++) {
        if (v[i].nome[0] != 'C') {
            sem[k++] = v[i];
        }
    }
    printf("Sem a Caio:\n");
    cobre(sem, k);
    return 0;
}
