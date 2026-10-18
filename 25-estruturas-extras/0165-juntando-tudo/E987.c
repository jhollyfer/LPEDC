// 0165 · Juntando tudo
// Exercício E987 · ★★☆
//
// Um quinto concorrente: a tabela hash com encadeamento (assunto 0106).
// Complete as quatro funções do hash com 101 baldes, h(chave) = chave % 101,
// e a chave nova entrando no INÍCIO da lista do balde. O custo de uma busca
// é quantos nós da lista do balde ela comparou (balde vazio custa 0). O
// main já põe o hash no fim da tabela de concorrentes.
//
//   Saída esperada:
//               embaralhada  crescente
//   BST                11.9      569.7
//   AVL                 8.9        9.1
//   skip list          16.4       18.3
//   lista MTF         114.6      114.5
//   hash                6.4        4.7
//
// Dicas:
// 1. A estrutura pode ser typedef struct { NoH *balde[BALDES]; } Hash; com
//    NoH { int chave; struct NoH *prox; }. cria faz o malloc e põe NULL em
//    todos os baldes.
// 2. insere confere se a chave já está no balde antes de criar o nó. libera
//    solta as listas de todos os baldes e depois a struct.
// 3. Resposta esperada: a saída acima. Com 1000 chaves em 101 baldes, cada
//    lista tem umas 10; o hash ganha de todos, mas não guarda a ordem: não
//    serve para "liste do código 200 ao 300".
//
// Escreva sua resposta abaixo (complete as funções do hash):

#include <stdio.h>
#include <stdlib.h>
#include "bancada.h"

#define N 1000
#define BUSCAS 10000
#define QUENTES 20
#define BALDES 101

void *hash_cria(void) {
    return NULL; // troque: aloque e devolva a estrutura vazia
}

void hash_insere(void *e, int chave) {
    (void)e; // apague estas duas linhas
    (void)chave;
}

bool hash_busca(void *e, int chave, int *custo) {
    (void)e; // apague estas duas linhas
    (void)chave;
    *custo = 0;
    return false;
}

void hash_libera(void *e) {
    free(e); // troque: libere tudo o que a estrutura alocou
}

double mede(const Estrutura *e, const int ordem[], const int buscas[]) {
    void *d = e->cria();
    for (int i = 0; i < N; i++) {
        e->insere(d, ordem[i]);
    }
    long total = 0;
    for (int i = 0; i < BUSCAS; i++) {
        int custo;
        e->busca(d, buscas[i], &custo);
        total += custo;
    }
    e->libera(d);
    return (double)total / BUSCAS;
}

int main(void) {
    unsigned estado = 7;
    int crescente[N], embaralhada[N], sorteio[N];
    for (int i = 0; i < N; i++) {
        crescente[i] = embaralhada[i] = sorteio[i] = i + 1;
    }
    bc_embaralha(embaralhada, N, &estado);
    bc_embaralha(sorteio, N, &estado);
    static int buscas[BUSCAS];
    for (int i = 0; i < BUSCAS; i++) {
        if (bc_sorteio(&estado) % 100 < 80) {
            buscas[i] = sorteio[bc_sorteio(&estado) % QUENTES];
        } else {
            buscas[i] = bc_sorteio(&estado) % N + 1;
        }
    }

    // os quatro da bancada e mais o novo, no fim
    Estrutura todos[NUM_CONCORRENTES + 1];
    for (int k = 0; k < NUM_CONCORRENTES; k++) {
        todos[k] = CONCORRENTES[k];
    }
    todos[NUM_CONCORRENTES] = (Estrutura){"hash", hash_cria, hash_insere, hash_busca, hash_libera};

    printf("%-10s %12s %10s\n", "", "embaralhada", "crescente");
    for (int k = 0; k <= NUM_CONCORRENTES; k++) {
        printf("%-10s %12.1f %10.1f\n", todos[k].nome, mede(&todos[k], embaralhada, buscas),
               mede(&todos[k], crescente, buscas));
    }
    return 0;
}
