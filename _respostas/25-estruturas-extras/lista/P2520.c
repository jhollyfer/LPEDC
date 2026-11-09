// Lista · Módulo 25 · Estruturas especiais
// Exercício P2520 · ★★☆ · A playlist que aprende o gosto

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char musica[24];
    int toques;
    struct No *prox;
} No;

No *inicio = NULL;

void poe_no_fim(const char *m) {
    No **p = &inicio;
    while (*p != NULL) p = &(*p)->prox;
    *p = malloc(sizeof(No));
    if (*p == NULL) exit(1);
    strcpy((*p)->musica, m);
    (*p)->toques = 0;
    (*p)->prox = NULL;
}

// contagem: soma 1 e reinsere o nó depois de todos com MAIS OU IGUAL toques
int toca(const char *m) {
    No **p = &inicio;
    int custo = 1;
    while (*p != NULL && strcmp((*p)->musica, m) != 0) {
        p = &(*p)->prox;
        custo++;
    }
    if (*p == NULL) return custo - 1;
    No *x = *p;
    *p = x->prox; // tira da lista
    x->toques++;
    No **q = &inicio;
    while (*q != NULL && (*q)->toques >= x->toques && *q != x) q = &(*q)->prox;
    x->prox = *q; // põe de volta no lugar certo
    *q = x;
    return custo;
}

int main(void) {
    const char *musicas[] = {"Asa Branca", "Garota de Ipanema", "Evidências", "Aquarela", "Tempo Perdido"};
    for (int k = 0; k < 5; k++) poe_no_fim(musicas[k]);
    const char *toques[] = {"Aquarela", "Evidências", "Aquarela", "Tempo Perdido", "Evidências",
                            "Evidências", "Asa Branca", "Aquarela"};
    int total = 0;
    for (int k = 0; k < 8; k++) {
        int c = toca(toques[k]);
        total += c;
        printf("custo %d:", c);
        for (No *x = inicio; x != NULL; x = x->prox) printf(" %s(%d)", x->musica, x->toques);
        printf("\n");
    }
    printf("Custo total: %d\n", total);
    while (inicio != NULL) {
        No *x = inicio;
        inicio = x->prox;
        free(x);
    }
    return 0;
}
