// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1710 · ★☆☆ · Adivinhe o preço: o limite da árvore de decisão

#include <stdio.h>

int palpites(int n, int preco) {
    int ini = 1, fim = n, conta = 0;
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        conta++;
        if (meio == preco) break;
        if (preco > meio) ini = meio + 1;
        else fim = meio - 1;
    }
    return conta;
}

int teto_lg(int x) {
    int h = 0;
    for (long p = 1; p < x; p *= 2) h++;
    return h;
}

int main(void) {
    int ns[] = {7, 15, 100, 1000, 1000000};
    printf("      n  pior caso  limite\n");
    for (int k = 0; k < 5; k++) {
        int n = ns[k], pior = 0;
        for (int preco = 1; preco <= n; preco++) {
            int p = palpites(n, preco);
            if (p > pior) pior = p;
        }
        printf("%7d %10d %7d\n", n, pior, teto_lg(n + 1));
    }
    return 0;
}
