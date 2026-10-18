// 0081 · Lista encadeada
// Exercício E484 · ★★☆
//
// Uma lista é NULL ou um nó seguido de outra lista. Essa definição é
// recursiva, e as funções também podem ser. O extrato recebeu os Pix 15, 60,
// 35, 90 e 25, inseridos no início. Escreva, SEM laço nenhum:
//
//   void imprime_ao_contrario(const No *p)  do mais antigo para o mais novo
//   int tamanho_rec(const No *p)            quantos nós
//
//   Saída esperada:
//   mais novo primeiro: 25 -> 90 -> 35 -> 60 -> 15 -> NULL
//   mais antigo primeiro: 15 60 35 90 25
//   tamanho (recursivo): 5
//
// Dicas:
// 1. Caso base das duas: p == NULL.
// 2. Para imprimir ao contrário, imprima o RESTO da lista primeiro
//    (chamada com p->prox) e só depois o p->valor.
// 3. tamanho_rec(p) = 1 + tamanho_rec(p->prox).
// 4. Resposta esperada: a saída acima. Para a primeira linha, use
//    printf("mais novo primeiro: ") seguido de lista_imprime.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "lista.h"

int main(void) {

    return 0;
}
