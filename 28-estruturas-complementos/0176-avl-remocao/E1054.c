// 0176 · AVL: remoção
// Exercício E1054 · ★★☆
//
// Este programa traz uma AVL completa, escrita à mão, cuja remoção de nó com
// dois filhos copia o SUCESSOR (o menor da direita), como no TAD. Mude a
// remoção para usar o ANTECESSOR (o maior da subárvore esquerda): copie a
// chave dele para o nó e remova-o da subárvore esquerda. O rebalanceamento
// na volta continua igual. Com a mudança, a saída tem que ser esta:
//
//   Saída esperada:
//   início:  pré 40 20 10 30 25 35 60 50 70
//   tira 40: pré 35 20 10 30 25 60 50 70
//   tira 20: pré 35 25 10 30 60 50 70
//   altura final: 2
//
// Dicas:
// 1. Hoje o código anda r->dir e depois tudo à esquerda. O antecessor é o
//    espelho: r->esq e depois tudo à direita.
// 2. A chamada recursiva também muda de lado: r->esq = remove(r->esq, ...).
// 3. Resposta esperada: a saída acima. Com o sucessor, a raiz depois de
//    tirar o 40 seria o 50.
//
// Escreva sua resposta abaixo (modifique a função remove_chave):

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave, altura;
    struct No *esq, *dir;
} No;

int alt(const No *r) {
    return r == NULL ? -1 : r->altura;
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

No *equilibra(No *r) {
    atualiza(r);
    int fb = alt(r->esq) - alt(r->dir);
    if (fb > 1) {
        if (alt(r->esq->esq) < alt(r->esq->dir)) {
            r->esq = gira_esq(r->esq);
        }
        return gira_dir(r);
    }
    if (fb < -1) {
        if (alt(r->dir->dir) < alt(r->dir->esq)) {
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
        No *s = r->dir; // o sucessor
        while (s->esq != NULL) {
            s = s->esq;
        }
        r->chave = s->chave;
        r->dir = remove_chave(r->dir, s->chave);
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

int main(void) {
    int v[] = {40, 20, 60, 10, 30, 50, 70, 25, 35};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = insere(raiz, v[i]);
    }
    printf("início:  pré");
    pre(raiz);
    raiz = remove_chave(raiz, 40);
    printf("\ntira 40: pré");
    pre(raiz);
    raiz = remove_chave(raiz, 20);
    printf("\ntira 20: pré");
    pre(raiz);
    printf("\naltura final: %d\n", alt(raiz));
    libera(raiz);
    return 0;
}
