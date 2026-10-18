// bancada.c · os quatro concorrentes da bancada de testes
#include <stdio.h>
#include <stdlib.h>
#include "bancada.h"
#include "skip.h"

static void *aloca(size_t bytes) {
    void *p = malloc(bytes);
    if (p == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    return p;
}

int bc_sorteio(unsigned *estado) {
    *estado = *estado * 1103515245u + 12345u;
    return (int)((*estado >> 16) & 0x7fff);
}

void bc_embaralha(int v[], int n, unsigned *estado) {
    for (int i = n - 1; i > 0; i--) {
        int j = (bc_sorteio(estado) * 32768 + bc_sorteio(estado)) % (i + 1);
        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
    }
}

// ---------------------------------------------------------------- árvores
// a BST e a AVL usam o mesmo nó; a BST simplesmente ignora a altura
typedef struct NoArv {
    int chave;
    int altura;
    struct NoArv *esq, *dir;
} NoArv;

typedef struct {
    NoArv *raiz;
} Arvore;

static void *arv_cria(void) {
    Arvore *a = aloca(sizeof(Arvore));
    a->raiz = NULL;
    return a;
}

static NoArv *arv_novo(int chave) {
    NoArv *n = aloca(sizeof(NoArv));
    n->chave = chave;
    n->altura = 0;
    n->esq = n->dir = NULL;
    return n;
}

static bool arv_busca(void *e, int chave, int *custo) {
    const NoArv *r = ((Arvore *)e)->raiz;
    int c = 0;
    while (r != NULL) {
        c++;
        if (chave == r->chave) {
            break;
        }
        r = chave < r->chave ? r->esq : r->dir;
    }
    *custo = c;
    return r != NULL;
}

static void arv_libera_nos(NoArv *r) {
    if (r != NULL) {
        arv_libera_nos(r->esq);
        arv_libera_nos(r->dir);
        free(r);
    }
}

static void arv_libera(void *e) {
    arv_libera_nos(((Arvore *)e)->raiz);
    free(e);
}

// BST: inserção com laço (com chaves em ordem, a recursão desceria 1000 níveis)
static void bst_insere_laco(void *e, int chave) {
    NoArv **p = &((Arvore *)e)->raiz;
    while (*p != NULL) {
        if (chave == (*p)->chave) {
            return;
        }
        p = chave < (*p)->chave ? &(*p)->esq : &(*p)->dir;
    }
    *p = arv_novo(chave);
}

static int alt(const NoArv *r) {
    return r == NULL ? -1 : r->altura;
}

static void atualiza(NoArv *r) {
    int he = alt(r->esq), hd = alt(r->dir);
    r->altura = 1 + (he > hd ? he : hd);
}

static NoArv *rot_dir(NoArv *r) {
    NoArv *e = r->esq;
    r->esq = e->dir;
    e->dir = r;
    atualiza(r);
    atualiza(e);
    return e;
}

static NoArv *rot_esq(NoArv *r) {
    NoArv *d = r->dir;
    r->dir = d->esq;
    d->esq = r;
    atualiza(r);
    atualiza(d);
    return d;
}

static NoArv *avl_ins(NoArv *r, int chave) {
    if (r == NULL) {
        return arv_novo(chave);
    }
    if (chave < r->chave) {
        r->esq = avl_ins(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = avl_ins(r->dir, chave);
    } else {
        return r;
    }
    atualiza(r);
    int fb = alt(r->esq) - alt(r->dir);
    if (fb > 1) {
        if (alt(r->esq->esq) < alt(r->esq->dir)) {
            r->esq = rot_esq(r->esq);
        }
        return rot_dir(r);
    }
    if (fb < -1) {
        if (alt(r->dir->dir) < alt(r->dir->esq)) {
            r->dir = rot_dir(r->dir);
        }
        return rot_esq(r);
    }
    return r;
}

static void avl_insere_raiz(void *e, int chave) {
    Arvore *a = e;
    a->raiz = avl_ins(a->raiz, chave);
}

// ---------------------------------------------------------------- skip list
static void *skip_cria_bc(void) {
    return skip_cria(2024);
}

static void skip_insere_bc(void *e, int chave) {
    skip_insere(e, chave);
}

static bool skip_busca_bc(void *e, int chave, int *custo) {
    return skip_busca(e, chave, custo);
}

static void skip_libera_bc(void *e) {
    skip_libera(e);
}

// ---------------------------------------------------------------- lista MTF
typedef struct NoLista {
    int chave;
    struct NoLista *prox;
} NoLista;

typedef struct {
    NoLista *inicio;
} Lista;

static void *mtf_cria(void) {
    Lista *l = aloca(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

static bool mtf_busca(void *e, int chave, int *custo) {
    Lista *l = e;
    NoLista *ant = NULL, *p = l->inicio;
    int c = 0;
    while (p != NULL) {
        c++;
        if (p->chave == chave) {
            break;
        }
        ant = p;
        p = p->prox;
    }
    *custo = c;
    if (p == NULL) {
        return false;
    }
    if (ant != NULL) { // achou fora da frente: vai para o início
        ant->prox = p->prox;
        p->prox = l->inicio;
        l->inicio = p;
    }
    return true;
}

static void mtf_insere(void *e, int chave) {
    Lista *l = e;
    for (const NoLista *p = l->inicio; p != NULL; p = p->prox) {
        if (p->chave == chave) {
            return;
        }
    }
    NoLista *n = aloca(sizeof(NoLista)); // chave nova entra no fim
    n->chave = chave;
    n->prox = NULL;
    NoLista **fim = &l->inicio;
    while (*fim != NULL) {
        fim = &(*fim)->prox;
    }
    *fim = n;
}

static void mtf_libera(void *e) {
    NoLista *p = ((Lista *)e)->inicio;
    while (p != NULL) {
        NoLista *prox = p->prox;
        free(p);
        p = prox;
    }
    free(e);
}

const Estrutura CONCORRENTES[NUM_CONCORRENTES] = {
    {"BST", arv_cria, bst_insere_laco, arv_busca, arv_libera},
    {"AVL", arv_cria, avl_insere_raiz, arv_busca, arv_libera},
    {"skip list", skip_cria_bc, skip_insere_bc, skip_busca_bc, skip_libera_bc},
    {"lista MTF", mtf_cria, mtf_insere, mtf_busca, mtf_libera},
};
