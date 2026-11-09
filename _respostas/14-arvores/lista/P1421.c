// Lista · Módulo 14 · Árvores
// Exercício P1421 · ★★★ · Remoção na AVL

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave, alt;
    struct No *esq, *dir;
} No;

int alt(const No *p) {
    return p == NULL ? -1 : p->alt;
}

void atualiza(No *p) {
    int he = alt(p->esq), hd = alt(p->dir);
    p->alt = 1 + (he > hd ? he : hd);
}

int fator(const No *p) {
    return alt(p->esq) - alt(p->dir);
}

No *gira_dir(No *r) {
    No *e = r->esq;
    r->esq = e->dir;
    e->dir = r;
    atualiza(r);
    atualiza(e);
    return e;
}

No *gira_esq(No *r) {
    No *d = r->dir;
    r->dir = d->esq;
    d->esq = r;
    atualiza(r);
    atualiza(d);
    return d;
}

const char *rotacao = "";

// atualiza a altura e gira se o nó ficou desbalanceado
No *rebalanceia(No *r) {
    atualiza(r);
    if (fator(r) > 1) {
        if (fator(r->esq) < 0) {
            r->esq = gira_esq(r->esq);
            rotacao = "LR";
        } else {
            rotacao = "LL";
        }
        return gira_dir(r);
    }
    if (fator(r) < -1) {
        if (fator(r->dir) > 0) {
            r->dir = gira_dir(r->dir);
            rotacao = "RL";
        } else {
            rotacao = "RR";
        }
        return gira_esq(r);
    }
    return r;
}

No *insere(No *r, int chave) {
    if (r == NULL) {
        No *p = malloc(sizeof(No));
        if (p == NULL) {
            exit(1);
        }
        p->chave = chave;
        p->alt = 0;
        p->esq = p->dir = NULL;
        return p;
    }
    if (chave < r->chave) {
        r->esq = insere(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = insere(r->dir, chave);
    } else {
        return r;
    }
    return rebalanceia(r);
}

No *remove_chave(No *r, int chave) {
    if (r == NULL) {
        return NULL;
    }
    if (chave < r->chave) {
        r->esq = remove_chave(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = remove_chave(r->dir, chave);
    } else if (r->esq == NULL || r->dir == NULL) {
        No *filho = (r->esq != NULL) ? r->esq : r->dir;
        free(r);
        return filho;
    } else {
        No *s = r->dir;
        while (s->esq != NULL) {
            s = s->esq;
        }
        r->chave = s->chave;
        r->dir = remove_chave(r->dir, s->chave);
    }
    return rebalanceia(r); // a diferença para a BST: rebalancear na volta
}

void pre(const No *r) {
    if (r != NULL) {
        printf(" %d", r->chave);
        pre(r->esq);
        pre(r->dir);
    }
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    int entram[] = {40, 20, 60, 10, 30, 50, 70, 5, 25, 35, 45};
    No *raiz = NULL;
    for (int i = 0; i < 11; i++) {
        raiz = insere(raiz, entram[i]);
    }
    printf("início:");
    pre(raiz);
    printf("\n");

    int saem[] = {70, 45, 60, 5};
    for (int k = 0; k < 4; k++) {
        rotacao = "";
        raiz = remove_chave(raiz, saem[k]);
        printf("sem o %d:", saem[k]);
        pre(raiz);
        if (rotacao[0] != '\0') {
            printf("   (rotação %s)", rotacao);
        }
        printf("  altura %d\n", raiz->alt);
    }
    libera(raiz);
    return 0;
}
