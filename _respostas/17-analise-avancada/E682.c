// 0114 · Recorrências e árvore de recursão
// Exercício E682 · ★★☆

#include <stdio.h>

long total = 0;

// ordena v[0..n-1]: leva o maior para o fim e ordena o resto
// T(n) = T(n-1) + (n - 1), T(1) = 0
void ordena(int v[], int n) {
    if (n <= 1) {
        return;
    }
    int maior = 0;
    int comparacoes = 0;
    for (int i = 1; i < n; i++) {
        comparacoes++;
        if (v[i] > v[maior]) {
            maior = i;
        }
    }
    int t = v[maior];
    v[maior] = v[n - 1];
    v[n - 1] = t;
    printf("ordena(%d): %d %s\n", n, comparacoes, comparacoes == 1 ? "comparação" : "comparações");
    total += comparacoes;
    ordena(v, n - 1);
}

int main(void) {
    int precos[] = {42, 17, 88, 5, 63, 29, 71, 10};
    int n = 8;
    ordena(precos, n);
    printf("total: %ld = 8 · 7 / 2\n", total);
    for (int i = 0; i < n; i++) {
        printf("%d ", precos[i]);
    }
    printf("\n");
    return 0;
}
