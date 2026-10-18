// 0082 · Pilha
// Exercício E491 · ★★★
//
// 3 1 2 4 é impossível: para o 3 sair primeiro, o 1 e o 2 já estão
// empilhados, com o 2 por cima do 1. Então o 2 sempre sai antes do 1.

#include <stdbool.h>
#include <stdio.h>
// Na pasta do assunto basta #include "pilha.h" (o rodar compila o pilha.c
// junto). Aqui a resolução inclui a implementação para compilar sozinha.
#include "../../12-pilhas-e-filas/0082-pilha/pilha.c"

void simula(const char *ops) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return;
    }
    printf("%s:", ops);
    int proximo = 1;
    for (int i = 0; ops[i] != '\0'; i++) {
        if (ops[i] == 'E') {
            pilha_empilha(p, proximo);
            proximo++;
        } else {
            int x;
            if (!pilha_desempilha(p, &x)) {
                printf(" erro: pilha vazia");
                break;
            }
            printf(" %d", x);
        }
    }
    printf("\n");
    pilha_libera(p);
}

// Simula a pilha: para cada número pedido, empilha os que chegam até ele
// ficar no topo. Se ele já foi empilhado e não está no topo, está preso
// embaixo de alguém: impossível.
bool possivel(const int ordem[], int n) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return false;
    }
    int proximo = 1;
    bool ok = true;
    for (int i = 0; i < n && ok; i++) {
        while (proximo <= ordem[i]) {
            pilha_empilha(p, proximo);
            proximo++;
        }
        int topo;
        if (!pilha_desempilha(p, &topo) || topo != ordem[i]) {
            ok = false;
        }
    }
    pilha_libera(p);
    return ok;
}

int main(void) {
    simula("EEDEDDED");
    simula("EEEDDDED");
    simula("EDDE");
    int boa[] = {2, 3, 1, 4};
    int ruim[] = {3, 1, 2, 4};
    printf("2 3 1 4: %s\n", possivel(boa, 4) ? "possível" : "impossível");
    printf("3 1 2 4: %s\n", possivel(ruim, 4) ? "possível" : "impossível");
    return 0;
}
