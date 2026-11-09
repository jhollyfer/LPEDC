// Lista · Módulo 25 · Estruturas especiais
// Exercício P2519 · ★★☆ · Transpor as triplas sem ordenar

#include <stdio.h>

#define MAXT 32

typedef struct {
    int lin, col, valor;
} Tripla;

void mostra(const char *rotulo, const Tripla t[], int n) {
    printf("%s:", rotulo);
    for (int k = 0; k < n; k++) printf(" (%d,%d,%d)", t[k].lin, t[k].col, t[k].valor);
    printf("\n");
}

// transposição rápida: conta quantas triplas cada coluna tem e calcula
// onde a primeira de cada coluna vai cair; depois uma passada só
void transpoe(const Tripla a[], int n, int colunas, Tripla b[]) {
    int conta[MAXT] = {0}, inicio[MAXT];
    for (int k = 0; k < n; k++) conta[a[k].col]++;
    inicio[0] = 0;
    for (int c = 1; c < colunas; c++) inicio[c] = inicio[c - 1] + conta[c - 1];
    for (int c = 0; c < colunas; c++) printf("coluna %d: %d tripla(s), começa em %d\n", c, conta[c], inicio[c]);
    for (int k = 0; k < n; k++) {
        int pos = inicio[a[k].col]++;
        b[pos] = (Tripla){a[k].col, a[k].lin, a[k].valor};
    }
}

int main(void) {
    // notas[aluno][disciplina], 4 alunos x 5 disciplinas, em ordem de aluno
    Tripla notas[] = {{0, 1, 7}, {0, 3, 9}, {1, 0, 6}, {1, 3, 8}, {1, 4, 5},
                      {2, 1, 10}, {3, 0, 4}, {3, 2, 8}, {3, 4, 9}};
    int n = 9;
    Tripla por_disciplina[MAXT];
    mostra("por aluno", notas, n);
    transpoe(notas, n, 5, por_disciplina);
    mostra("por disciplina", por_disciplina, n);
    return 0;
}
