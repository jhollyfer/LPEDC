// 0182 · Caminhos e ciclos
// Exercício E1092 · ★★★

#include <stdio.h>

#define V 5 // 4 cantos + 1 vértice falso
#define MAX 16

const char nome[V] = {'A', 'B', 'C', 'D', 'X'};
int traco[V][V];

int grau(int u) {
    int g = 0;
    for (int v = 0; v < V; v++) g += traco[u][v];
    return g;
}

int main(void) {
    // o quadrado com as duas diagonais: A-B, B-C, C-D, D-A, A-C, B-D
    int tracos[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2}, {1, 3}};
    for (int k = 0; k < 6; k++) traco[tracos[k][0]][tracos[k][1]] = traco[tracos[k][1]][tracos[k][0]] = 1;

    int impar[V], n = 0;
    for (int u = 0; u < 4; u++)
        if (grau(u) % 2 != 0) impar[n++] = u;
    printf("Cantos ímpares: %d -> %d traços\n", n, n / 2);

    // o falso X liga os dois últimos ímpares: eles viram pares
    traco[4][impar[2]] = traco[impar[2]][4] = 1;
    traco[4][impar[3]] = traco[impar[3]][4] = 1;

    int pilha[MAX], topo = 0, ordem[MAX], m = 0;
    pilha[topo++] = impar[0];
    while (topo > 0) {
        int u = pilha[topo - 1], v = 0;
        while (v < V && traco[u][v] == 0) v++;
        if (v < V) {
            traco[u][v] = traco[v][u] = 0;
            pilha[topo++] = v;
        } else {
            ordem[m++] = u;
            topo--;
        }
    }
    // percorre o trajeto e corta onde aparece o X
    int t = 1;
    printf("Traço %d:", t);
    for (int i = m - 1; i >= 0; i--) {
        if (ordem[i] == 4) {
            printf("\nTraço %d:", ++t);
            continue;
        }
        printf(" %c", nome[ordem[i]]);
    }
    printf("\n");
    return 0;
}
