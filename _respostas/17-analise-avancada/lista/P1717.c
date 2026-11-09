// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1717 · ★★☆ · Conserte o vetor que cresce de 10 em 10

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *item;
    int num, cap;
    long copias;
    int realocacoes;
} Vetor;

void insere(Vetor *v, int x) {
    if (v->num == v->cap) {
        int nova = 2 * v->cap; // dobra: o custo das cópias fica O(1) amortizado
        int *novo = malloc(nova * sizeof *novo);
        if (novo == NULL) exit(1);
        for (int i = 0; i < v->num; i++) novo[i] = v->item[i];
        v->copias += v->num;
        v->realocacoes++;
        free(v->item);
        v->item = novo;
        v->cap = nova;
    }
    v->item[v->num++] = x;
}

int main(void) {
    Vetor v = {malloc(10 * sizeof(int)), 0, 10, 0, 0};
    if (v.item == NULL) return 1;
    for (int i = 0; i < 10000; i++) insere(&v, 5000 + i);
    printf("Pedidos: %d | capacidade: %d\n", v.num, v.cap);
    printf("Realocações: %d | cópias: %ld (%.2f por pedido)\n", v.realocacoes, v.copias,
           (double)v.copias / v.num);
    free(v.item);
    return 0;
}
