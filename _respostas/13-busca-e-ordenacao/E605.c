// 0101 · Comparando: estabilidade, custo e qsort
// Exercício E605 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[16];
    char telefone[16];
} Contato;

// para o qsort: os dois argumentos são Contato *
int compara_contatos(const void *a, const void *b) {
    const Contato *x = a;
    const Contato *y = b;
    return strcmp(x->nome, y->nome);
}

// para o bsearch: o 1º argumento é a CHAVE (aqui, um char *), o 2º é um
// elemento do vetor (Contato *). Tipos diferentes, mesmo critério.
int compara_nome(const void *chave, const void *elemento) {
    const char *nome = chave;
    const Contato *c = elemento;
    return strcmp(nome, c->nome);
}

int main(void) {
    Contato agenda[] = {
        {"Rafael", "81 99876-1234"},
        {"Carla", "11 98765-4321"},
        {"Bruno", "21 97654-3210"},
        {"Marina", "31 96543-2109"},
        {"Diego", "85 95432-1098"},
    };
    size_t n = sizeof agenda / sizeof agenda[0];
    const char *procurados[] = {"Carla", "Zeca"};

    qsort(agenda, n, sizeof agenda[0], compara_contatos);
    for (int k = 0; k < 2; k++) {
        Contato *c = bsearch(procurados[k], agenda, n, sizeof agenda[0], compara_nome);
        if (c != NULL) {
            printf("%s: %s (posição %td)\n", c->nome, c->telefone, c - agenda);
        } else {
            printf("%s: não está na agenda\n", procurados[k]);
        }
    }
    return 0;
}
