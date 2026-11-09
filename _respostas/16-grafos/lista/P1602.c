// Lista · Módulo 16 · Grafos
// Exercício P1602 · ★☆☆ · Voos diretos: graus de entrada e de saída

#include <stdio.h>

#define V 6

const char *nomes[V] = {"Manaus", "Belem", "Brasilia", "Sao Paulo", "Recife", "Boa Vista"};
int voos[][2] = {
    {0, 1}, {0, 2}, {0, 5}, {1, 2}, {2, 3}, {2, 4},
    {2, 0}, {3, 2}, {3, 4}, {4, 3}, {5, 0},
};

int main(void) {
    int total = (int)(sizeof voos / sizeof voos[0]);
    int m[V][V] = {0};

    for (int k = 0; k < total; k++) m[voos[k][0]][voos[k][1]] = 1; // só um sentido

    int soma_saida = 0, soma_entrada = 0, hub = 0, entrada_hub = -1;
    for (int i = 0; i < V; i++) {
        int saida = 0, entrada = 0;
        for (int j = 0; j < V; j++) {
            saida += m[i][j];   // linha i: voos que partem de i
            entrada += m[j][i]; // coluna i: voos que chegam em i
        }
        printf("%-10s saída %d  entrada %d\n", nomes[i], saida, entrada);
        soma_saida += saida;
        soma_entrada += entrada;
        if (entrada > entrada_hub) {
            entrada_hub = entrada;
            hub = i;
        }
    }
    printf("Voos: %d | soma das saídas %d | soma das entradas %d\n", total, soma_saida, soma_entrada);
    printf("Hub: %s (%d chegadas)\n", nomes[hub], entrada_hub);

    int pares = 0;
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++)
            if (m[i][j] && m[j][i]) {
                printf("Ida e volta: %s <-> %s\n", nomes[i], nomes[j]);
                pares++;
            }
    printf("Pares com ida e volta: %d\n", pares);
    return 0;
}
