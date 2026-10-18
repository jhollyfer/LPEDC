// 0130 · Juntando tudo
// Exercício E775 · ★☆☆

#include <stdbool.h>
#include <stdio.h>

int grade1[9][9] = {
    {2, 7, 3, 6, 8, 5, 1, 4, 9}, {6, 8, 5, 9, 4, 1, 3, 7, 2}, {9, 4, 1, 2, 7, 3, 5, 8, 6},
    {5, 2, 8, 1, 6, 4, 7, 9, 3}, {3, 9, 7, 5, 2, 8, 4, 6, 1}, {1, 6, 4, 3, 9, 7, 8, 2, 5},
    {8, 3, 2, 4, 5, 6, 9, 1, 7}, {4, 5, 6, 7, 1, 9, 2, 3, 8}, {7, 1, 9, 8, 3, 2, 6, 5, 4},
};
int grade2[9][9] = {
    {2, 7, 3, 6, 8, 5, 1, 4, 9}, {6, 8, 5, 9, 4, 1, 3, 7, 2}, {9, 4, 1, 2, 7, 3, 5, 8, 6},
    {5, 2, 8, 1, 6, 4, 7, 9, 3}, {9, 3, 7, 5, 2, 8, 4, 6, 1}, {1, 6, 4, 3, 9, 7, 8, 2, 5},
    {8, 3, 2, 4, 5, 6, 9, 1, 7}, {4, 5, 6, 7, 1, 9, 2, 3, 8}, {7, 1, 9, 8, 3, 2, 6, 5, 4},
};

// tipo 0: linha k; 1: coluna k; 2: caixa k. Devolve o i-ésimo valor do grupo
int casa(int g[9][9], int tipo, int k, int i) {
    if (tipo == 0) {
        return g[k][i];
    }
    if (tipo == 1) {
        return g[i][k];
    }
    return g[(k / 3) * 3 + i / 3][(k % 3) * 3 + i % 3];
}

bool confere(int g[9][9], char *onde, int *qual) {
    const char tipos[3] = {'L', 'C', 'X'};
    for (int tipo = 0; tipo < 3; tipo++) {
        for (int k = 0; k < 9; k++) {
            bool visto[10] = {false};
            for (int i = 0; i < 9; i++) {
                int d = casa(g, tipo, k, i);
                if (d < 1 || d > 9 || visto[d]) {
                    *onde = tipos[tipo];
                    *qual = k;
                    return false;
                }
                visto[d] = true;
            }
        }
    }
    return true;
}

void testa(int numero, int g[9][9]) {
    char onde;
    int qual;
    if (confere(g, &onde, &qual)) {
        printf("grade %d: certa\n", numero);
    } else {
        const char *nome = onde == 'L' ? "linha" : (onde == 'C' ? "coluna" : "caixa");
        printf("grade %d: errada (%s %d)\n", numero, nome, qual);
    }
}

int main(void) {
    testa(1, grade1);
    testa(2, grade2);
    return 0;
}
