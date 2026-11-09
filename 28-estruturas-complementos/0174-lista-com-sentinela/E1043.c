// 0174 · Lista com sentinela
// Exercício E1043 · ★★★
//
// Ache o bug. A playlist do carro é uma lista dupla circular com sentinela
// escrita à mão. As músicas 3, 2 e 1 entram no começo, e a playlist toca
// para a frente e para trás. Para a frente sai certo; para trás, a lista
// parece vazia. Falta UMA linha em insere_inicio. Conserte e rode de novo.
//
//   Saída esperada:
//   frente: [ 1 2 3 ]
//   trás:   [ 3 2 1 ]
//
// Dicas:
// 1. Inserir x entre a sentinela e o antigo primeiro mexe em QUATRO
//    ponteiros: x->prox, x->ant, nil.prox e o ant do antigo primeiro.
// 2. Com a lista vazia, o "antigo primeiro" é a própria sentinela: a linha
//    que falta é a que acerta o nil.ant na primeira inserção.
// 3. Resposta esperada: falta "L->nil.prox->ant = x;" antes de
//    "L->nil.prox = x;". Com ela, a saída é a de cima.
//
// Escreva sua resposta abaixo (conserte o código):

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
