// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1017 · ★★☆ · A busca que não acha o último ônibus

#include <stdio.h>

int busca(const int v[], int n, int x) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) { // [ini, fim] fechado: só está vazio quando ini > fim
        int meio = (ini + fim) / 2;
        if (v[meio] == x) {
            return meio;
        }
        if (v[meio] < x) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main(void) {
    int horarios[6] = {5, 12, 20, 33, 41, 58};
    int procurados[4] = {58, 5, 33, 40};
    for (int k = 0; k < 4; k++) {
        int pos = busca(horarios, 6, procurados[k]);
        if (pos >= 0) {
            printf("%d: posição %d\n", procurados[k], pos);
        } else {
            printf("%d: não tem\n", procurados[k]);
        }
    }
    return 0;
}
