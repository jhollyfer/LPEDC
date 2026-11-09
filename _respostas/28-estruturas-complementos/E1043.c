// 0174 · Lista com sentinela
// Exercício E1043 · ★★★

#include <stdio.h>
#include <stdlib.h>

typedef struct Musica {
    int faixa;
    struct Musica *ant, *prox;
} Musica;

typedef struct {
    Musica nil;
} Playlist;

void inicia(Playlist *L) {
    L->nil.prox = &L->nil;
    L->nil.ant = &L->nil;
}

void insere_inicio(Playlist *L, int faixa) {
    Musica *x = malloc(sizeof(Musica));
    if (x == NULL) {
        exit(1);
    }
    x->faixa = faixa;
    x->prox = L->nil.prox;
    x->ant = &L->nil;
    L->nil.prox->ant = x; // a linha que faltava
    L->nil.prox = x;
}

void mostra(const Playlist *L, int para_frente) {
    printf("[");
    const Musica *x = para_frente ? L->nil.prox : L->nil.ant;
    while (x != &L->nil) {
        printf(" %d", x->faixa);
        x = para_frente ? x->prox : x->ant;
    }
    printf(" ]\n");
}

void libera(Playlist *L) {
    Musica *x = L->nil.prox;
    while (x != &L->nil) {
        Musica *seguinte = x->prox;
        free(x);
        x = seguinte;
    }
}

int main(void) {
    Playlist p;
    inicia(&p);
    insere_inicio(&p, 3);
    insere_inicio(&p, 2);
    insere_inicio(&p, 1);
    printf("frente: ");
    mostra(&p, 1);
    printf("trás:   ");
    mostra(&p, 0);
    libera(&p);
    return 0;
}
