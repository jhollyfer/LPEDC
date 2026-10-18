// 0083 · Pilha encadeada
// Exercício E498 · ★★★

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// Na pasta do assunto basta #include "pilha.h" (o rodar compila o pilha.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0083-pilha-encadeada/pilha.c"

typedef struct {
    Pilha *valores;
    Pilha *minimos; // minimos[i] = menor valor entre valores[0..i]
} PilhaMin;

bool min_cria(PilhaMin *pm) {
    pm->valores = pilha_cria();
    pm->minimos = pilha_cria();
    if (pm->valores == NULL || pm->minimos == NULL) {
        if (pm->valores != NULL) {
            pilha_libera(pm->valores);
        }
        if (pm->minimos != NULL) {
            pilha_libera(pm->minimos);
        }
        return false;
    }
    return true;
}

bool min_empilha(PilhaMin *pm, int valor) {
    int menor;
    if (!pilha_topo(pm->minimos, &menor) || valor < menor) {
        menor = valor; // pilha vazia ou valor novo é o menor de todos
    }
    return pilha_empilha(pm->valores, valor) && pilha_empilha(pm->minimos, menor);
}

bool min_desempilha(PilhaMin *pm, int *valor) {
    int lixo;
    if (!pilha_desempilha(pm->valores, valor)) {
        return false;
    }
    pilha_desempilha(pm->minimos, &lixo);
    return true;
}

bool min_atual(const PilhaMin *pm, int *menor) {
    return pilha_topo(pm->minimos, menor); // O(1)
}

void min_libera(PilhaMin *pm) {
    pilha_libera(pm->valores);
    pilha_libera(pm->minimos);
}

int main(void) {
    PilhaMin pm;
    if (!min_cria(&pm)) {
        return 1;
    }
    int temperaturas[] = {22, 19, 25, 17, 30};
    int menor;
    for (int i = 0; i < 5; i++) {
        min_empilha(&pm, temperaturas[i]);
        min_atual(&pm, &menor);
        printf("empilha %d -> mínimo %d\n", temperaturas[i], menor);
    }
    for (int i = 0; i < 4; i++) {
        int t;
        min_desempilha(&pm, &t);
        min_atual(&pm, &menor);
        printf("desempilha %d -> mínimo %d\n", t, menor);
    }
    min_libera(&pm);
    return 0;
}
