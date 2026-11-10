// 0162 · Matriz esparsa
// Exercício E967 · ★☆☆
//
// Um app de delivery guarda as notas (1 a 5) que 4 clientes deram a 10
// restaurantes numa matriz esparsa (esparsa.h). Complete resumo_linha, que
// percorre só as células da linha i e devolve a soma das notas, guardando em
// *qtd quantas notas a linha tem. O main já mostra a média de cada cliente.
//
//   Saída esperada:
//   Cliente 0: 3 notas, média 4.00
//   Cliente 1: 1 nota, média 2.00
//   Cliente 2: 0 notas
//   Cliente 3: 4 notas, média 3.50
//
// Escreva sua resposta abaixo (complete resumo_linha):

#include <stdio.h>
#include "esparsa.h"

int resumo_linha(const Esparsa *m, int i, int *qtd) {
    (void)m; // apague estas três linhas
    (void)i;
    *qtd = 0;
    return 0;
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
