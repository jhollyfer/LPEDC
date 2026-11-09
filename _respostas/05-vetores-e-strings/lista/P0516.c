// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0516 · ★★☆ · A mediana do tempo de entrega

#include <stdio.h>

void mostrar(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], i < n - 1 ? " " : "\n");
    }
}

void selecao(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int i_menor = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[i_menor]) {
                i_menor = j;
            }
        }
        int aux = v[i];
        v[i] = v[i_menor];
        v[i_menor] = aux;
        printf("Passo %d: ", i + 1);
        mostrar(v, n);
    }
}

int main(void) {
    int tempos[9] = {34, 18, 52, 27, 41, 23, 19, 60, 30};
    int n = 9;
    int soma = 0;

    for (int i = 0; i < n; i++) {
        soma += tempos[i];
    }
    selecao(tempos, n);
    printf("Média: %.2f min\n", soma / (double) n);
    printf("Mediana: %d min\n", tempos[n / 2]);
    return 0;
}
