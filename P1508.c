// Lista · Módulo 15 · Tabelas hash
// Exercício P1508 · ★☆☆ · Quanto custa procurar na corrente
//
// A secretaria guarda os RAs numa tabela com encadeamento de 5 baldes,
// h(k) = k % 5, inserindo no início da corrente. O main insere 21, 6, 11,
// 33, 18, 40, 16, 3. Complete int busca(No *t[], int k, int *comp), que
// devolve 1 se achou e conta em *comp quantas chaves comparou, e procure 21,
// 16, 33, 40, 26 e 8.
//
//   Saída esperada:
//   21: achou (comparações: 4)
//   16: achou (comparações: 1)
//   33: achou (comparações: 3)
//   40: achou (comparações: 1)
//   26: não achou (comparações: 4)
//   8: não achou (comparações: 3)
//
// Dicas:
// 1. A busca só olha a corrente do balde k % M.
// 2. O balde 1 ficou 16 11 6 21: o 21, primeiro a entrar, é o último da
//    corrente e custa 4. Busca sem sucesso percorre a corrente inteira.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>
#include <stdlib.h>

#define M 5

typedef struct No {
    int chave;
    struct No *prox;
} No;

void insere(No *t[], int k) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    novo->chave = k;
    novo->prox = t[k % M];
    t[k % M] = novo;
}

int busca(No *t[], int k, int *comp) {
    *comp = 0;
    // complete aqui
    (void)t;
    (void)k;
    return 0;
}

void libera(No *t[]) {
    for (int b = 0; b < M; b++) {
        while (t[b] != NULL) {
            No *prox = t[b]->prox;
            free(t[b]);
            t[b] = prox;
        }
    }
}

int main(void) {
    No *t[M] = {NULL};
    int ra[] = {21, 6, 11, 33, 18, 40, 16, 3};
    for (int i = 0; i < 8; i++) {
        insere(t, ra[i]);
    }

    int procura[] = {21, 16, 33, 40, 26, 8};
    for (int i = 0; i < 6; i++) {
        int c;
        int achou = busca(t, procura[i], &c);
        printf("%d: %s (comparações: %d)\n", procura[i], achou ? "achou" : "não achou", c);
    }
    libera(t);
    return 0;
}
