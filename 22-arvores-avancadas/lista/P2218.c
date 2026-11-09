// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2218 · ★★☆ · Rotações com ponteiro para o pai
//
// No Cormen, cada nó da rubro-negra tem também um ponteiro pai, e as
// rotações precisam acertar seis ponteiros. Complete rot_esq(raiz, x) e
// rot_dir(raiz, y), que giram em torno de x (ou y) e devolvem a raiz da
// árvore toda (que muda se o nó girado era a raiz). O main monta a árvore
// de busca de cima, faz rot_esq no 10, depois rot_dir no 20, e confere
// depois de cada uma que o percurso em ordem não mudou e que todo filho
// aponta de volta para o pai certo.
//
//   10(5, 20(15, 30))
//
//   Saída esperada:
//   Início: raiz 10, em ordem 5 10 15 20 30, pais OK
//   rot_esq(10): raiz 20, em ordem 5 10 15 20 30, pais OK
//   rot_dir(20): raiz 10, em ordem 5 10 15 20 30, pais OK
//
// Dicas:
// 1. rot_esq(x): y = x->dir; x->dir = y->esq (e o pai desse filho vira x,
//    se ele existe); y->pai = x->pai; ligue y no lugar de x (como raiz, ou
//    como filho esquerdo ou direito do pai); y->esq = x; x->pai = y.
// 2. rot_dir é o espelho: troque esq por dir em todo lugar.
// 3. Resposta esperada: depois de rot_esq(10), a raiz é 20; depois de
//    rot_dir(20), volta a ser 10. Em ordem sempre 5 10 15 20 30 e pais OK.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *esq, *dir, *pai;
} No;

No *no(int chave, No *esq, No *dir) {
    No *n = malloc(sizeof *n);
    if (n == NULL) {
        exit(1);
    }
    *n = (No){chave, esq, dir, NULL};
    if (esq != NULL) {
        esq->pai = n;
    }
    if (dir != NULL) {
        dir->pai = n;
    }
    return n;
}

No *rot_esq(No *raiz, No *x) {
    (void)x;
    // COMPLETE AQUI
    return raiz;
}

No *rot_dir(No *raiz, No *y) {
    (void)y;
    // COMPLETE AQUI
    return raiz;
}

void em_ordem(const No *r) {
    if (r != NULL) {
        em_ordem(r->esq);
        printf(" %d", r->chave);
        em_ordem(r->dir);
    }
}

bool pais_ok(const No *r) {
    if (r == NULL) {
        return true;
    }
    if (r->esq != NULL && r->esq->pai != r) {
        return false;
    }
    if (r->dir != NULL && r->dir->pai != r) {
        return false;
    }
    return pais_ok(r->esq) && pais_ok(r->dir);
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

void confere(const char *passo, const No *raiz) {
    printf("%s: raiz %d, em ordem", passo, raiz->chave);
    em_ordem(raiz);
    printf(", pais %s\n", pais_ok(raiz) && raiz->pai == NULL ? "OK" : "errados");
}

int main(void) {
    No *raiz = no(10, no(5, NULL, NULL), no(20, no(15, NULL, NULL), no(30, NULL, NULL)));
    No *n10 = raiz, *n20 = raiz->dir;
    confere("Início", raiz);
    raiz = rot_esq(raiz, n10);
    confere("rot_esq(10)", raiz);
    raiz = rot_dir(raiz, n20);
    confere("rot_dir(20)", raiz);
    libera(raiz);
    return 0;
}
