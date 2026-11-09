// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2726 · ★★★ · A tabela do campeonato com qsort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[16];
    int pontos;
    int saldo;
} Time;

typedef enum { POR_PONTOS, POR_NOME } Criterio;

int comparar_pontos(const void *a, const void *b) {
    const Time *x = a;
    const Time *y = b;
    if (x->pontos != y->pontos) {
        return y->pontos - x->pontos; // mais pontos primeiro
    }
    return y->saldo - x->saldo;
}

int comparar_nome(const void *a, const void *b) {
    const Time *x = a;
    const Time *y = b;
    return strcmp(x->nome, y->nome);
}

void ordenar(Time v[], int n, Criterio c) {
    int (*cmp)(const void *, const void *) = NULL;
    switch (c) {
    case POR_PONTOS:
        cmp = comparar_pontos;
        break;
    case POR_NOME:
        cmp = comparar_nome;
        break;
    }
    qsort(v, n, sizeof v[0], cmp);
}

void mostrar(const char *rotulo, const Time v[], int n) {
    printf("%s:", rotulo);
    for (int i = 0; i < n; i++) {
        printf("%s %s %d", i ? "," : "", v[i].nome, v[i].pontos);
    }
    printf("\n");
}

int main(void) {
    Time v[] = {{"Remo", 10, 3}, {"Paysandu", 12, 5}, {"Nacional", 10, 6}, {"Fast", 7, -2}};
    ordenar(v, 4, POR_PONTOS);
    mostrar("por pontos", v, 4);
    ordenar(v, 4, POR_NOME);
    mostrar("por nome", v, 4);
    return 0;
}
