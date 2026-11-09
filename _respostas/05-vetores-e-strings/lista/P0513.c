// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0513 · ★★☆ · Busca binária nos CEPs

#include <stdio.h>

int busca_binaria(const int v[], int n, int x, int passos[1]) {
    int ini = 0;
    int fim = n - 1;
    passos[0] = 0;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        passos[0]++;
        if (v[meio] == x) {
            return meio;
        }
        if (x < v[meio]) {
            fim = meio - 1; // está na metade de baixo
        } else {
            ini = meio + 1; // está na metade de cima
        }
    }
    return -1;
}

int main(void) {
    int ceps[10] = {69005010, 69020030, 69040000, 69050010, 69053000,
                    69057040, 69060000, 69075351, 69083000, 69097290};
    int procurados[3] = {69075351, 69005010, 69099999};

    for (int k = 0; k < 3; k++) {
        int passos[1];
        int pos = busca_binaria(ceps, 10, procurados[k], passos);
        if (pos >= 0) {
            printf("CEP %d: posição %d em %d passos\n", procurados[k], pos, passos[0]);
        } else {
            printf("CEP %d: não atendido (%d passos)\n", procurados[k], passos[0]);
        }
    }
    return 0;
}
