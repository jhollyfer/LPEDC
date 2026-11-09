// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0527 · ★★★ · A lista de chamada em ordem

#include <stdio.h>
#include <string.h>

void ordenar(char v[][20], int n) {
    for (int passada = 0; passada < n - 1; passada++) {
        for (int j = 0; j < n - 1 - passada; j++) {
            if (strcmp(v[j], v[j + 1]) > 0) {
                char aux[20];
                strcpy(aux, v[j]);
                strcpy(v[j], v[j + 1]);
                strcpy(v[j + 1], aux);
            }
        }
    }
}

int buscar(char v[][20], int n, const char nome[]) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        int cmp = strcmp(nome, v[meio]);
        if (cmp == 0) {
            return meio;
        }
        if (cmp < 0) {
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }
    return -1;
}

int main(void) {
    char nomes[7][20] = {"Thiago", "Ana Clara", "Bruno", "Yasmin",
                         "Ana Beatriz", "Davi", "Larissa"};
    char procurados[2][20] = {"Davi", "Carla"};

    ordenar(nomes, 7);
    for (int i = 0; i < 7; i++) {
        printf("%d. %s\n", i + 1, nomes[i]);
    }
    for (int k = 0; k < 2; k++) {
        int pos = buscar(nomes, 7, procurados[k]);
        if (pos >= 0) {
            printf("%s: número %d da chamada\n", procurados[k], pos + 1);
        } else {
            printf("%s: não está na lista\n", procurados[k]);
        }
    }
    return 0;
}
