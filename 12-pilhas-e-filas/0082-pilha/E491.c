// 0082 · Pilha
// Exercício E491 · ★★★
//
// Os números 1, 2, 3, 4 chegam nessa ordem. A cada passo você pode empilhar
// o próximo que chegou (E) ou desempilhar e mostrar o topo (D). A sequência
// EEDEDDED, por exemplo, mostra 2 3 1 4.
//
// Escreva a função void simula(const char *ops), que recebe a sequência de
// letras e mostra os números na ordem em que saem. Se aparecer um D com a
// pilha vazia, mostre "erro: pilha vazia" e pare. Teste com as três
// sequências do main pronto abaixo.
//
//   Saída esperada:
//   EEDEDDED: 2 3 1 4
//   EEEDDDED: 3 2 1 4
//   EDDE: 1 erro: pilha vazia
//
// Depois escreva bool possivel(const int ordem[], int n), que diz se uma
// ordem de saída dá para ser produzida pela pilha (com os números chegando
// 1, 2, ..., n), e teste com 2 3 1 4 e 3 1 2 4.
//
//   Saída esperada (continuação):
//   2 3 1 4: possível
//   3 1 2 4: impossível
//
// Dicas:
// 1. Guarde num int o próximo número a chegar (começa em 1).
// 2. pilha_desempilha devolve false com a pilha vazia: é o seu teste de
//    erro.
// 3. Libere a pilha antes de sair da função, inclusive no caso de erro.
// 4. Em possivel, para cada número da ordem: empilhe os que chegam até ele
//    aparecer no topo. Se ele já passou e não está no topo, é impossível.
// 5. Resposta esperada: as cinco linhas acima. 3 1 2 4 é impossível: para o
//    3 sair primeiro, o 1 e o 2 precisam estar empilhados com o 2 por cima
//    do 1. Então o 2 sai antes do 1, sempre.
//
// Escreva sua resposta abaixo (escreva simula e possivel):

#include <stdbool.h>
#include <stdio.h>
#include "pilha.h"

int main(void) {
    // simula("EEDEDDED");
    // simula("EEEDDDED");
    // simula("EDDE");
    // int boa[] = {2, 3, 1, 4};
    // int ruim[] = {3, 1, 2, 4};
    // printf("2 3 1 4: %s\n", possivel(boa, 4) ? "possível" : "impossível");
    // printf("3 1 2 4: %s\n", possivel(ruim, 4) ? "possível" : "impossível");
    return 0;
}
