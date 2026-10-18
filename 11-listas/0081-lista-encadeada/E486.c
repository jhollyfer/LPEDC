// 0081 · Lista encadeada
// Exercício E486 · ★★★
//
// A fila de embarque foi montada ao contrário: 5 -> 4 -> 3 -> 2 -> 1.
// Escreva No *inverte(No *inicio), que inverte a lista SÓ MEXENDO NOS
// PONTEIROS: nada de malloc, nada de trocar os valores, nada de vetor
// auxiliar. Ela devolve o novo início. Teste também com a lista vazia e com
// uma lista de um nó só.
//
//   Saída esperada:
//   antes:  5 -> 4 -> 3 -> 2 -> 1 -> NULL
//   depois: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
//   vazia:  NULL
//   um só:  7 -> NULL
//
// Dicas:
// 1. Use três ponteiros: ant (começa NULL), p (começa no início) e seg.
// 2. A cada passo: seg = p->prox; p->prox = ant; ant = p; p = seg. A ordem
//    importa: se você trocar p->prox antes de guardar seg, perde o resto.
// 3. Quando p vira NULL, ant é o novo início.
// 4. Resposta esperada: a saída acima. É O(n) em tempo e O(1) em memória
//    extra.
//
// Escreva sua resposta abaixo (troque o corpo de inverte):

#include <stdio.h>
#include "lista.h"

No *inverte(No *inicio) {
    return inicio; // por enquanto não inverte nada
}

int main(void) {
    No *fila = NULL;
    for (int i = 1; i <= 5; i++) fila = lista_insere_inicio(fila, i);
    printf("antes:  ");
    lista_imprime(fila);
    fila = inverte(fila);
    printf("depois: ");
    lista_imprime(fila);

    No *vazia = inverte(NULL);
    printf("vazia:  ");
    lista_imprime(vazia);

    No *um = inverte(lista_insere_inicio(NULL, 7));
    printf("um só:  ");
    lista_imprime(um);

    lista_libera(fila);
    lista_libera(um);
    return 0;
}
