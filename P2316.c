// Lista · Módulo 23 · Grafos: estrutura e caminhos
// Exercício P2316 · ★★☆ · O Prim preguiçoso e as sobras do heap
//
// A prefeitura vai ligar cinco praças com cabo de Wi-Fi público (metros,
// mão dupla). O heap de mínimo já está pronto: poe(item) e tira(). Escreva
// o laço do Prim preguiçoso a partir da Matriz: o heap guarda arestas
// (peso, de, para); ao tirar uma, se o "para" já está na rede, ela é uma
// SOBRA (o vértice entrou por um caminho mais barato depois que ela foi
// posta) e é descartada. Mostre cada item tirado e pare quando os cinco
// estiverem na rede.
//
//   Saída esperada:
//   tira Matriz-Porto (1): entra Porto
//   tira Porto-Feira (2): entra Feira
//   tira Matriz-Feira (4): descartada, Feira já está na rede
//   tira Feira-Escola (5): entra Escola
//   tira Escola-Ginásio (3): entra Ginásio
//   Total: 11 metros; sobraram 2 itens no heap
//
// Dicas:
// 1. Comece com a Matriz na rede e ponha no heap todas as arestas dela.
// 2. Quando v entra, ponha no heap as arestas de v para quem ainda está
//    fora. Uma mesma praça pode estar no heap várias vezes.
// 3. Resposta esperada: só Matriz-Feira (4) é descartada; total 11 metros
//    e 2 itens ainda no heap no fim (Porto-Escola e Porto-Ginásio).
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define V 5
#define MAXH 32

typedef struct {
    int peso, de, para;
} Item;

const char *pracas[V] = {"Matriz", "Feira", "Porto", "Escola", "Ginásio"};
int metros[V][V];
Item heap[MAXH];
int n_heap = 0;

void troca(int i, int j) {
    Item t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
}

void poe(Item x) {
    int i = n_heap++;
    heap[i] = x;
    while (i > 0 && heap[(i - 1) / 2].peso > heap[i].peso) {
        troca(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

Item tira(void) {
    Item menor = heap[0];
    heap[0] = heap[--n_heap];
    int i = 0;
    for (;;) {
        int e = 2 * i + 1, d = e + 1, m = i;
        if (e < n_heap && heap[e].peso < heap[m].peso) m = e;
        if (d < n_heap && heap[d].peso < heap[m].peso) m = d;
        if (m == i) break;
        troca(i, m);
        i = m;
    }
    return menor;
}

int main(void) {
    int cabos[][3] = {{0, 1, 4}, {0, 2, 1}, {1, 2, 2}, {1, 3, 5}, {2, 3, 8}, {3, 4, 3}, {2, 4, 9}};
    for (int k = 0; k < 7; k++) {
        metros[cabos[k][0]][cabos[k][1]] = cabos[k][2];
        metros[cabos[k][1]][cabos[k][0]] = cabos[k][2];
    }
    // escreva o Prim aqui

    return 0;
}
