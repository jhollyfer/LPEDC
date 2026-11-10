// Lista · Módulo 14 · Árvores
// Exercício P1403 · ★☆☆ · Procurando o CEP na BST
//
// A transportadora guarda os prefixos de CEP atendidos numa BST. O main já
// insere 690, 420, 810, 150, 530, 770, 950, 480, 600. Complete:
//
//   const No *busca(const No *r, int chave, int *visitados)
//     busca SEM recursão (um while que desce pela árvore), contando quantos
//     nós olhou;
//   int minimo(const No *r) e int maximo(const No *r)
//     sem recursão: o menor é o nó mais à esquerda; o maior, o mais à direita.
//
//   Saída esperada:
//   600: achou (visitados: 4)
//   950: achou (visitados: 3)
//   690: achou (visitados: 1)
//   500: não achou (visitados: 4)
//   menor: 150, maior: 950
//
// Dicas:
// 1. No while, compare: igual, achou; menor, r = r->esq; maior, r = r->dir.
// 2. O 500 desce 690, 420, 530, 480 e cai num NULL: a busca sem sucesso
//    também custa a altura do caminho.
// 3. No mínimo, ande enquanto r->esq != NULL (a árvore aqui não é vazia).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *esq, *dir;
} No;

No *insere(No *r, int chave) {
    if (r == NULL) {
        No *p = malloc(sizeof(No));
        if (p == NULL) {
            exit(1);
        }
        p->chave = chave;
        p->esq = p->dir = NULL;
        return p;
    }
    if (chave < r->chave) {
        r->esq = insere(r->esq, chave);
    } else if (chave > r->chave) {
        r->dir = insere(r->dir, chave);
    }
    return r;
}

const No *busca(const No *r, int chave, int *visitados) {
    *visitados = 0;
    // complete aqui
    (void)r;
    (void)chave;
    return NULL;
}

int minimo(const No *r) {
    // complete aqui
    (void)r;
    return 0;
}

int maximo(const No *r) {
    // complete aqui
    (void)r;
    return 0;
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    int ceps[] = {690, 420, 810, 150, 530, 770, 950, 480, 600};
    No *raiz = NULL;
    for (int i = 0; i < 9; i++) {
        raiz = insere(raiz, ceps[i]);
    }

    int procurados[] = {600, 950, 690, 500};
    for (int k = 0; k < 4; k++) {
        int vis;
        const No *achou = busca(raiz, procurados[k], &vis);
        printf("%d: %s (visitados: %d)\n", procurados[k], achou ? "achou" : "não achou", vis);
    }
    printf("menor: %d, maior: %d\n", minimo(raiz), maximo(raiz));
    libera(raiz);
    return 0;
}
