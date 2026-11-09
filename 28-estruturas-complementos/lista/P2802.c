// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2802 · ★☆☆ · A chave guardada na sentinela
//
// Na busca com sentinela do Cormen, a chave procurada é copiada para
// nil.chave antes do laço, e o laço só testa x->chave != k. Monte a lista
// com sentinela 4, 8, 15, 16, 23, 42 (insira no fim) e escreva busca(L, k,
// &comparacoes), que devolve o nó achado (ou &L->nil) e conta quantas vezes
// x->chave != k foi avaliado. Busque 15, 42 e 99.
//
//   Saída esperada:
//   15: achou, 3 comparações
//   42: achou, 6 comparações
//   99: não está, 7 comparações
//
// Dicas:
// 1. Antes do laço: L->nil.chave = k; x = L->nil.prox.
// 2. Cada volta do while é uma comparação; a última (a que dá falso) também
//    conta.
// 3. Para 99, o laço passa pelos 6 nós e para na sentinela: 7 comparações.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
