// 0087 · Pilha
// Exercício E519 · ★★☆
//
// Complete a função soma_pedido: ela devolve a soma de todos os preços da
// pilha (em centavos), usando só as funções do pilha.h. A pilha tem que
// voltar exatamente como estava, na mesma ordem: o cliente ainda pode
// querer desfazer.
//
//   Saída esperada:
//   Total: R$ 45,90
//   Topo continua: R$ 12,00 (3 itens)
//
// Dicas:
// 1. Você não enxerga o vetor lá dentro: para ver um item, precisa
//    desempilhar.
// 2. Use uma segunda pilha: desempilhe tudo para ela, somando, e depois
//    devolva tudo para a original. Ela volta na ordem certa porque inverter
//    duas vezes desfaz a inversão.
// 3. Não esqueça de liberar a pilha auxiliar.
// 4. Resposta esperada: Total: R$ 45,90 e o topo continua R$ 12,00, com 3
//    itens.
//
// Escreva sua resposta abaixo (complete soma_pedido):

#include <stdio.h>
#include "pilha.h"

int soma_pedido(Pilha *p) {
    (void)p; // apague esta linha quando usar p
    return 0;
}

int main(void) {
    Pilha *pedido = pilha_cria();
    if (pedido == NULL) {
        return 1;
    }
    pilha_empilha(pedido, 2590);
    pilha_empilha(pedido, 800);
    pilha_empilha(pedido, 1200);

    int total = soma_pedido(pedido);
    printf("Total: R$ %d,%02d\n", total / 100, total % 100);

    int topo;
    if (pilha_topo(pedido, &topo)) {
        printf("Topo continua: R$ %d,%02d (%d itens)\n", topo / 100, topo % 100, pilha_tamanho(pedido));
    }
    pilha_libera(pedido);
    return 0;
}
