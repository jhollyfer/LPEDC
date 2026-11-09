// Lista · Módulo 15 · Tabelas hash
// Exercício P1516 · ★★☆ · Cancelando matrículas na tabela encadeada
//
// A academia guarda as matrículas numa tabela com encadeamento de 5 baldes,
// h(k) = k % 5, inserindo no início. O main insere 101, 206, 311, 416, 122,
// 227, 133. Escreva int remove_chave(No *t[], int k), que tira k da corrente
// e libera o nó (devolve 1) ou devolve 0 se não achar. Remova 311 (meio da
// corrente), 416 (começo), 101 (fim) e 999 (não existe), e libere o resto no
// fim usando a própria remove_chave.
//
//   Saída esperada:
//   início:
//     0:
//     1: 416 311 206 101
//     2: 227 122
//     3: 133
//     4:
//   remove 311: ok
//   remove 416: ok
//   remove 101: ok
//   remove 999: não existe
//   fim:
//     0:
//     1: 206
//     2: 227 122
//     3: 133
//     4:
//
// Dicas:
// 1. Com um ponteiro para ponteiro, No **p = &t[k % M], o começo da corrente
//    não é caso especial: ande com p = &(*p)->prox e, ao achar, faça
//    *p = sai->prox.
// 2. Lembre de free(sai) DEPOIS de religar a corrente.
// 3. Ao contrário do endereçamento aberto, aqui a remoção é de verdade: nada
//    de lápide.
// 4. Resposta esperada: a saída acima, limpa no AddressSanitizer.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define M 5

typedef struct No {
    int matricula;
    struct No *prox;
} No;

void insere(No *t[], int k) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        exit(1);
    }
    novo->matricula = k;
    novo->prox = t[k % M];
    t[k % M] = novo;
}

void mostra(No *t[]) {
    for (int b = 0; b < M; b++) {
        printf("  %d:", b);
        for (No *p = t[b]; p != NULL; p = p->prox) {
            printf(" %d", p->matricula);
        }
        printf("\n");
    }
}

int main(void) {
    No *t[M] = {NULL};
    int entram[] = {101, 206, 311, 416, 122, 227, 133};
    for (int i = 0; i < 7; i++) {
        insere(t, entram[i]);
    }
    printf("início:\n");
    mostra(t);

    // remova 311, 416, 101 e 999 e mostre "fim:"

    // troque esta liberação por uma que use remove_chave
    for (int b = 0; b < M; b++) {
        while (t[b] != NULL) {
            No *prox = t[b]->prox;
            free(t[b]);
            t[b] = prox;
        }
    }
    return 0;
}
