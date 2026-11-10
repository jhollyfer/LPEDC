// heap.h · interface do TAD heap de máximo (fila de prioridade de int)
#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>

// a árvore mora no vetor: pai de i em (i - 1) / 2, filhos em 2i + 1 e 2i + 2
typedef struct {
    int *v;  // os elementos
    int n;   // quantos tem agora
    int cap; // quantos cabem
} Heap;

Heap *heap_cria(int cap);
bool heap_insere(Heap *h, int x); // false se estiver cheio
int heap_remove(Heap *h);         // tira e devolve o máximo (não pode estar vazio)
int heap_topo(const Heap *h);     // só olha o máximo
bool heap_vazio(const Heap *h);
void heap_mostra(const Heap *h);  // mostra o vetor
void heap_libera(Heap *h);

#endif
