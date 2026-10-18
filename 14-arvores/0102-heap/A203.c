// A203 · O leilão com vagas contadas

#include <stdio.h>
#include "heap.h"

int main(void) {
    // lances (em R$) por uma bicicleta usada; o leiloeiro só anota 4
    int lances[] = {300, 450, 450, 200, 500};
    Heap *mesa = heap_cria(4);

    for (int i = 0; i < 5; i++) {
        // heap_insere avisa quando não cabe: o vetor tem tamanho fixo, e o
        // heap recusa até o maior lance de todos
        if (heap_insere(mesa, lances[i])) {
            printf("Lance R$ %d anotado: ", lances[i]);
        } else {
            printf("Lance R$ %d recusado, mesa cheia: ", lances[i]);
        }
        heap_mostra(mesa);
        printf("\n");
    }

    // olhar o topo não tira ninguém
    printf("Maior lance agora: R$ %d\n", heap_topo(mesa));
    printf("Olhei de novo: R$ %d\n", heap_topo(mesa));

    // empate: os dois 450 continuam lá, um depois do outro
    while (!heap_vazio(mesa)) {
        printf("Sai R$ %d\n", heap_remove(mesa));
    }

    heap_libera(mesa);
    return 0;
}
// Saída:
// Lance R$ 300 anotado: [300]
// Lance R$ 450 anotado: [450 300]
// Lance R$ 450 anotado: [450 300 450]
// Lance R$ 200 anotado: [450 300 450 200]
// Lance R$ 500 recusado, mesa cheia: [450 300 450 200]
// Maior lance agora: R$ 450
// Olhei de novo: R$ 450
// Sai R$ 450
// Sai R$ 450
// Sai R$ 300
// Sai R$ 200
