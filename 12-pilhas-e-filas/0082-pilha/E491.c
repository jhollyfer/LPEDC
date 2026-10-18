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
// Depois responda sem programar: dá para sair 3 1 2 4? Por quê?
//
// Dicas:
// 1. Guarde num int o próximo número a chegar (começa em 1).
// 2. pilha_desempilha devolve false com a pilha vazia: é o seu teste de
//    erro.
// 3. Libere a pilha antes de sair da função, inclusive no caso de erro.
// 4. Resposta esperada: as três linhas acima. 3 1 2 4 é impossível: para o
//    3 sair primeiro, o 1 e o 2 precisam estar empilhados com o 2 por cima
//    do 1. Então o 2 sai antes do 1, sempre.
//
// Escreva sua resposta abaixo (escreva simula):

#include <stdio.h>
#include "pilha.h"

int main(void) {
    // simula("EEDEDDED");
    // simula("EEEDDDED");
    // simula("EDDE");
    return 0;
}
