// 0151 · Ordenação topológica
// Exercício E902 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

#define V 8

const char *etapas[V] = {"processador", "cooler", "memória", "placa no gabinete",
                         "fonte", "placa de vídeo", "cabos", "ligar"};
int antes[V][V];

bool valida(const int ordem[]) {
    int pos[V]; // pos[t] = em que posição a etapa t aparece na ordem
    for (int i = 0; i < V; i++) pos[ordem[i]] = i;
    for (int a = 0; a < V; a++)
        for (int b = 0; b < V; b++)
            if (antes[a][b] && pos[a] > pos[b]) {
                printf("inválida (%s veio antes de %s)\n", etapas[b], etapas[a]);
                return false;
            }
    printf("válida\n");
    return true;
}

int main(void) {
    int regras[][2] = {{0, 1}, {0, 3}, {1, 3}, {2, 3}, {3, 5}, {4, 6}, {5, 6}, {3, 6}, {6, 7}};
    for (int k = 0; k < 9; k++) antes[regras[k][0]][regras[k][1]] = 1;

    int joao[V] = {0, 1, 2, 3, 4, 5, 6, 7};
    int lia[V] = {4, 2, 0, 1, 3, 5, 6, 7};
    int rui[V] = {0, 2, 3, 1, 4, 5, 6, 7};
    printf("João: ");
    valida(joao);
    printf("Lia: ");
    valida(lia);
    printf("Rui: ");
    valida(rui);
    return 0;
}
