// 0108 · Juntando tudo: o contador de palavras
// Exercício E645 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define M 13

typedef struct No {
    char palavra[32];
    struct No *prox;
} No;

unsigned espalha(const char *s) {
    unsigned h = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        h = h * 31 + (unsigned char)s[i];
    }
    return h % M;
}

// true se a palavra já estava; senão guarda e devolve false
bool viu_antes(No *baldes[], const char *w) {
    unsigned b = espalha(w);
    for (No *p = baldes[b]; p != NULL; p = p->prox) {
        if (strcmp(p->palavra, w) == 0) {
            return true;
        }
    }
    No *novo = malloc(sizeof *novo);
    if (novo != NULL) {
        snprintf(novo->palavra, sizeof novo->palavra, "%s", w);
        novo->prox = baldes[b];
        baldes[b] = novo;
    }
    return false;
}

void libera(No *baldes[]) {
    for (int b = 0; b < M; b++) {
        while (baldes[b] != NULL) {
            No *prox = baldes[b]->prox;
            free(baldes[b]);
            baldes[b] = prox;
        }
    }
}

int main(void) {
    const char *frase = "Quem parte e reparte fica com a maior parte";
    No *baldes[M] = {NULL};
    char w[32];
    int posicao = 0;
    const char *p = frase;

    while (*p != '\0') {
        while (*p != '\0' && !isalpha((unsigned char)*p)) {
            p++;
        }
        if (*p == '\0') {
            break;
        }
        int n = 0;
        while (isalpha((unsigned char)*p)) {
            if (n < 31) {
                w[n++] = (char)tolower((unsigned char)*p);
            }
            p++;
        }
        w[n] = '\0';
        posicao++;
        if (viu_antes(baldes, w)) {
            printf("primeira repetida: %s (palavra %d)\n", w, posicao);
            break;
        }
    }
    libera(baldes);
    return 0;
}
