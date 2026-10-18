// 0083 · Pilha encadeada
// Exercício E493 · ★☆☆

#include <stdio.h>
// Na pasta do assunto basta #include "pilha.h" (o rodar compila o pilha.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0083-pilha-encadeada/pilha.c"

void estado(const Pilha *p) {
    int topo;
    if (pilha_topo(p, &topo)) {
        int n = pilha_tamanho(p);
        printf("[%d %s, topo %d]\n", n, n == 1 ? "item" : "itens", topo);
    } else {
        printf("[vazia]\n");
    }
}

int main(void) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return 1;
    }
    int x;

    pilha_empilha(p, 3);
    estado(p);
    pilha_empilha(p, 8);
    estado(p);
    pilha_desempilha(p, &x);
    printf("saiu %d -> ", x);
    estado(p);
    pilha_empilha(p, 5);
    estado(p);
    pilha_empilha(p, 9);
    estado(p);
    while (pilha_desempilha(p, &x)) {
        printf("saiu %d -> ", x);
        estado(p);
    }

    pilha_libera(p);
    return 0;
}
