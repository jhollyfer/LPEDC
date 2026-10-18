// A305 · Prim sem heap: fiação dos postes de um loteamento

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define N 7

int main(void) {
    // posição de cada poste, em metros; qualquer poste pode ligar em qualquer outro
    double x[N] = {0, 30, 62, 10, 45, 82, 25};
    double y[N] = {0, 10, 0, 40, 35, 28, 70};

    double chave[N]; // o fio mais curto conhecido que liga o poste à rede
    int pai[N];
    bool na_rede[N] = {false};
    for (int v = 0; v < N; v++) {
        chave[v] = INFINITY; // da math.h: maior que qualquer double
        pai[v] = -1;
    }
    chave[0] = 0; // o transformador fica no poste 0

    double total = 0;
    for (int passo = 0; passo < N; passo++) {
        int u = -1;
        for (int v = 0; v < N; v++) // O(V): procura a menor chave num vetor
            if (!na_rede[v] && (u == -1 || chave[v] < chave[u])) u = v;
        na_rede[u] = true;
        total += chave[u];
        if (pai[u] != -1) printf("poste %d - poste %d: %.1f m\n", pai[u], u, chave[u]);
        for (int v = 0; v < N; v++) {
            if (na_rede[v]) continue;
            double d = hypot(x[u] - x[v], y[u] - y[v]); // distância em linha reta
            if (d < chave[v]) {
                chave[v] = d; // Prim: só o fio, sem somar o caminho até o transformador
                pai[v] = u;
            }
        }
    }
    printf("Fio total: %.1f m\n", total);
    return 0;
}
// Saída:
// poste 0 - poste 1: 31.6 m
// poste 1 - poste 4: 29.2 m
// poste 1 - poste 2: 33.5 m
// poste 2 - poste 5: 34.4 m
// poste 4 - poste 3: 35.4 m
// poste 3 - poste 6: 33.5 m
// Fio total: 197.6 m
//
// Num grafo completo, E é quase V²/2. O heap custaria O(E log V); o vetor,
// O(V²). Aqui o Prim sem heap é o mais rápido, e nem precisa guardar as
// arestas: a distância é calculada na hora.
