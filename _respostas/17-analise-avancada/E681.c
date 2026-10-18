// 0114 · Recorrências e árvore de recursão
// Exercício E681 · ★★☆

#include <stdio.h>

#define MAX_NIVEIS 32

long custo_nivel[MAX_NIVEIS];

// compara cada produto do lote [ini, fim) com todos do lote e divide ao meio
// devolve quantos pares suspeitos (um preço mais que o dobro do outro) achou
long confere_precos(const int preco[], int ini, int fim, int nivel) {
    int n = fim - ini;
    long suspeitos = 0;
    for (int i = ini; i < fim; i++) {
        for (int j = ini; j < fim; j++) {
            custo_nivel[nivel]++;              // uma comparação
            if (preco[i] > 2 * preco[j]) {
                suspeitos++;                   // mais que o dobro de outro
            }
        }
    }
    if (n == 1) {
        return suspeitos;
    }
    int meio = ini + n / 2;
    suspeitos += confere_precos(preco, ini, meio, nivel + 1);
    suspeitos += confere_precos(preco, meio, fim, nivel + 1);
    return suspeitos;
}

long total(const int preco[], int n, int mostrar) {
    for (int k = 0; k < MAX_NIVEIS; k++) {
        custo_nivel[k] = 0;
    }
    confere_precos(preco, 0, n, 0);
    long soma = 0;
    for (int k = 0; k < MAX_NIVEIS && custo_nivel[k] > 0; k++) {
        if (mostrar) {
            printf("nível %d: %ld comparações\n", k, custo_nivel[k]);
        }
        soma += custo_nivel[k];
    }
    return soma;
}

int main(void) {
    int preco[64];
    for (int i = 0; i < 64; i++) {
        preco[i] = 5 + (i * 13) % 40;
    }

    printf("total: %ld\n\n", total(preco, 8, 1));
    printf(" n  T(n)  2n² - n\n");
    for (int n = 16; n <= 64; n *= 2) {
        printf("%2d  %4ld  %4d\n", n, total(preco, n, 0), 2 * n * n - n);
    }
    return 0;
}
