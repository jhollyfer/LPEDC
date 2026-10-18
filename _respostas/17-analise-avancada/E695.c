// 0116 · Análise amortizada
// Exercício E695 · ★★★

#include <stdbool.h>
#include <stdio.h>

#define CAP 1000000

typedef struct {
    int v[CAP];
    int topo;
} Pilha;

Pilha entrada, saida;           // globais: 8 MB fora da pilha de chamadas
long transferencias = 0;

void empilha(Pilha *p, int x) {
    p->v[p->topo++] = x;
}

int desempilha(Pilha *p) {
    return p->v[--p->topo];
}

void enfileira(int x) {
    empilha(&entrada, x);
}

bool fila_vazia(void) {
    return entrada.topo == 0 && saida.topo == 0;
}

// devolve o mais antigo; só vira a entrada quando a saída está vazia
int desenfileira(int *custo) {
    *custo = 1;
    if (saida.topo == 0) {
        while (entrada.topo > 0) {
            empilha(&saida, desempilha(&entrada));
            transferencias++;
            (*custo)++;
        }
    }
    return desempilha(&saida);
}

int main(void) {
    int custo;
    printf("atendidos:");
    for (int i = 1; i <= 5; i++) {
        enfileira(i);
    }
    for (int i = 0; i < 2; i++) {
        printf(" %d", desenfileira(&custo));
    }
    enfileira(6);
    enfileira(7);
    for (int i = 0; i < 4; i++) {
        printf(" %d", desenfileira(&custo));
    }
    enfileira(8);
    for (int i = 0; i < 2; i++) {
        printf(" %d", desenfileira(&custo));
    }
    printf("\n8 pedidos, %ld transferências\n", transferencias);

    // um milhão de operações: a cada 3, uma é atender
    entrada.topo = saida.topo = 0;
    transferencias = 0;
    long enfileirados = 0;
    int pior = 0;
    for (int i = 1; i <= 1000000; i++) {
        if (i % 3 == 0 && !fila_vazia()) {
            desenfileira(&custo);
            if (custo > pior) {
                pior = custo;
            }
        } else {
            enfileira(i);
            enfileirados++;
        }
    }
    printf("%ld enfileirados, %ld transferências, pior atendimento: %d\n", enfileirados, transferencias, pior);
    return 0;
}
