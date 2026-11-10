// Lista · Módulo 14 · Árvores
// Exercício P1419 · ★★☆ · O ancestral comum das estações
//
// As estações de uma ferrovia foram guardadas numa BST pelo quilômetro:
// 60, 25, 90, 10, 40, 75, 120, 30, 50, 80. Escreva:
//
//   const No *ancestral(const No *r, int a, int b)
//     o ancestral comum mais baixo de a e b, sem recursão: enquanto a e b
//     estão do mesmo lado de r, desça para esse lado; quando se separam (ou
//     um deles é r), r é a resposta;
//   int profundidade(const No *r, int x)
//     quantas arestas da raiz até x.
//
// A distância (em arestas) entre a e b é prof(a) + prof(b) - 2 · prof(ancestral).
// Mostre para os pares (30, 50), (10, 50), (80, 120), (30, 80) e (25, 30).
//
//   Saída esperada:
//   30 e 50: ancestral 40, distância 2
//   10 e 50: ancestral 25, distância 3
//   80 e 120: ancestral 90, distância 3
//   30 e 80: ancestral 60, distância 6
//   25 e 30: ancestral 25, distância 2
//
// Dicas:
// 1. Se a < r->chave e b < r->chave, os dois estão à esquerda; se os dois são
//    maiores, à direita; senão, r é o ancestral.
// 2. No par (25, 30) o próprio 25 é o ancestral: um nó conta como ancestral
//    de si mesmo.
// 3. Numa árvore qualquer (não BST) isso exige busca nas duas subárvores; a
//    ordem da BST deixa em O(h).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

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

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    int km[] = {60, 25, 90, 10, 40, 75, 120, 30, 50, 80};
    No *raiz = NULL;
    for (int i = 0; i < 10; i++) {
        raiz = insere(raiz, km[i]);
    }

    libera(raiz);
    return 0;
}
