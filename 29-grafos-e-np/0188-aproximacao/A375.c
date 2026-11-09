// A375 · Cobertura de vértices: as duas pontas contra o ótimo

#include <stdbool.h>
#include <stdio.h>

#define V 8
#define E 9

// corredores de um galpão (arestas) entre os pontos 0 a 7; um segurança num
// ponto vigia todos os corredores que chegam nele
const int corredor[E][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {1, 6}, {2, 5}};

int main(void) {
    // 2-aproximado: pega uma aresta descoberta e põe as DUAS pontas
    bool aprox[V] = {false};
    int tam_aprox = 0;
    printf("Arestas escolhidas:");
    for (int k = 0; k < E; k++) {
        int a = corredor[k][0], b = corredor[k][1];
        if (aprox[a] || aprox[b]) continue; // já coberta
        printf(" %d-%d", a, b);
        aprox[a] = aprox[b] = true;
        tam_aprox += 2;
    }
    printf("\nAproximado: %d seguranças em", tam_aprox);
    for (int v = 0; v < V; v++)
        if (aprox[v]) printf(" %d", v);

    // ótimo por força bruta: 2^8 subconjuntos
    int melhor = V + 1, mascara_otima = 0;
    for (int m = 0; m < (1 << V); m++) {
        bool cobre = true;
        for (int k = 0; k < E && cobre; k++)
            if (!(m >> corredor[k][0] & 1) && !(m >> corredor[k][1] & 1)) cobre = false;
        int tam = 0;
        for (int v = 0; v < V; v++) tam += m >> v & 1;
        if (cobre && tam < melhor) melhor = tam, mascara_otima = m;
    }
    printf("\nÓtimo: %d seguranças em", melhor);
    for (int v = 0; v < V; v++)
        if (mascara_otima >> v & 1) printf(" %d", v);
    printf("\nRazão: %.2f (a garantia é 2)\n", (double)tam_aprox / melhor);
    return 0;
}
// Saída:
// Arestas escolhidas: 0-1 2-3 4-5 6-7
// Aproximado: 8 seguranças em 0 1 2 3 4 5 6 7
// Ótimo: 4 seguranças em 0 2 4 6
// Razão: 2.00 (a garantia é 2)
//
// Aqui o aproximado bate exatamente no pior caso: as quatro arestas
// escolhidas não têm ponta em comum (formam um emparelhamento), e o ótimo
// precisa de pelo menos uma ponta de cada uma, ou seja, pelo menos 4. O
// aproximado põe as duas pontas: 8 = 2 x 4. Ele nunca passa disso, mas
// também não faz melhor quando o emparelhamento é "perfeito" assim.
// Custo: O(E) contra O(2^V · E) da força bruta.
