// pombal.c · implementação do pigeonhole sort e das ordenações por nota
#include <stdio.h>
#include <stdlib.h>
#include "pombal.h"

int pb_pigeonhole(Aluno *v, int n, int min, int max) {
    int casas = max - min + 1;
    // cada casa é uma fila de índices: primeiro[c], ultimo[c] e prox[i]
    int *primeiro = malloc((size_t)casas * sizeof(int));
    int *ultimo = malloc((size_t)casas * sizeof(int));
    int *prox = malloc((size_t)n * sizeof(int));
    Aluno *saida = malloc((size_t)n * sizeof(Aluno));
    if (primeiro == NULL || ultimo == NULL || prox == NULL || saida == NULL) {
        free(primeiro);
        free(ultimo);
        free(prox);
        free(saida);
        return -1;
    }
    for (int c = 0; c < casas; c++) {
        primeiro[c] = -1;
    }
    for (int i = 0; i < n; i++) { // 1. cada aluno entra no fim da fila da sua casa
        int c = v[i].nota - min;
        prox[i] = -1;
        if (primeiro[c] == -1) {
            primeiro[c] = i;
        } else {
            prox[ultimo[c]] = i;
        }
        ultimo[c] = i;
    }
    int k = 0;
    for (int c = 0; c < casas; c++) { // 2. esvazia as casas em ordem
        for (int i = primeiro[c]; i != -1; i = prox[i]) {
            saida[k++] = v[i];
        }
    }
    for (int i = 0; i < n; i++) {
        v[i] = saida[i];
    }
    free(primeiro);
    free(ultimo);
    free(prox);
    free(saida);
    return 0;
}

void pb_selecao(Aluno *v, int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j].nota < v[menor].nota) {
                menor = j;
            }
        }
        Aluno t = v[i]; // a troca pula por cima de quem está no meio
        v[i] = v[menor];
        v[menor] = t;
    }
}

void pb_insercao(Aluno *v, int n) {
    for (int i = 1; i < n; i++) {
        Aluno x = v[i];
        int j = i - 1;
        while (j >= 0 && v[j].nota > x.nota) { // > e não >=: empate não passa na frente
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

void pb_mostra(const Aluno *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s%s(%d)", i > 0 ? " " : "", v[i].nome, v[i].nota);
    }
    printf("\n");
}
