// A300 · Grupos de corrida que se juntam

#include <stdio.h>

#define N 8

const char *nomes[N] = {"Ana", "Beto", "Caio", "Dani", "Eli", "Fabi", "Gil", "Hugo"};
int pai[N], tamanho[N];

// union-find (assunto 0148): cada grupo é uma árvore; a raiz é o representante
int acha(int x) {
    if (pai[x] != x) pai[x] = acha(pai[x]); // compressão de caminho
    return pai[x];
}

int main(void) {
    for (int i = 0; i < N; i++) {
        pai[i] = i;
        tamanho[i] = 1;
    }
    int grupos = N;

    // as amizades chegam pelo aplicativo, uma de cada vez
    int amizades[][2] = {{0, 1}, {2, 3}, {1, 3}, {4, 5}, {0, 2}, {6, 7}, {5, 7}, {3, 6}};
    for (int k = 0; k < 8; k++) {
        int a = amizades[k][0], b = amizades[k][1];
        int ra = acha(a), rb = acha(b);
        printf("%-4s + %-4s: ", nomes[a], nomes[b]);
        if (ra == rb) {
            printf("já estavam no mesmo grupo (fecha um ciclo)\n");
            continue;
        }
        if (tamanho[ra] < tamanho[rb]) { // o menor grupo pendura no maior
            int t = ra;
            ra = rb;
            rb = t;
        }
        pai[rb] = ra;
        tamanho[ra] += tamanho[rb];
        grupos--;
        printf("%d grupo%s (o de %s tem %d)\n", grupos, grupos == 1 ? "" : "s", nomes[ra], tamanho[ra]);
    }
    return 0;
}
// Saída:
// Ana  + Beto: 7 grupos (o de Ana tem 2)
// Caio + Dani: 6 grupos (o de Caio tem 2)
// Beto + Dani: 5 grupos (o de Ana tem 4)
// Eli  + Fabi: 4 grupos (o de Eli tem 2)
// Ana  + Caio: já estavam no mesmo grupo (fecha um ciclo)
// Gil  + Hugo: 3 grupos (o de Gil tem 2)
// Fabi + Hugo: 2 grupos (o de Eli tem 4)
// Dani + Gil : 1 grupo (o de Ana tem 8)
//
// A DFS conta os componentes de um grafo pronto. Quando as arestas chegam
// aos poucos, refazer a DFS a cada amizade custaria O(V + E) cada vez; o
// union-find responde em tempo quase constante.
