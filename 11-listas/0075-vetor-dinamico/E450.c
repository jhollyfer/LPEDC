// 0075 · Vetor dinâmico
// Exercício E450 · ★★★
//
// Um vetor que só cresce nunca devolve memória. Usando a struct Vet abaixo,
// escreva vet_empurra (põe no fim; quando tam == cap, dobra a capacidade com
// realloc) e duas funções que tiram o último item, guardam em *saiu e
// encolhem o vetor pela metade (nunca abaixo de capacidade 2):
//
//   bool vet_tira(Vet *v, int *saiu)         encolhe se tam <= cap / 4
//   bool vet_tira_metade(Vet *v, int *saiu)  encolhe se tam <= cap / 2
//
// Some 1 em v->reallocs a cada realloc que der certo. No main: comece com um
// vetor de cap 2, empurre 1 a 9, esvazie com vet_tira mostrando cada passo;
// depois crie dois vetores com 1, 2, 3, 4 (tam 4, cap 4, reallocs zerado) e,
// 10 vezes, empurre 5 e tire, um com cada regra, mostrando os reallocs.
//
//   Saída esperada:
//   empurrou 9: tam 9, cap 16
//   tirou 9: tam 8, cap 16
//   tirou 8: tam 7, cap 16
//   tirou 7: tam 6, cap 16
//   tirou 6: tam 5, cap 16
//   tirou 5: tam 4, cap 8
//   tirou 4: tam 3, cap 8
//   tirou 3: tam 2, cap 4
//   tirou 2: tam 1, cap 2
//   tirou 1: tam 0, cap 2
//   alternando com 1/2: 20 realloc
//   alternando com 1/4: 1 realloc
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *itens;
    int tam;
    int cap;
    int reallocs; // quantos realloc deram certo
} Vet;

int main(void) {

    return 0;
}
