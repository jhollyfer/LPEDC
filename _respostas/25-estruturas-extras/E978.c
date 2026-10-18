// 0163 · Skip list
// Exercício E978 · ★★★

#include <stdio.h>
#include <stdlib.h>

#define MAX 12

typedef struct No {
    int chave;
    int andares;
    struct No *prox[]; // membro vetor flexível: o tamanho vem do malloc
} No;

typedef struct {
    No *cabeca;   // não pode ser um No dentro da struct: virou ponteiro
    size_t bytes; // bytes pedidos para os nós (a cabeça não conta)
} Skip;

No *novo_no(int chave, int andares) {
    No *n = malloc(sizeof(No) + andares * sizeof(No *));
    if (n == NULL) {
        exit(1);
    }
    n->chave = chave;
    n->andares = andares;
    for (int k = 0; k < andares; k++) {
        n->prox[k] = NULL;
    }
    return n;
}

void insere(Skip *s, int chave, int andares) {
    No *antes[MAX];
    No *x = s->cabeca;
    for (int k = MAX - 1; k >= 0; k--) {
        while (x->prox[k] != NULL && x->prox[k]->chave < chave) {
            x = x->prox[k];
        }
        antes[k] = x;
    }
    No *novo = novo_no(chave, andares);
    s->bytes += sizeof(No) + andares * sizeof(No *);
    for (int k = 0; k < andares; k++) { // só os andares que o nó tem
        novo->prox[k] = antes[k]->prox[k];
        antes[k]->prox[k] = novo;
    }
}

void mostra(const Skip *s) {
    for (int k = 2; k >= 0; k--) {
        printf("andar %d:", k);
        for (const No *x = s->cabeca->prox[k]; x != NULL; x = x->prox[k]) {
            printf(" %d", x->chave);
        }
        printf("\n");
    }
}

int main(void) {
    Skip s = {.cabeca = novo_no(0, MAX), .bytes = 0};

    int km[] = {5, 12, 18, 23, 31, 40, 47, 56};
    int andares[] = {1, 2, 1, 3, 1, 2, 1, 3};
    for (int i = 0; i < 8; i++) {
        insere(&s, km[i], andares[i]);
    }
    mostra(&s);
    printf("Memória dos nós: %zu bytes\n", s.bytes);

    No *x = s.cabeca->prox[0];
    while (x != NULL) {
        No *prox = x->prox[0];
        free(x);
        x = prox;
    }
    free(s.cabeca);
    return 0;
}
