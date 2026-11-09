// Lista · Módulo 15 · Tabelas hash
// Exercício P1512 · ★★☆ · Contando as palavras do trava-língua

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 7

typedef struct No {
    char palavra[16];
    int vezes;
    struct No *prox;
} No;

unsigned long long djb2(const char *s) {
    unsigned long long h = 5381;
    for (; *s != '\0'; s++) {
        h = h * 33 + (unsigned char)*s;
    }
    return h;
}

void conta(No *t[], const char *p) {
    int b = (int)(djb2(p) % M);
    for (No *q = t[b]; q != NULL; q = q->prox) {
        if (strcmp(q->palavra, p) == 0) {
            q->vezes++;
            return;
        }
    }
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    snprintf(novo->palavra, sizeof novo->palavra, "%s", p);
    novo->vezes = 1;
    novo->prox = t[b];
    t[b] = novo;
}

int main(void) {
    const char *frase = "o rato roeu a roupa do rei de roma e o rei riu do rato";
    No *t[M] = {NULL};

    // separa as palavras pelos espaços
    char palavra[16];
    int tam = 0, total = 0;
    for (const char *s = frase;; s++) {
        if (*s == ' ' || *s == '\0') {
            if (tam > 0) {
                palavra[tam] = '\0';
                conta(t, palavra);
                total++;
                tam = 0;
            }
            if (*s == '\0') {
                break;
            }
        } else if (tam < 15) {
            palavra[tam++] = *s;
        }
    }

    int distintas = 0;
    for (int b = 0; b < M; b++) {
        printf("%d:", b);
        for (No *q = t[b]; q != NULL; q = q->prox) {
            printf(" %s=%d", q->palavra, q->vezes);
            distintas++;
        }
        printf("\n");
    }
    printf("%d palavras, %d distintas\n", total, distintas);

    for (int b = 0; b < M; b++) {
        while (t[b] != NULL) {
            No *prox = t[b]->prox;
            free(t[b]);
            t[b] = prox;
        }
    }
    return 0;
}
