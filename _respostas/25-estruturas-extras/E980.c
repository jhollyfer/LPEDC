// 0164 · Listas autoajustáveis
// Exercício E980 · ★☆☆

#include <stdio.h>

int acessa(int v[], int n, int canal) {
    int i = 0;
    while (i < n && v[i] != canal) {
        i++;
    }
    int achado = v[i];
    for (int j = i; j > 0; j--) { // os anteriores andam uma casa para trás
        v[j] = v[j - 1];
    }
    v[0] = achado;
    return i + 1;
}

int main(void) {
    int canais[] = {2, 4, 5, 7, 9, 11, 13};
    int n = 7;
    int acessos[] = {9, 4, 9, 13, 9};

    for (int k = 0; k < 5; k++) {
        int custo = acessa(canais, n, acessos[k]);
        printf("canal %2d (custo %d):", acessos[k], custo);
        for (int i = 0; i < n; i++) {
            printf(" %d", canais[i]);
        }
        printf("\n");
    }
    return 0;
}
