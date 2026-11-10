// 0162 · Matriz esparsa
// Exercício E967 · ★☆☆
//
// Um app de delivery guarda as notas (1 a 5) que 4 clientes deram a 10
// restaurantes numa matriz esparsa (esparsa.h). Escreva
// int resumo_linha(const Esparsa *m, int i, int *qtd): percorre só as células
// da linha i, devolve a soma das notas e guarda em *qtd quantas notas a linha
// tem. No main (a matriz já está montada), mostre a média de cada cliente:
//
//   Saída esperada:
//   Cliente 0: 3 notas, média 4.00
//   Cliente 1: 1 nota, média 2.00
//   Cliente 2: 0 notas
//   Cliente 3: 4 notas, média 3.50
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "0162-esparsa.h"

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

    esp_libera(notas);
    return 0;
}
