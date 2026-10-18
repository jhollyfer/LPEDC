// 0135 · Mochila fracionária
// Exercício E809 · ★★★

#include <stdio.h>

#define N 8

typedef struct {
    const char *carga;
    double peso, valor;
} Frete;

double razao(Frete f) {
    return f.valor / f.peso;
}

void troca(Frete *a, Frete *b) {
    Frete t = *a;
    *a = *b;
    *b = t;
}

// heap de máximo pela razão: o elemento em i desce trocando com o maior filho
void desce(Frete v[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && razao(v[f + 1]) > razao(v[f])) {
            f++;
        }
        if (razao(v[i]) >= razao(v[f])) {
            break;
        }
        troca(&v[i], &v[f]);
        i = f;
    }
}

int main(void) {
    Frete v[N] = {
        {"móveis", 400, 2000},   {"eletrônicos", 150, 4500}, {"roupas", 200, 3000},
        {"cimento", 900, 900},   {"remédios", 50, 2500},     {"livros", 300, 1800},
        {"brinquedos", 250, 2750}, {"areia", 1000, 300},
    };
    int n = N;
    double livre = 700, total = 0;
    int tirados = 0;

    for (int i = n / 2 - 1; i >= 0; i--) {
        desce(v, n, i);                      // monta o heap em O(n)
    }
    while (n > 0 && livre > 0) {
        Frete f = v[0];                      // a maior razão
        v[0] = v[--n];
        desce(v, n, 0);
        tirados++;
        double leva = f.peso <= livre ? f.peso : livre;
        double ganho = f.valor * leva / f.peso;
        printf("%3.0f de %4.0f kg  R$ %7.2f  %s\n", leva, f.peso, ganho, f.carga);
        livre -= leva;
        total += ganho;
    }
    printf("Total: R$ %.2f\n", total);
    printf("Itens tirados do heap: %d de %d\n", tirados, N);
    return 0;
}
