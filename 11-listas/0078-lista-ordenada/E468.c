// 0078 · Lista ordenada
// Exercício E468 · ★★★
//
// Os pedidos do delivery chegaram fora de ordem: 3 -> 7 -> 1 -> 9 -> 4.
// Escreva No *ordena(No *inicio), que deixa a lista em ordem crescente pelo
// método da inserção, SÓ RELIGANDO os nós: nada de malloc, nada de free,
// nada de trocar valores entre nós.
//
//   Saída esperada:
//   antes:  3 -> 7 -> 1 -> 9 -> 4 -> NULL
//   depois: 1 -> 3 -> 4 -> 7 -> 9 -> NULL
//
// Depois responda: quanto custa ordenar n nós assim, no pior caso?
//
// Dicas:
// 1. Comece uma lista "ordenada" vazia (NULL). Enquanto a original tiver nós,
//    DESENGATE o primeiro dela (guarde o resto antes!).
// 2. Encaixe o nó desengatado na ordenada com o mesmo laço ant/p da
//    inserção ordenada, só que sem malloc: o nó já existe.
// 3. Resposta esperada: a saída acima. Cada encaixe percorre até a lista
//    ordenada inteira: 0 + 1 + ... + (n-1), O(n²) no pior caso. A vantagem
//    sobre o vetor é que encaixar não desloca ninguém.
//
// Escreva sua resposta abaixo (troque o corpo de ordena):

#include <stdio.h>
#include "lista.h"

No *ordena(No *inicio) {
    return inicio; // por enquanto não ordena nada
}

int main(void) {
    int pedidos[] = {4, 9, 1, 7, 3}; // inseridos no início: ficam ao contrário
    No *l = NULL;
    for (int i = 0; i < 5; i++) l = lista_insere_inicio(l, pedidos[i]);

    printf("antes:  ");
    lista_imprime(l);
    l = ordena(l);
    printf("depois: ");
    lista_imprime(l);

    lista_libera(l);
    return 0;
}
