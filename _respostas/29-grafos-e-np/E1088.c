// 0182 · Caminhos e ciclos
// Exercício E1088 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define V 6

const char letra[V] = {'G', 'P', 'F', 'E', 'I', 'S'};
int rua[V][V];

int indice(char c) {
    for (int i = 0; i < V; i++)
        if (letra[i] == c) return i;
    return -1;
}

const char *classifica(const char *seq) {
    int s[32], n = 0;
    for (int i = 0; seq[i] != '\0'; i++) s[n++] = indice(seq[i]);
    for (int i = 0; i + 1 < n; i++)
        if (!rua[s[i]][s[i + 1]]) return "não é passeio";
    bool fechado = n > 1 && s[0] == s[n - 1];
    bool repete_aresta = false, repete_vertice = false;
    for (int i = 0; i + 1 < n; i++)
        for (int j = i + 1; j + 1 < n; j++) {
            bool mesma = (s[i] == s[j] && s[i + 1] == s[j + 1]) || (s[i] == s[j + 1] && s[i + 1] == s[j]);
            if (mesma) repete_aresta = true;
        }
    int ultimo = fechado ? n - 1 : n; // no fechado, o último é o primeiro de novo
    for (int i = 0; i < ultimo; i++)
        for (int j = i + 1; j < ultimo; j++)
            if (s[i] == s[j]) repete_vertice = true;
    if (repete_aresta) return fechado ? "passeio fechado" : "passeio";
    if (repete_vertice) return fechado ? "circuito" : "trajeto";
    return fechado ? "ciclo" : "caminho";
}

int main(void) {
    int ruas[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {1, 5}, {2, 4}, {2, 5}, {3, 4}};
    for (int k = 0; k < 8; k++) rua[ruas[k][0]][ruas[k][1]] = rua[ruas[k][1]][ruas[k][0]] = 1;

    const char *testes[] = {"GPFG", "GPEIFPS", "GPFPS", "PEIF", "GPFIEPSFG", "GE"};
    for (int t = 0; t < 6; t++) printf("%-9s %s\n", testes[t], classifica(testes[t]));
    return 0;
}
