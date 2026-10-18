// 0113 · Juntando tudo: o contador de palavras
// Exercício E678 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 11
#define MAX_GRUPOS 16

typedef struct Grupo {
    char assinatura[16]; // as letras da palavra em ordem: "amor" -> "amor", "roma" -> "amor"
    char palavras[8][16];
    int n;
    struct Grupo *prox;
} Grupo;

int compara_letra(const void *a, const void *b) {
    return *(const char *)a - *(const char *)b;
}

unsigned espalha(const char *s) {
    unsigned h = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        h = h * 31 + (unsigned char)s[i];
    }
    return h % M;
}

int main(void) {
    const char *palavras[] = {"amor", "pato", "roma", "sala", "topa", "mora",
                              "alas", "lata", "ramo", "cafe"};
    int total = (int)(sizeof palavras / sizeof palavras[0]);
    Grupo *baldes[M] = {NULL};
    Grupo *ordem[MAX_GRUPOS]; // os grupos na ordem em que apareceram
    int grupos = 0;

    for (int i = 0; i < total; i++) {
        char ass[16];
        snprintf(ass, sizeof ass, "%s", palavras[i]);
        qsort(ass, strlen(ass), 1, compara_letra); // a assinatura

        unsigned b = espalha(ass);
        Grupo *g = baldes[b];
        while (g != NULL && strcmp(g->assinatura, ass) != 0) {
            g = g->prox;
        }
        if (g == NULL) { // assinatura nova: novo grupo
            g = malloc(sizeof *g);
            if (g == NULL || grupos == MAX_GRUPOS) {
                free(g);
                break;
            }
            snprintf(g->assinatura, sizeof g->assinatura, "%s", ass);
            g->n = 0;
            g->prox = baldes[b];
            baldes[b] = g;
            ordem[grupos++] = g;
        }
        if (g->n < 8) {
            snprintf(g->palavras[g->n], sizeof g->palavras[0], "%s", palavras[i]);
            g->n++;
        }
    }

    for (int k = 0; k < grupos; k++) {
        if (ordem[k]->n >= 2) {
            for (int j = 0; j < ordem[k]->n; j++) {
                printf("%s%s", j ? " " : "", ordem[k]->palavras[j]);
            }
            printf("\n");
        }
        free(ordem[k]); // cada grupo está uma vez só em ordem[]
    }
    return 0;
}
