// Lista · Módulo 14 · Árvores
// Exercício P1429 · ★★★ · O maior caminho da rede de sensores

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int id;
    struct No *esq, *dir;
} No;

No *novo(int id, No *esq, No *dir) {
    No *p = malloc(sizeof(No));
    if (p == NULL) {
        exit(1);
    }
    p->id = id;
    p->esq = esq;
    p->dir = dir;
    return p;
}

// devolve a altura de r e atualiza o maior caminho visto até agora
int altura_e_diametro(const No *r, int *diametro, int *curva) {
    if (r == NULL) {
        return -1;
    }
    int he = altura_e_diametro(r->esq, diametro, curva);
    int hd = altura_e_diametro(r->dir, diametro, curva);
    int passando_aqui = (he + 1) + (hd + 1); // arestas descendo pelos dois lados
    if (passando_aqui > *diametro) {
        *diametro = passando_aqui;
        *curva = r->id;
    }
    return 1 + (he > hd ? he : hd);
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    // a central é o 1; o caminho mais longo NÃO passa por ela
    No *raiz = novo(1,
        novo(2,
            novo(4, novo(8, novo(12, NULL, NULL), NULL), novo(9, NULL, NULL)),
            novo(5, NULL, novo(10, NULL, novo(13, novo(14, NULL, NULL), NULL)))),
        novo(3, NULL, novo(7, NULL, NULL)));

    int diametro = 0, curva = -1;
    int h = altura_e_diametro(raiz, &diametro, &curva);
    printf("altura: %d\n", h);
    printf("maior caminho: %d arestas, fazendo a curva no sensor %d\n", diametro, curva);
    libera(raiz);
    return 0;
}
