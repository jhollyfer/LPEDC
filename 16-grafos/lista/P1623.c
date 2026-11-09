// Lista · Módulo 16 · Grafos
// Exercício P1623 · ★★★ · Dijkstra com heap indexado e diminuir-chave
//
// O Dijkstra do Cormen põe TODOS os vértices numa fila de prioridade mínima
// pela chave dist e, a cada relaxamento que melhora dist[v], chama
// DIMINUIR-CHAVE(v). Com heap binário, cada operação custa O(lg V), e o total
// fica O((V + E) lg V).
//
// Para diminuir a chave de v é preciso saber ONDE v está no heap: guarde
// pos[v] (o índice de v no vetor do heap, ou -1 se já saiu) e atualize pos[]
// em toda troca.
//
// Escreva esse Dijkstra com lista de adjacência (malloc) para as estradas
// da região de Manaus (km, mão dupla, no esqueleto), saindo de Manaus. Mostre
// a ordem em que os vértices saem do heap com a distância, e conte as
// extrações e as chamadas de diminuir-chave.
//
//   Saída esperada:
//   sai Manaus             0 km
//   sai Iranduba          27 km
//   sai Rio Preto da Eva  80 km
//   sai Manacapuru        87 km
//   sai Careiro          100 km
//   sai Pres. Figueiredo 107 km
//   sai Novo Airao       202 km
//   sai Itacoatiara      250 km
//   Extrações: 8 | diminuir-chave: 10
//   Itacoatiara: 250 km, chegando por Rio Preto da Eva
//
// Dicas:
// 1. O heap guarda vértices em h[0..tam-1] e compara dist[h[i]]. Pai de i é
//    (i - 1) / 2; filhos 2i + 1 e 2i + 2.
// 2. troca(i, j) troca h[i] com h[j] e acerta pos[h[i]] = i e pos[h[j]] = j.
//    Esquecer o pos[] é o erro clássico: o diminuir-chave sobe o vértice
//    errado.
// 3. diminuir_chave(v): dist[v] já diminuiu; suba a partir de pos[v]
//    enquanto o pai tiver dist maior.
// 4. Ao contrário do heap "preguiçoso" (que empurra cópias), aqui o heap
//    nunca passa de V itens e cada vértice sai uma vez só: V extrações.
// 5. Resposta esperada: 8 extrações e 9 diminuir-chave; Itacoatiara a 250
//    km, por Rio Preto da Eva.
//
// Escreva sua resposta abaixo:

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define V 8

typedef struct Aresta {
    int v, km;
    struct Aresta *prox;
} Aresta;

const char *nomes[V] = {"Manaus", "Iranduba", "Manacapuru", "Novo Airao",
                        "Rio Preto da Eva", "Pres. Figueiredo", "Itacoatiara", "Careiro"};
Aresta *adj[V];

void liga(int a, int b, int km) {
    for (int k = 0; k < 2; k++) {
        Aresta *e = malloc(sizeof *e);
        if (e == NULL) exit(1);
        e->v = k ? a : b;
        e->km = km;
        e->prox = adj[k ? b : a];
        adj[k ? b : a] = e;
    }
}

int main(void) {
    int estradas[][3] = {{0, 1, 27}, {1, 2, 60}, {0, 2, 98}, {2, 3, 115}, {1, 3, 180},
                         {0, 4, 80}, {4, 6, 170}, {0, 6, 270}, {0, 5, 107}, {5, 4, 60},
                         {0, 7, 100}, {7, 6, 190}};
    for (int k = 0; k < 12; k++) liga(estradas[k][0], estradas[k][1], estradas[k][2]);

    for (int u = 0; u < V; u++)
        while (adj[u]) {
            Aresta *e = adj[u];
            adj[u] = e->prox;
            free(e);
        }
    return 0;
}
