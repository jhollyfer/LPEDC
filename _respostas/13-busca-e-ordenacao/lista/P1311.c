// Lista · Módulo 13 · Busca e ordenação
// Exercício P1311 · ★★☆ · O primeiro boleto do dia

#include <stdio.h>

// primeira posição de x num vetor crescente com repetidos (ou -1)
int primeira_binaria(const int v[], int n, int x, int *comp) {
    int ini = 0, fim = n - 1, achou = -1;
    *comp = 0;
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        (*comp)++;
        if (v[meio] == x) {
            achou = meio;   // guarda e continua procurando à esquerda
            fim = meio - 1;
        } else if (v[meio] < x) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return achou;
}

int primeira_sequencial(const int v[], int n, int x, int *comp) {
    *comp = 0;
    for (int i = 0; i < n; i++) {
        (*comp)++;
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int vencimentos[] = {2, 3, 5, 5, 5, 5, 9, 10, 12, 12, 12, 15, 18, 20, 20, 25};
    int n = 16;
    int dias[] = {5, 12, 20, 7};

    for (int k = 0; k < 4; k++) {
        int cb, cs;
        int pb = primeira_binaria(vencimentos, n, dias[k], &cb);
        int ps = primeira_sequencial(vencimentos, n, dias[k], &cs);
        printf("dia %d: binária %d (%d comp.), sequencial %d (%d comp.)\n", dias[k], pb, cb, ps, cs);
    }
    return 0;
}
