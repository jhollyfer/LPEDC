// 0102 · Heap e fila de prioridade
// Exercício E610 · ★★☆

#include <stdio.h>
#include "heap.h"

int main(void) {
    int senhas[] = {7, 3, 9, 1, 5};
    Heap *fila = heap_cria(5);
    for (int i = 0; i < 5; i++) {
        heap_insere(fila, -senhas[i]); // a menor senha vira o maior número
    }
    while (!heap_vazio(fila)) {
        printf("Chamando senha %d\n", -heap_remove(fila));
    }
    heap_libera(fila);
    return 0;
}
