// A364 · A casinha sem tirar o lápis do papel

#include <stdio.h>

#define V 5
#define MAX_TRACOS 8

// os cantos da casinha: A e B no chão, C e D no alto das paredes, E no telhado
const char nome[V] = {'A', 'B', 'C', 'D', 'E'};
int traco[V][V];

int grau(int u) {
    int g = 0;
    for (int v = 0; v < V; v++) g += traco[u][v];
    return g;
}

int main(void) {
    // chão, paredes, teto, o X dentro e as duas águas do telhado
    int tracos[][2] = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {0, 3}, {1, 2}, {2, 4}, {3, 4}};
    for (int k = 0; k < MAX_TRACOS; k++) {
        traco[tracos[k][0]][tracos[k][1]] = 1;
        traco[tracos[k][1]][tracos[k][0]] = 1;
    }

    int impares[V], n_impares = 0;
    for (int u = 0; u < V; u++)
        if (grau(u) % 2 != 0) impares[n_impares++] = u;
    printf("Cantos de grau ímpar: %d\n", n_impares);
    if (n_impares != 0 && n_impares != 2) {
        printf("Impossível sem tirar o lápis\n");
        return 0;
    }
    int inicio = n_impares == 2 ? impares[0] : 0; // trajeto aberto: começa num ímpar

    // Hierholzer: o mesmo do texto, agora a partir de um vértice ímpar
    int pilha[MAX_TRACOS + 1], topo = 0, ordem[MAX_TRACOS + 1], n = 0;
    pilha[topo++] = inicio;
    while (topo > 0) {
        int u = pilha[topo - 1], v = 0;
        while (v < V && traco[u][v] == 0) v++;
        if (v < V) {
            traco[u][v] = traco[v][u] = 0;
            pilha[topo++] = v;
        } else {
            ordem[n++] = u;
            topo--;
        }
    }
    printf("Desenho: ");
    for (int i = n - 1; i >= 0; i--) printf("%c%s", nome[ordem[i]], i > 0 ? "-" : "\n");
    printf("Começa em %c e termina em %c\n", nome[ordem[n - 1]], nome[ordem[0]]);
    return 0;
}
// Saída:
// Cantos de grau ímpar: 2
// Desenho: A-B-C-A-D-C-E-D-B
// Começa em A e termina em B
//
// Os dois cantos do chão têm grau 3; os outros, grau par. Por isso o
// desenho é um TRAJETO aberto (nenhum traço repete) que tem de começar num
// canto do chão e terminar no outro. Comece em C e você trava com um traço
// sobrando, por mais que tente.
