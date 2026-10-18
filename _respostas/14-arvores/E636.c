// 0106 · AVL: balanceamento e rotações
// Exercício E636 · ★★★

#include <stdio.h>
#include <stdlib.h>

typedef struct Pedido {
    int num;
    int alt;
    struct Pedido *esq, *dir;
} Pedido;

int alt(const Pedido *p) {
    return p == NULL ? -1 : p->alt;
}

void atualiza(Pedido *p) {
    int he = alt(p->esq), hd = alt(p->dir);
    p->alt = 1 + (he > hd ? he : hd);
}

int fator(const Pedido *p) {
    return alt(p->esq) - alt(p->dir);
}

Pedido *gira_dir(Pedido *r) {
    Pedido *e = r->esq;
    r->esq = e->dir;
    e->dir = r;
    atualiza(r);
    atualiza(e);
    return e;
}

Pedido *gira_esq(Pedido *r) {
    Pedido *d = r->dir;
    r->dir = d->esq;
    d->esq = r;
    atualiza(r);
    atualiza(d);
    return d;
}

// novo é a chave que está sendo inserida (só para a mensagem)
Pedido *insere(Pedido *r, int num, int novo) {
    if (r == NULL) {
        Pedido *p = malloc(sizeof(Pedido));
        if (p == NULL) {
            exit(1);
        }
        p->num = num;
        p->alt = 0;
        p->esq = p->dir = NULL;
        return p;
    }
    if (num < r->num) {
        r->esq = insere(r->esq, num, novo);
    } else if (num > r->num) {
        r->dir = insere(r->dir, num, novo);
    } else {
        return r;
    }
    atualiza(r);
    if (fator(r) > 1) {
        if (fator(r->esq) < 0) {
            printf("Insere %d: esquerda-direita no %d\n", novo, r->num);
            r->esq = gira_esq(r->esq);
        } else {
            printf("Insere %d: esquerda-esquerda no %d\n", novo, r->num);
        }
        return gira_dir(r);
    }
    if (fator(r) < -1) {
        if (fator(r->dir) > 0) {
            printf("Insere %d: direita-esquerda no %d\n", novo, r->num);
            r->dir = gira_dir(r->dir);
        } else {
            printf("Insere %d: direita-direita no %d\n", novo, r->num);
        }
        return gira_esq(r);
    }
    return r;
}

void em_ordem(const Pedido *p) {
    if (p != NULL) {
        em_ordem(p->esq);
        printf(" %d", p->num);
        em_ordem(p->dir);
    }
}

void pre(const Pedido *p) {
    if (p != NULL) {
        printf(" %d", p->num);
        pre(p->esq);
        pre(p->dir);
    }
}

void libera(Pedido *p) {
    if (p != NULL) {
        libera(p->esq);
        libera(p->dir);
        free(p);
    }
}

int main(void) {
    int pedidos[] = {30, 25, 15, 45, 60, 35, 20};
    Pedido *raiz = NULL;
    for (int i = 0; i < 7; i++) {
        raiz = insere(raiz, pedidos[i], pedidos[i]);
    }
    printf("Em ordem:");
    em_ordem(raiz);
    printf("\nPré-ordem:");
    pre(raiz);
    printf("\n");
    libera(raiz);
    return 0;
}
