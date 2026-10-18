// 0165 · Juntando tudo
// Exercício E990 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include "bancada.h"

#define N 1000
#define BUSCAS 10000
#define QUENTES 20
typedef struct NoR {
    int chave;
    struct NoR *esq, *dir;
} NoR;

typedef struct {
    NoR *raiz;
} Raiz;

void *raiz_cria(void) {
    Raiz *a = malloc(sizeof(Raiz));
    if (a == NULL) {
        exit(1);
    }
    a->raiz = NULL;
    return a;
}

// inserção comum de BST, com laço (chaves em ordem fariam uma recursão funda)
void raiz_insere(void *e, int chave) {
    NoR **p = &((Raiz *)e)->raiz;
    while (*p != NULL) {
        if (chave == (*p)->chave) {
            return;
        }
        p = chave < (*p)->chave ? &(*p)->esq : &(*p)->dir;
    }
    *p = malloc(sizeof(NoR));
    if (*p == NULL) {
        exit(1);
    }
    (*p)->chave = chave;
    (*p)->esq = (*p)->dir = NULL;
}

static NoR *rot_direita(NoR *r) {
    NoR *e = r->esq;
    r->esq = e->dir;
    e->dir = r;
    return e;
}

static NoR *rot_esquerda(NoR *r) {
    NoR *d = r->dir;
    r->dir = d->esq;
    d->esq = r;
    return d;
}

// busca e, se achar, sobe o nó uma rotação por nível até a raiz
static NoR *sobe(NoR *r, int chave, int *custo, bool *achou) {
    if (r == NULL) {
        return NULL;
    }
    (*custo)++;
    if (chave == r->chave) {
        *achou = true;
        return r;
    }
    if (chave < r->chave) {
        r->esq = sobe(r->esq, chave, custo, achou);
        if (*achou) {
            r = rot_direita(r); // o achado (agora filho esquerdo) sobe
        }
    } else {
        r->dir = sobe(r->dir, chave, custo, achou);
        if (*achou) {
            r = rot_esquerda(r);
        }
    }
    return r;
}

bool raiz_busca(void *e, int chave, int *custo) {
    Raiz *a = e;
    bool achou = false;
    *custo = 0;
    a->raiz = sobe(a->raiz, chave, custo, &achou);
    return achou;
}

static void libera_nos(NoR *r) {
    if (r != NULL) {
        libera_nos(r->esq);
        libera_nos(r->dir);
        free(r);
    }
}

void raiz_libera(void *e) {
    libera_nos(((Raiz *)e)->raiz);
    free(e);
}

double mede(const Estrutura *e, const int ordem[], const int buscas[]) {
    void *d = e->cria();
    for (int i = 0; i < N; i++) {
        e->insere(d, ordem[i]);
    }
    long total = 0;
    for (int i = 0; i < BUSCAS; i++) {
        int custo;
        e->busca(d, buscas[i], &custo);
        total += custo;
    }
    e->libera(d);
    return (double)total / BUSCAS;
}

int main(void) {
    unsigned estado = 7;
    int crescente[N], embaralhada[N], sorteio[N];
    for (int i = 0; i < N; i++) {
        crescente[i] = embaralhada[i] = sorteio[i] = i + 1;
    }
    bc_embaralha(embaralhada, N, &estado);
    bc_embaralha(sorteio, N, &estado);
    static int buscas[BUSCAS];
    for (int i = 0; i < BUSCAS; i++) {
        if (bc_sorteio(&estado) % 100 < 80) {
            buscas[i] = sorteio[bc_sorteio(&estado) % QUENTES];
        } else {
            buscas[i] = bc_sorteio(&estado) % N + 1;
        }
    }

    Estrutura todos[NUM_CONCORRENTES + 1];
    for (int k = 0; k < NUM_CONCORRENTES; k++) {
        todos[k] = CONCORRENTES[k];
    }
    todos[NUM_CONCORRENTES] = (Estrutura){"para raiz", raiz_cria, raiz_insere, raiz_busca, raiz_libera};

    printf("%-10s %12s %10s\n", "", "embaralhada", "crescente");
    for (int k = 0; k <= NUM_CONCORRENTES; k++) {
        printf("%-10s %12.1f %10.1f\n", todos[k].nome, mede(&todos[k], embaralhada, buscas),
               mede(&todos[k], crescente, buscas));
    }
    return 0;
}
