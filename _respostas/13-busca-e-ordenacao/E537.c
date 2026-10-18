// 0090 · Busca binária
// Exercício E537 · ★★☆

#include <stdio.h>

// primeira posição com v[i] >= x (semiaberto [ini, fim))
int primeira_maior_igual(const int v[], int n, int x) {
    int ini = 0, fim = n;
    while (ini < fim) {
        int meio = ini + (fim - ini) / 2;
        if (v[meio] < x) {
            ini = meio + 1;
        } else {
            fim = meio;
        }
    }
    return ini;
}

// primeira posição com v[i] > x
int primeira_maior(const int v[], int n, int x) {
    int ini = 0, fim = n;
    while (ini < fim) {
        int meio = ini + (fim - ini) / 2;
        if (v[meio] <= x) {
            ini = meio + 1;
        } else {
            fim = meio;
        }
    }
    return ini;
}

int main(void) {
    int notas[] = {1, 1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5};
    int n = 12;

    for (int nota = 1; nota <= 5; nota++) {
        int a = primeira_maior_igual(notas, n, nota);
        int b = primeira_maior(notas, n, nota);
        if (a == b) {
            printf("Nota %d: nenhuma\n", nota);
        } else {
            printf("Nota %d: posições %d a %d, %d %s\n", nota, a, b - 1, b - a,
                   b - a == 1 ? "avaliação" : "avaliações");
        }
    }
    return 0;
}
