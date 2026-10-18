// 0148 · Union-find
// Exercício E883 · ★☆☆
//
// Depois da enchente, só algumas estradas entre sete cidades continuam
// abertas. Use o TAD (uniao.h): una as cidades de cada estrada aberta, mostre
// quantos grupos de cidades ligadas existem e mostre, para cada pergunta,
// se dá para ir de uma cidade à outra (passando por outras, se preciso).
//
//   Saída esperada:
//   Grupos de cidades ligadas: 3
//   Araras -> Dourado: dá para ir
//   Bauru -> Garça: dá para ir
//   Dourado -> Franca: não dá para ir
//   Embu -> Embu: dá para ir
//
// Dicas:
// 1. uf_cria(7), um uf_une por estrada e uf_grupos no fim.
// 2. Para cada pergunta, uf_juntos(u, a, b). A pergunta não é se existe uma
//    estrada DIRETA: Araras e Dourado também se ligam pela Catanduva.
// 3. Resposta esperada: a saída acima. Os grupos são {Araras, Catanduva,
//    Dourado}, {Bauru, Franca, Garça} e {Embu}.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "uniao.h"

int main(void) {
    const char *cidade[] = {"Araras", "Bauru", "Catanduva", "Dourado", "Embu", "Franca", "Garça"};
    int estradas[][2] = {{0, 2}, {1, 5}, {2, 3}, {5, 6}, {0, 3}};
    int perguntas[][2] = {{0, 3}, {1, 6}, {3, 5}, {4, 4}};
    (void)cidade; // apague estas três linhas
    (void)estradas;
    (void)perguntas;

    return 0;
}
