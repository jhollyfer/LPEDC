// Lista · Módulo 14 · Árvores
// Exercício P1428 · ★★★ · BST comum contra AVL na planilha ordenada

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

// BST comum (o campo alt fica sem uso)
No *insere_bst(No *r, int chave) {
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
        r->esq = insere_bst(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = insere_bst(r->dir, chave);
    }
    return r;
}

No *insere_avl(No *r, int chave) {
    if (r == NULL) {
        return insere_bst(NULL, chave);
    }
    if (chave < r->chave) {
        r->esq = insere_avl(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = insere_avl(r->dir, chave);
    } else {
        return r;
    }
    atualiza(r);
    if (fator(r) > 1) {
        if (fator(r->esq) < 0) {
            r->esq = gira_esq(r->esq);
        }
        return gira_dir(r);
    }
    if (fator(r) < -1) {
        if (fator(r->dir) > 0) {
            r->dir = gira_dir(r->dir);
        }
        return gira_esq(r);
    }
    return r;
}

int altura_real(const No *r) {
    if (r == NULL) {
        return -1;
    }
    int he = altura_real(r->esq), hd = altura_real(r->dir);
    return 1 + (he > hd ? he : hd);
}

int comparacoes(const No *r, int x) {
    int c = 0;
    while (r != NULL) {
        c++;
        if (x == r->chave) {
            break;
        }
        r = (x < r->chave) ? r->esq : r->dir;
    }
    return c;
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    int n = 31;
    No *bst = NULL, *avl = NULL;
    for (int i = 1; i <= n; i++) { // a planilha veio em ordem de matrícula
        bst = insere_bst(bst, i);
        avl = insere_avl(avl, i);
    }

    long total_bst = 0, total_avl = 0;
    int pior_bst = 0, pior_avl = 0;
    for (int i = 1; i <= n; i++) {
        int cb = comparacoes(bst, i), ca = comparacoes(avl, i);
        total_bst += cb;
        total_avl += ca;
        if (cb > pior_bst) {
            pior_bst = cb;
        }
        if (ca > pior_avl) {
            pior_avl = ca;
        }
    }
    printf("BST: altura %d, pior busca %d, total %ld, média %.2f\n", altura_real(bst), pior_bst, total_bst, (double)total_bst / n);
    printf("AVL: altura %d, pior busca %d, total %ld, média %.2f\n", altura_real(avl), pior_avl, total_avl, (double)total_avl / n);
    libera(bst);
    libera(avl);
    return 0;
}
