// 0115 · Teorema mestre
// Exercício E687 · ★★☆

#include <stdio.h>

long chamadas = 0;

// olha as duas metades sempre: T(n) = 2 T(n/2) + 1 -> caso 1, Θ(n)
int conta_lento(const int v[], int ini, int fim, int x) {
    chamadas++;
    if (fim - ini == 1) {
        return v[ini] == x;
    }
    int meio = ini + (fim - ini) / 2;
    return conta_lento(v, ini, meio, x) + conta_lento(v, meio, fim, x);
}

// primeira posição com v[i] >= x: T(n) = T(n/2) + 1 -> caso 2, Θ(log n)
int primeira(const int v[], int ini, int fim, int x) {
    chamadas++;
    if (ini == fim) {
        return ini;
    }
    int meio = ini + (fim - ini) / 2;
    if (v[meio] < x) {
        return primeira(v, meio + 1, fim, x);
    }
    return primeira(v, ini, meio, x);
}

int main(void) {
    int notas[1024];
    for (int i = 0; i < 1024; i++) {
        notas[i] = i * 11 / 1024; // notas de 0 a 10, em ordem
    }

    chamadas = 0;
    int qtd = conta_lento(notas, 0, 1024, 7);
    printf("lento:  %d notas 7 em %ld chamadas\n", qtd, chamadas);

    chamadas = 0;
    qtd = primeira(notas, 0, 1024, 8) - primeira(notas, 0, 1024, 7);
    printf("rápido: %d notas 7 em %ld chamadas\n", qtd, chamadas);
    return 0;
}
