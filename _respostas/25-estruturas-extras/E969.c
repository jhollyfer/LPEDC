// 0162 · Matriz esparsa
// Exercício E969 · ★★☆

#include <stdio.h>
#include "esparsa.h"

Esparsa *transposta(const Esparsa *m) {
    Esparsa *t = esp_cria(m->colunas, m->linhas);
    for (int i = 0; i < m->linhas; i++) {
        for (const Celula *c = m->linha[i]; c != NULL; c = c->prox) {
            esp_define(t, c->col, i, c->valor); // (i, col) vira (col, i)
        }
    }
    return t;
}

int main(void) {
    Esparsa *notas = esp_cria(4, 6); // 4 clientes x 6 filmes
    esp_define(notas, 0, 0, 5);
    esp_define(notas, 0, 2, 3);
    esp_define(notas, 1, 2, 1);
    esp_define(notas, 2, 0, 4);
    esp_define(notas, 3, 2, 4);
    esp_define(notas, 3, 5, 1);

    Esparsa *por_filme = transposta(notas);
    for (int f = 0; f < por_filme->linhas; f++) {
        if (por_filme->linha[f] == NULL) {
            continue; // filme sem nota
        }
        int soma = 0, qtd = 0;
        for (const Celula *c = por_filme->linha[f]; c != NULL; c = c->prox) {
            soma += c->valor;
            qtd++;
        }
        printf("Filme %d: %d %s, média %.2f\n", f, qtd, qtd == 1 ? "nota" : "notas",
               (double)soma / qtd);
    }
    printf("Células: %d e %d\n", notas->nao_zeros, por_filme->nao_zeros);

    esp_libera(notas);
    esp_libera(por_filme);
    return 0;
}
