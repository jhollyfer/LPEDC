// 0162 · Matriz esparsa
// Exercício E971 · ★★★
//
// Uma rede de farmácias guarda o estoque numa matriz esparsa filial x
// produto (esparsa.h). No fim do dia chega a matriz de movimento: entrada é
// positiva, venda é negativa. Escreva soma(a, b), que devolve uma NOVA
// Esparsa com a + b, sem usar esp_valor e sem esp_define: monte cada linha
// do resultado intercalando as duas listas, como no merge do merge sort.
// Quando a soma der 0, a célula não entra.
//
//   Saída esperada:
//   Estoque novo:
//     4  0  0  0  9  0
//     0  0  0  3  0  0
//     0  2  0  0  0  0
//   Células: 4
//
// Escreva sua resposta abaixo (complete soma):

#include <stdio.h>
#include <stdlib.h>
#include "esparsa.h"

Esparsa *soma(const Esparsa *a, const Esparsa *b) {
    Esparsa *c = esp_cria(a->linhas, a->colunas);
    (void)b; // apague esta linha
    return c;
}

int main(void) {
    Esparsa *estoque = esp_cria(3, 6);
    esp_define(estoque, 0, 0, 4);
    esp_define(estoque, 0, 2, 5);
    esp_define(estoque, 1, 0, 2);
    esp_define(estoque, 1, 3, 3);
    esp_define(estoque, 2, 1, 2);

    Esparsa *movimento = esp_cria(3, 6);
    esp_define(movimento, 0, 2, -5); // vendeu tudo do produto 2
    esp_define(movimento, 0, 4, 9);  // chegou o produto 4
    esp_define(movimento, 1, 0, -2);

    Esparsa *novo = soma(estoque, movimento);
    printf("Estoque novo:\n");
    esp_mostra(novo);
    printf("Células: %d\n", novo->nao_zeros);

    esp_libera(estoque);
    esp_libera(movimento);
    esp_libera(novo);
    return 0;
}
