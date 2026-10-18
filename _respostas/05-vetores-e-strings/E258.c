// 0043 · Vetores e funções
// Exercício E258 · ★★★

#include <stdio.h>

#define FAIXAS 5

void mostrar(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%d" : " %d", v[i]);
    }
    printf("\n");
}

void inverter(int v[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int aux = v[i];
        v[i] = v[n - 1 - i];
        v[n - 1 - i] = aux;
    }
}

void rotacionar(int v[], int n) {
    int primeira = v[0];
    for (int i = 0; i < n - 1; i++) {
        v[i] = v[i + 1];
    }
    v[n - 1] = primeira;
}

int main(void) {
    int playlist[FAIXAS] = {11, 22, 33, 44, 55};

    mostrar(playlist, FAIXAS);
    inverter(playlist, FAIXAS);
    mostrar(playlist, FAIXAS);
    rotacionar(playlist, FAIXAS);
    rotacionar(playlist, FAIXAS);
    mostrar(playlist, FAIXAS);
    return 0;
}
