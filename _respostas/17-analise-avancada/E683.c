// 0114 · Recorrências e árvore de recursão
// Exercício E683 · ★★★

#include <stdio.h>

long chamadas = 0;

// Antes: maior(ini, fim - 1) e maior(ini + 1, fim), dois pedaços de n - 1:
// T(n) = 2 T(n-1) + 1 = 2^n - 1 chamadas.
// Agora: duas metades, T(n) = 2 T(n/2) + 1 = 2n - 1 chamadas.
int maior(const int t[], int ini, int fim) {
    chamadas++;
    if (fim - ini == 1) {
        return t[ini];
    }
    int meio = ini + (fim - ini) / 2;
    int a = maior(t, ini, meio);
    int b = maior(t, meio, fim);
    return a > b ? a : b;
}

int main(void) {
    int temp[30] = {28, 31, 27, 25, 30, 33, 29, 26, 24, 27,
                    32, 35, 30, 28, 26, 25, 29, 31, 34, 30,
                    27, 26, 28, 33, 35, 31, 29, 27, 26, 30};

    int m = maior(temp, 0, 20);
    printf("maior: %d graus, %ld chamadas\n", m, chamadas);

    chamadas = 0;
    m = maior(temp, 0, 30);
    printf("30 dias: maior %d graus, %ld chamadas\n", m, chamadas);
    return 0;
}
