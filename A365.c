// A365 · Euleriano sim, hamiltoniano não

#include <stdbool.h>
#include <stdio.h>

#define V 5

// duas trilhas em triângulo que se cruzam no Mirante (formato de gravata)
const char *pontos[V] = {"Mirante", "Cachoeira", "Gruta", "Lagoa", "Pedra"};
int trilha[V][V];
int rota[V];
bool usado[V];
long chamadas = 0;

bool hamilton(int pos) {
    chamadas++;
    if (pos == V) return trilha[rota[V - 1]][rota[0]];
    for (int v = 1; v < V; v++) {
        if (!trilha[rota[pos - 1]][v] || usado[v]) continue;
        rota[pos] = v;
        usado[v] = true;
        if (hamilton(pos + 1)) return true;
        usado[v] = false;
    }
    return false;
}

int main(void) {
    int trechos[][2] = {{0, 1}, {1, 2}, {2, 0}, {0, 3}, {3, 4}, {4, 0}};
    for (int k = 0; k < 6; k++) trilha[trechos[k][0]][trechos[k][1]] = trilha[trechos[k][1]][trechos[k][0]] = 1;

    int impares = 0;
    for (int u = 0; u < V; u++) {
        int g = 0;
        for (int v = 0; v < V; v++) g += trilha[u][v];
        printf("grau(%s) = %d\n", pontos[u], g);
        if (g % 2) impares++;
    }
    printf("Circuito euleriano: %s\n", impares == 0 ? "sim (todos os graus pares)" : "não");

    rota[0] = 0;
    usado[0] = true;
    printf("Ciclo hamiltoniano: %s\n", hamilton(1) ? "sim" : "não");
    printf("Chamadas até desistir: %ld\n", chamadas);
    return 0;
}
// Saída:
// grau(Mirante) = 4
// grau(Cachoeira) = 2
// grau(Gruta) = 2
// grau(Lagoa) = 2
// grau(Pedra) = 2
// Circuito euleriano: sim (todos os graus pares)
// Ciclo hamiltoniano: não
// Chamadas até desistir: 9
//
// O guia percorre as seis trilhas sem repetir nenhuma (Mirante, Cachoeira,
// Gruta, Mirante, Lagoa, Pedra, Mirante), mas passa duas vezes pelo
// Mirante. Um ciclo hamiltoniano teria de cruzar o Mirante uma vez só, e
// ele é a única ligação entre os dois triângulos: impossível. O Euler
// respondeu com uma conta de graus; o backtracking só respondeu "não"
// depois de esgotar todas as rotas.
