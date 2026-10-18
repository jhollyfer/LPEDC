// 0108 · Juntando tudo: o contador de palavras
// Exercício E647 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 5

typedef struct No {
    char palavra[16]; // a cópia, não o endereço do buffer
    int vezes;
    struct No *prox;
} No;

unsigned espalha(const char *s) {
    unsigned h = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        h = h * 31 + (unsigned char)s[i];
    }
    return h % M;
}

void conta(No *baldes[], const char *atual) {
    unsigned b = espalha(atual);
    for (No *p = baldes[b]; p != NULL; p = p->prox) {
        if (strcmp(p->palavra, atual) == 0) {
            p->vezes++;
            return;
        }
    }
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return;
    }
    snprintf(novo->palavra, sizeof novo->palavra, "%s", atual);
    novo->vezes = 1;
    novo->prox = baldes[b];
    baldes[b] = novo;
}

int main(void) {
    const char *frase = "sol e mar e sol e pera e lua";
    No *baldes[M] = {NULL};
    char atual[16]; // reaproveitado a cada palavra
    const char *p = frase;

    while (*p != '\0') {
        int n = 0;
        while (*p != '\0' && *p != ' ') { // copia até o espaço
            if (n < 15) {
                atual[n++] = *p;
            }
            p++;
        }
        atual[n] = '\0';
        if (n > 0) {
            conta(baldes, atual);
        }
        while (*p == ' ') {
            p++;
        }
    }
    int diferentes = 0;
    for (int b = 0; b < M; b++) {
        No *q = baldes[b];
        while (q != NULL) {
            printf("%s: %d\n", q->palavra, q->vezes);
            diferentes++;
            No *prox = q->prox;
            free(q);
            q = prox;
        }
    }
    printf("diferentes: %d\n", diferentes);
    return 0;
}
