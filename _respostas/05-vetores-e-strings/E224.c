// 0038 · Vetores e funções
// Exercício E224 · ★☆☆

#include <stdio.h>

#define VAGAS 10

void preencher(int v[], int n, int valor) {
    for (int i = 0; i < n; i++) {
        v[i] = valor;
    }
}

void mostrar(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%d" : " %d", v[i]);
    }
    printf("\n");
}

int main(void) {
    int vagas[VAGAS];

    preencher(vagas, VAGAS, 0);
    mostrar(vagas, VAGAS);

    vagas[0] = 1;
    vagas[3] = 1;
    vagas[7] = 1;
    vagas[8] = 1;
    mostrar(vagas, VAGAS);
    return 0;
}
