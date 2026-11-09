// Lista · Módulo 05 · Vetores, matrizes e strings
// Exercício P0514 · ★★☆ · Encaixar na fila preferencial

#include <stdio.h>

int inserir(int v[], int n, int cap, int idade) {
    if (n == cap) {
        return n; // cheia: não cabe
    }
    int i = n - 1;
    while (i >= 0 && v[i] < idade) {
        v[i + 1] = v[i]; // empurra o mais novo uma casa
        i--;
    }
    v[i + 1] = idade;
    return n + 1;
}

void mostrar(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], i < n - 1 ? " " : "\n");
    }
}

int main(void) {
    int idades[10] = {91, 84, 77, 70, 66, 61};
    int n = 6;
    int chegadas[3] = {80, 95, 60};

    for (int k = 0; k < 3; k++) {
        n = inserir(idades, n, 10, chegadas[k]);
        printf("Entrou %d: ", chegadas[k]);
        mostrar(idades, n);
    }
    return 0;
}
