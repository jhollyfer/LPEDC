// 0186 · P e NP
// Exercício E1114 · ★★☆

#include <stdbool.h>
#include <stdio.h>

#define V 6
#define CORES 3

const char *provas[V] = {"Cálculo", "Física", "Química", "Algoritmos", "Inglês", "Desenho"};
const char *turnos[CORES] = {"manhã", "tarde", "noite"};
int conflito[V][V]; // 1 = algum aluno faz as duas provas

bool valida(const int turno[]) {
    for (int a = 0; a < V; a++)
        for (int b = a + 1; b < V; b++)
            if (conflito[a][b] && turno[a] == turno[b]) {
                printf("  conflito: %s e %s de %s\n", provas[a], provas[b], turnos[turno[a]]);
                return false;
            }
    return true;
}

int main(void) {
    int pares[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}, {3, 4}, {0, 4}, {4, 5}, {3, 5}};
    for (int k = 0; k < 9; k++) conflito[pares[k][0]][pares[k][1]] = conflito[pares[k][1]][pares[k][0]] = 1;

    int palpite[V] = {0, 1, 2, 0, 1, 0};
    printf("Palpite da coordenação:\n");
    printf("  %s\n", valida(palpite) ? "válido" : "inválido");

    // força bruta: 3^6 = 729 escalas, contando em base 3
    int turno[V] = {0}, testadas = 0;
    for (int codigo = 0; codigo < 729; codigo++) {
        int resto = codigo;
        for (int p = 0; p < V; p++) turno[p] = resto % 3, resto /= 3;
        testadas++;
        bool ok = true;
        for (int a = 0; a < V && ok; a++)
            for (int b = a + 1; b < V && ok; b++)
                if (conflito[a][b] && turno[a] == turno[b]) ok = false;
        if (ok) {
            printf("Primeira escala válida (tentativa %d):\n", testadas);
            for (int p = 0; p < V; p++) printf("  %s: %s\n", provas[p], turnos[turno[p]]);
            return 0;
        }
    }
    printf("Nenhuma escala com 3 turnos\n");
    return 0;
}
