// 0177 · Rubro-negra clássica
// Exercício E1061 · ★★★
//
// Ache o bug. A central de entregas escreveu a rubro-negra do Cormen à mão,
// com a sentinela nil. Os pacotes 1 a 10 entram em ordem e um fiscal confere
// as propriedades 4 (vermelho não tem filho vermelho) e 5 (mesma quantidade
// de pretos em todo caminho). O fiscal reclama. Falta UMA linha no caso 1
// do conserto (nos dois lados, o do pai à esquerda e o espelho). Conserte e
// rode de novo.
//
//   Saída esperada:
//   pré: 4 2 1 3 6 5 8* 7 9 10*
//   fiscal: as cinco propriedades valem
//
// Dicas:
// 1. No caso 1 (tio vermelho), o avô fica vermelho. E se o pai do avô também
//    for vermelho? O problema subiu dois níveis.
// 2. O while só olha z. Para ele continuar consertando lá em cima, z tem que
//    subir junto.
// 3. Resposta esperada: falta "z = avo;" depois de "avo->cor = VERMELHO;" no
//    caso 1, dos dois lados. Com ela, a saída é a de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

enum { VERMELHO, PRETO };

typedef struct No {
    int chave, cor;
    struct No *esq, *dir, *pai;
} No;

static No nil = {0, PRETO, &nil, &nil, &nil};
static No *raiz = &nil;

void gira_esq(No *x) {
    No *y = x->dir;
    x->dir = y->esq;
    if (y->esq != &nil) {
        y->esq->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == &nil) {
        raiz = y;
    } else if (x == x->pai->esq) {
        x->pai->esq = y;
    } else {
        x->pai->dir = y;
    }
    y->esq = x;
    x->pai = y;
}

void gira_dir(No *x) {
    No *y = x->esq;
    x->esq = y->dir;
    if (y->dir != &nil) {
        y->dir->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == &nil) {
        raiz = y;
    } else if (x == x->pai->dir) {
        x->pai->dir = y;
    } else {
        x->pai->esq = y;
    }
    y->dir = x;
    x->pai = y;
}

void conserta(No *z) {
    while (z->pai->cor == VERMELHO) {
        No *avo = z->pai->pai;
        if (z->pai == avo->esq) {
            No *tio = avo->dir;
            if (tio->cor == VERMELHO) {
                z->pai->cor = PRETO;
                tio->cor = PRETO;
                avo->cor = VERMELHO;
            } else {
                if (z == z->pai->dir) {
                    z = z->pai;
                    gira_esq(z);
                }
                z->pai->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                gira_dir(z->pai->pai);
            }
        } else {
            No *tio = avo->esq;
            if (tio->cor == VERMELHO) {
                z->pai->cor = PRETO;
                tio->cor = PRETO;
                avo->cor = VERMELHO;
            } else {
                if (z == z->pai->esq) {
                    z = z->pai;
                    gira_dir(z);
                }
                z->pai->cor = PRETO;
                z->pai->pai->cor = VERMELHO;
                gira_esq(z->pai->pai);
            }
        }
    }
    raiz->cor = PRETO;
}

void insere(int chave) {
    No *y = &nil, *x = raiz;
    while (x != &nil) {
        y = x;
        x = chave < x->chave ? x->esq : x->dir;
    }
    No *z = malloc(sizeof(No));
    if (z == NULL) {
        exit(1);
    }
    z->chave = chave;
    z->pai = y;
    if (y == &nil) {
        raiz = z;
    } else if (chave < y->chave) {
        y->esq = z;
    } else {
        y->dir = z;
    }
    z->esq = z->dir = &nil;
    z->cor = VERMELHO;
    conserta(z);
}

// pretos de x até a nil (os dois inclusive), ou -1 se uma regra falhar
int fiscal(const No *x) {
    if (x == &nil) {
        return 1;
    }
    if (x->cor == VERMELHO && (x->esq->cor == VERMELHO || x->dir->cor == VERMELHO)) {
        return -1;
    }
    int e = fiscal(x->esq), d = fiscal(x->dir);
    if (e < 0 || d < 0 || e != d) {
        return -1;
    }
    return e + (x->cor == PRETO);
}

void pre(const No *x) {
    if (x != &nil) {
        printf(" %d%s", x->chave, x->cor == VERMELHO ? "*" : "");
        pre(x->esq);
        pre(x->dir);
    }
}

void libera(No *x) {
    if (x != &nil) {
        libera(x->esq);
        libera(x->dir);
        free(x);
    }
}

int main(void) {
    for (int k = 1; k <= 10; k++) {
        insere(k);
    }
    printf("pré:");
    pre(raiz);
    printf("\nfiscal: %s\n", fiscal(raiz) > 0 ? "as cinco propriedades valem" : "propriedade quebrada");
    libera(raiz);
    return 0;
}
