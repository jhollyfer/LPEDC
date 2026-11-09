// Lista · Módulo 25 · Estruturas especiais
// Exercício P2512 · ★★☆ · Amigos em comum
//
// A rede de amizades de oito pessoas é uma matriz de adjacência quase
// toda de zeros, guardada como matriz esparsa: linha[i] é a lista dos
// amigos de i, em ordem de índice. O programa já monta as listas.
// Estenda-o:
// - grau(i): quantos amigos i tem;
// - mostre cada pessoa com o grau e os amigos, e o total de células;
// - em_comum(a, b): os amigos em comum de a e b, andando nas duas listas
//   ao mesmo tempo, como no merge (sem matriz e sem laço dentro de laço).
// Pergunte por Ana e Beto, Caio e Hugo, Duda e Gabi.
//
//   Saída esperada:
//   Ana (3): Beto Caio Edu
//   Beto (4): Ana Caio Duda Edu
//   Caio (4): Ana Beto Edu Fábio
//   Duda (2): Beto Edu
//   Edu (5): Ana Beto Caio Duda Hugo
//   Fábio (2): Caio Hugo
//   Gabi (0):
//   Hugo (2): Edu Fábio
//   Células: 22 de 64
//   Ana e Beto: Caio Edu (2 em comum)
//   Caio e Hugo: Edu Fábio (2 em comum)
//   Duda e Gabi: (0 em comum)
//
// Dicas:
// 1. No merge: se x->col < y->col, avance x; se maior, avance y; se igual,
//    é amigo em comum e os dois avançam.
// 2. A matriz cheia teria 64 casas; as listas guardam só 22 células (cada
//    amizade aparece nas duas listas).
// 3. Resposta esperada: Ana e Beto têm Caio e Edu em comum; Gabi não tem
//    amigo nenhum.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define V 8

typedef struct Celula {
    int col;
    struct Celula *prox;
} Celula;

const char *nomes[V] = {"Ana", "Beto", "Caio", "Duda", "Edu", "Fábio", "Gabi", "Hugo"};
Celula *linha[V]; // linha[i]: os amigos de i, em ordem de índice

void liga_um(int i, int j) {
    Celula **p = &linha[i];
    while (*p != NULL && (*p)->col < j) p = &(*p)->prox;
    Celula *nova = malloc(sizeof(Celula));
    if (nova == NULL) exit(1);
    nova->col = j;
    nova->prox = *p;
    *p = nova;
}

void amizade(int a, int b) {
    liga_um(a, b);
    liga_um(b, a);
}

int main(void) {
    int pares[][2] = {{0, 1}, {0, 2}, {0, 4}, {1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 4}, {4, 7}, {5, 7}, {1, 4}};
    for (int k = 0; k < 11; k++) amizade(pares[k][0], pares[k][1]);

    for (int i = 0; i < V; i++)
        while (linha[i] != NULL) {
            Celula *c = linha[i];
            linha[i] = c->prox;
            free(c);
        }
    return 0;
}
