// 0165 · Juntando tudo
// Exercício E988 · ★★☆
//
// Um quinto concorrente: o vetor ordenado com busca binária (assuntos 0075
// e 0090). Complete as quatro funções: o vetor cresce com realloc (começa
// com 16 posições e dobra quando enche), insere mantém a ordem empurrando
// os maiores uma casa para a direita, e o custo de uma busca é quantas
// vezes a busca binária comparou a chave com v[meio].
//
//   Saída esperada:
//               embaralhada  crescente
//   BST                11.9      569.7
//   AVL                 8.9        9.1
//   skip list          16.4       18.3
//   lista MTF         114.6      114.5
//   vetor               8.7        8.7
//
// Dicas:
// 1. A estrutura: typedef struct { int *v; int n, cap; } Vetor;. Escreva
//    uma função auxiliar que faz a busca binária e devolve a posição da
//    chave ou, se ela não existir, a posição onde ela entraria (o ini do fim
//    do laço). insere e busca usam a mesma auxiliar.
// 2. Na binária, use meio = ini + (fim - ini) / 2 e conte 1 a cada volta.
// 3. Resposta esperada: a saída acima. O vetor empata com a AVL na busca,
//    mas a conta esconde o preço da inserção: cada chave nova empurra, em
//    média, metade do vetor.
//
// Escreva sua resposta abaixo (complete as funções do vetor):

#include <stdio.h>
#include <stdlib.h>
#include "bancada.h"

#define N 1000
#define BUSCAS 10000
#define QUENTES 20

void *vet_cria(void) {
    return NULL; // troque: aloque e devolva a estrutura vazia
}

void vet_insere(void *e, int chave) {
    (void)e; // apague estas duas linhas
    (void)chave;
}

bool vet_busca(void *e, int chave, int *custo) {
    (void)e; // apague estas duas linhas
    (void)chave;
    *custo = 0;
    return false;
}

void vet_libera(void *e) {
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
    todos[NUM_CONCORRENTES] = (Estrutura){"vetor", vet_cria, vet_insere, vet_busca, vet_libera};

    printf("%-10s %12s %10s\n", "", "embaralhada", "crescente");
    for (int k = 0; k <= NUM_CONCORRENTES; k++) {
        printf("%-10s %12.1f %10.1f\n", todos[k].nome, mede(&todos[k], embaralhada, buscas),
               mede(&todos[k], crescente, buscas));
    }
    return 0;
}
