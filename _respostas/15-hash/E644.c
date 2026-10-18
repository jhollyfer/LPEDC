// 0108 · Juntando tudo: o contador de palavras
// Exercício E644 · ★☆☆
//
// Resposta:
// [0] las:1 sal:2 ovo:1
// [1]
// [2] mel:1
// [3]
// ovo, sal e las somam 340, 320 e 320, todos com resto 0; mel soma 318,
// resto 2. O segundo "sal" acha o nó que já existe e só soma 1. O "las"
// entrou por último no balde 0, por isso aparece na frente.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 4

typedef struct No {
    char palavra[8];
    int vezes;
    struct No *prox;
} No;

unsigned h(const char *s) {
    unsigned soma = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        soma += (unsigned char)s[i];
    }
    return soma % M;
}

void soma(No *baldes[], const char *w) {
    unsigned b = h(w);
    for (No *p = baldes[b]; p != NULL; p = p->prox) {
        if (strcmp(p->palavra, w) == 0) {
            p->vezes++;
            return;
        }
    }
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return;
    }
    snprintf(novo->palavra, sizeof novo->palavra, "%s", w);
    novo->vezes = 1;
    novo->prox = baldes[b];
    baldes[b] = novo;
}

int main(void) {
    No *baldes[M] = {NULL};
    const char *texto[] = {"ovo", "sal", "mel", "las", "sal"};
    for (int i = 0; i < 5; i++) {
        soma(baldes, texto[i]);
    }
    for (int b = 0; b < M; b++) {
        printf("[%d]", b);
        No *p = baldes[b];
        while (p != NULL) {
            printf(" %s:%d", p->palavra, p->vezes);
            No *prox = p->prox;
            free(p);
            p = prox;
        }
        printf("\n");
    }
    return 0;
}
