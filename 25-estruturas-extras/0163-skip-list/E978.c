// 0163 · Skip list
// Exercício E978 · ★★★
//
// Refatore. Este programa tem a própria skip list, com o vetor fixo
// prox[MAX] em todo nó, e conta os bytes pedidos ao malloc para os nós. Hoje
// ele mostra:
//
//   andar 2: 23 56
//   andar 1: 12 23 40 56
//   andar 0: 5 12 18 23 31 40 47 56
//   Memória dos nós: 832 bytes
//
// Troque o vetor fixo por um membro vetor flexível (C99): a última linha
// da struct vira struct No *prox[]; e cada nó pede ao malloc só os andares
// que tem. Os andares devem sair iguais; a última linha deve virar:
//
//   Memória dos nós: 176 bytes
//
// Dicas:
// 1. Com prox[] no fim, sizeof(No) não conta o vetor (aqui, 8 bytes). O
//    malloc fica malloc(sizeof(No) + andares * sizeof(No *)), e é esse
//    valor que vai para bytes.
// 2. Uma struct com membro flexível não pode ser campo de outra struct. A
//    cabeça vira um ponteiro (No *cabeca), alocado com MAX andares e todos
//    os prox em NULL. Ela não entra na conta de bytes. Libere a cabeça no
//    fim também.
// 3. Cuidado com o laço que liga o nó novo: com o vetor flexível, só
//    existem prox[0] a prox[andares - 1]; escrever em prox[andares] é estouro
//    (o AddressSanitizer acusa). Resposta esperada: 176 = 8 nós x 8 bytes +
//    14 ponteiros x 8 bytes (os andares somam 14).
//
// Escreva sua resposta abaixo (refatore o código):

#include <stdio.h>
#include <stdlib.h>

#define MAX 12

typedef struct No {
    int chave;
    int andares;
    struct No *prox[MAX];
} No;

typedef struct {
    No cabeca;
    size_t bytes; // bytes pedidos para os nós (a cabeça não conta)
} Skip;

void insere(Skip *s, int chave, int andares) {
    No *antes[MAX];
    No *x = &s->cabeca;
    for (int k = MAX - 1; k >= 0; k--) {
        while (x->prox[k] != NULL && x->prox[k]->chave < chave) {
            x = x->prox[k];
        }
        antes[k] = x;
    }
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    s->bytes += sizeof(No);
    novo->chave = chave;
    novo->andares = andares;
    for (int k = 0; k < MAX; k++) {
        if (k < andares) {
            novo->prox[k] = antes[k]->prox[k];
            antes[k]->prox[k] = novo;
        } else {
            novo->prox[k] = NULL;
        }
    }
}

void mostra(const Skip *s) {
    for (int k = 2; k >= 0; k--) {
        printf("andar %d:", k);
        for (const No *x = s->cabeca.prox[k]; x != NULL; x = x->prox[k]) {
            printf(" %d", x->chave);
        }
        printf("\n");
    }
}

int main(void) {
    Skip s = {.bytes = 0}; // a cabeça começa com todos os prox em NULL
    s.cabeca.andares = MAX;

    int km[] = {5, 12, 18, 23, 31, 40, 47, 56};
    int andares[] = {1, 2, 1, 3, 1, 2, 1, 3};
    for (int i = 0; i < 8; i++) {
        insere(&s, km[i], andares[i]);
    }
    mostra(&s);
    printf("Memória dos nós: %zu bytes\n", s.bytes);

    No *x = s.cabeca.prox[0];
    while (x != NULL) {
        No *prox = x->prox[0];
        free(x);
        x = prox;
    }
    return 0;
}
