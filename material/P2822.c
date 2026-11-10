// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2822 · ★★★ · A remoção que esqueceu de subir
//
// Ache o bug. A cozinha guarda os pedidos numa AVL, e o pedido 30 foi
// entregue. A remoção apaga o nó direitinho, mas a árvore fica torta: o
// fiscal reclama. O erro está no FIM de remove_chave: a volta da recursão só
// recalcula a altura, sem rebalancear. Conserte e rode de novo.
//
//   Saída esperada:
//   pré: 12 6 3 1 4 9 8 10 20 16 14 18 26 25 28
//   altura 3 | rotações na remoção: 3
//   fiscal: AVL ok
//
// Dicas:
// 1. Na remoção, todo ancestral tem que passar pelo mesmo equilibra da
//    inserção, na volta da recursão.
// 2. Aqui, o 28 precisa de uma rotação dupla e, depois dela, a raiz 20
//    precisa de uma simples: 3 rotações.
// 3. Resposta esperada: troque "atualiza(r); return r;" por "return
//    equilibra(r);" no fim de remove_chave. Com a correção, a saída é a de
//    cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave, altura;
    struct No *esq, *dir;
} No;

static int rotacoes = 0;

int alt(const No *r) {
    return r == NULL ? -1 : r->altura;
}

int fator(const No *r) {
    return alt(r->esq) - alt(r->dir);
}

void atualiza(No *r) {
    r->altura = 1 + (alt(r->esq) > alt(r->dir) ? alt(r->esq) : alt(r->dir));
}

No *gira_dir(No *r) {
    No *e = r->esq;
    r->esq = e->dir;
    e->dir = r;
    atualiza(r);
    atualiza(e);
    rotacoes++;
    return e;
}

No *gira_esq(No *r) {
    No *d = r->dir;
    r->dir = d->esq;
    d->esq = r;
    atualiza(r);
    atualiza(d);
    rotacoes++;
    return d;
}

No *equilibra(No *r) {
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

No *insere(No *r, int chave) {
    if (r == NULL) {
        No *n = malloc(sizeof(No));
        if (n == NULL) {
            exit(1);
        }
        n->chave = chave;
        n->altura = 0;
        n->esq = n->dir = NULL;
        return n;
    }
    if (chave < r->chave) {
        r->esq = insere(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = insere(r->dir, chave);
    }
    return equilibra(r);
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

No *remove_chave(No *r, int chave) {
    if (r == NULL) {
        return NULL;
    }
    if (chave < r->chave) {
        r->esq = remove_chave(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = remove_chave(r->dir, chave);
    } else if (r->esq == NULL || r->dir == NULL) {
        No *filho = r->esq != NULL ? r->esq : r->dir;
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
    atualiza(r);
    return r;
}

int fiscal(const No *r) {
    if (r == NULL) {
        return 1;
    }
    int f = alt(r->esq) - alt(r->dir);
    if (f > 1 || f < -1) {
        printf("fiscal: nó %d com fator %d\n", r->chave, f);
        return 0;
    }
    return fiscal(r->esq) && fiscal(r->dir);
}

int main(void) {
    int v[] = {20, 12, 28, 6, 16, 25, 30, 3, 9, 14, 18, 26, 1, 4, 10, 8};
    No *raiz = NULL;
    for (int i = 0; i < 16; i++) {
        raiz = insere(raiz, v[i]);
    }
    int antes = rotacoes;
    raiz = remove_chave(raiz, 30);
    printf("pré:");
    pre(raiz);
    printf("\naltura %d | rotações na remoção: %d\n", alt(raiz), rotacoes - antes);
    if (fiscal(raiz)) {
        printf("fiscal: AVL ok\n");
    }
    libera(raiz);
    return 0;
}
