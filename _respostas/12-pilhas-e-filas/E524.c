// 0088 · Juntando tudo: a calculadora de expressões
// Exercício E524 · ★☆☆

#include <stdio.h>
// Na pasta do assunto basta incluir os .h (o rodar compila o pilha.c e o
// fila.c junto). Aqui a resolução inclui as implementações para compilar
// sozinha.
#include "../../12-pilhas-e-filas/0088-juntando-tudo/fila.c"
#include "../../12-pilhas-e-filas/0088-juntando-tudo/pilha.c"

void inverte(Fila *f) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return;
    }
    int x;
    while (fila_retira(f, &x)) {
        pilha_empilha(p, x);
    }
    while (pilha_desempilha(p, &x)) {
        fila_insere(f, x);
    }
    pilha_libera(p);
}

void mostra(Fila *f) {
    int n = fila_tamanho(f);
    for (int i = 0; i < n; i++) {
        int x;
        fila_retira(f, &x);
        printf(" %d", x);
        fila_insere(f, x);
    }
    printf("\n");
}

int main(void) {
    Fila *f = fila_cria();
    if (f == NULL) {
        return 1;
    }
    for (int s = 10; s <= 40; s += 10) {
        fila_insere(f, s);
    }
    printf("Antes:");
    mostra(f);
    inverte(f);
    printf("Depois:");
    mostra(f);
    fila_libera(f);
    return 0;
}
