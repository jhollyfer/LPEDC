// Lista · Módulo 16 · Grafos
// Exercício P1606 · ★☆☆ · Quem me segue: o grafo transposto
//
// Numa rede social, "u segue v" é uma seta u -> v (grafo dirigido). O
// esqueleto guarda, em lista de adjacência, QUEM CADA PERFIL SEGUE. Para
// mostrar os SEGUIDORES de cada perfil, você precisa do grafo TRANSPOSTO: o
// mesmo grafo com todas as setas invertidas (cada u -> v vira v -> u).
//
// Complete No **transposta(No *lista[]), que cria (com malloc) as listas do
// transposto, e mostre os seguidores de cada perfil em ordem alfabética.
// Libere as duas listas no fim.
//
//   Saída esperada:
//   Ana segue: Beto Cris
//   Beto segue: Cris
//   Cris segue: Ana
//   Dani segue: Ana Cris
//   Enzo segue: Dani
//   Seguidores de Ana: Cris Dani
//   Seguidores de Beto: Ana
//   Seguidores de Cris: Ana Beto Dani
//   Seguidores de Dani: Enzo
//   Seguidores de Enzo: ninguém
//
// Dicas:
// 1. Para cada u e cada nó v da lista de u, insira u na lista de v do
//    transposto. Custo: O(V + E).
// 2. insere() põe no COMEÇO da lista. Se você percorrer u de V - 1 até 0, os
//    seguidores ficam em ordem crescente de índice.
// 3. O vetor de cabeças do transposto também precisa de malloc (ou calloc,
//    que já zera os ponteiros).
// 4. Resposta esperada: a saída acima. Ana tem 2 seguidores; Enzo, nenhum.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

#define V 5

typedef struct No {
    int v;
    struct No *prox;
} No;

const char *nomes[V] = {"Ana", "Beto", "Cris", "Dani", "Enzo"};

void insere(No *lista[], int u, int v) { // v no começo da lista de u
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) exit(1);
    novo->v = v;
    novo->prox = lista[u];
    lista[u] = novo;
}

void libera(No *lista[]) {
    for (int u = 0; u < V; u++)
        while (lista[u]) {
            No *p = lista[u];
            lista[u] = p->prox;
            free(p);
        }
}

No **transposta(No *lista[]) {
    (void)lista; // apague e escreva a função
    return NULL;
}

int main(void) {
    No *segue[V] = {NULL};
    int setas[][2] = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {3, 0}, {3, 2}, {4, 3}};
    for (int k = 6; k >= 0; k--) insere(segue, setas[k][0], setas[k][1]);

    for (int u = 0; u < V; u++) {
        printf("%s segue:", nomes[u]);
        for (No *p = segue[u]; p; p = p->prox) printf(" %s", nomes[p->v]);
        printf("\n");
    }

    libera(segue);
    return 0;
}
