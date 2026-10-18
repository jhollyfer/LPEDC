// 0085 · Lista circular
// Exercício E509 · ★★★

#include <stdio.h>
#include <stdlib.h>

typedef struct processo {
    int id;
    int falta;
    struct processo *prox;
} Processo;

static Processo *chega(Processo *ultimo, int id, int tempo) {
    Processo *novo = malloc(sizeof(Processo));
    if (novo == NULL) exit(1);
    novo->id = id;
    novo->falta = tempo;
    if (ultimo == NULL) {
        novo->prox = novo;
    } else {
        novo->prox = ultimo->prox;
        ultimo->prox = novo;
    }
    return novo;
}

int main(void) {
    const int quantum = 2;
    Processo *ultimo = NULL;
    ultimo = chega(ultimo, 1, 5);
    ultimo = chega(ultimo, 2, 2);
    ultimo = chega(ultimo, 3, 4);

    int relogio = 0;
    while (ultimo != NULL) {
        Processo *p = ultimo->prox; // quem está na frente roda
        int fatia = p->falta < quantum ? p->falta : quantum;
        printf("t=%d..%d: P%d ", relogio, relogio + fatia, p->id);
        relogio += fatia;
        p->falta -= fatia;
        if (p->falta == 0) {
            printf("(terminou)\n");
            if (p == ultimo) ultimo = NULL;   // era o único
            else ultimo->prox = p->prox;      // sai da roda
            free(p);
        } else {
            printf("(falta %d)\n", p->falta);
            ultimo = p;                       // vai para o fim: gira a roda
        }
    }
    return 0;
}
