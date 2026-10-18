// 0162 · Matriz esparsa
// Exercício E967 · ★☆☆

#include <stdio.h>
#include "esparsa.h"

int resumo_linha(const Esparsa *m, int i, int *qtd) {
    int soma = 0;
    *qtd = 0;
    for (const Celula *c = m->linha[i]; c != NULL; c = c->prox) {
        soma += c->valor;
        (*qtd)++;
    }
    return soma;
}

int main(void) {
    Esparsa *notas = esp_cria(4, 10);
    esp_define(notas, 0, 2, 5);
    esp_define(notas, 0, 7, 3);
    esp_define(notas, 0, 9, 4);
    esp_define(notas, 1, 4, 2);
    esp_define(notas, 3, 0, 5);
    esp_define(notas, 3, 8, 4);
    esp_define(notas, 3, 3, 1);
    esp_define(notas, 3, 5, 4);

    for (int i = 0; i < notas->linhas; i++) {
        int qtd;
        int soma = resumo_linha(notas, i, &qtd);
        if (qtd == 0) {
            printf("Cliente %d: 0 notas\n", i);
        } else {
            printf("Cliente %d: %d %s, média %.2f\n", i, qtd, qtd == 1 ? "nota" : "notas",
                   (double)soma / qtd);
        }
    }

    esp_libera(notas);
    return 0;
}
