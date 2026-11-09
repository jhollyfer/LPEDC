// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1828 · ★★★ · A entrada que derruba os saltos de Shell

#include <stdio.h>
#include <string.h>

#define MAXN 4096

unsigned semente = 8;
long comparacoes;

int sorteia(int n) {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente >> 16) % (unsigned)n);
}

void shell(int v[], int n, const int saltos[], int ns) { // saltos em ordem decrescente
    for (int s = 0; s < ns; s++) {
        int h = saltos[s];
        for (int i = h; i < n; i++) {
            int x = v[i], j = i;
            while (j - h >= 0) {
                comparacoes++;
                if (v[j - h] <= x) break;
                v[j] = v[j - h];
                j -= h;
            }
            v[j] = x;
        }
    }
}

int monta(int qual, int n, int saltos[]) { // devolve quantos, em ordem decrescente
    int cresc[32], t = 0;
    if (qual == 0)
        for (int h = n / 2; h >= 1; h /= 2) saltos[t++] = h; // Shell já sai decrescente
    else {
        if (qual == 1)
            for (int h = 1; h < n; h = 2 * h + 1) cresc[t++] = h; // Hibbard
        else if (qual == 2)
            for (int h = 1; h <= n / 3 || h == 1; h = 3 * h + 1) cresc[t++] = h; // Knuth
        else
            cresc[t++] = 1; // insertion sort puro
        for (int i = 0; i < t; i++) saltos[i] = cresc[t - 1 - i];
    }
    return t;
}

int main(void) {
    static int ruim[MAXN], sorteado[MAXN], v[MAXN];
    const char *nomes[] = {"Shell", "Hibbard", "Knuth", "insertion"};
    for (int n = 1024; n <= MAXN; n *= 4) {
        for (int i = 0; i < n / 2; i++) {
            ruim[2 * i] = n / 2 + i; // os maiores nas pares
            ruim[2 * i + 1] = i;     // os menores nas ímpares
        }
        for (int i = 0; i < n; i++) sorteado[i] = sorteia(n);
        printf("n = %d (n²/8 = %d)\n", n, n * n / 8);
        printf("  %-10s %10s %10s\n", "", "ruim", "sorteado");
        for (int q = 0; q < 4; q++) {
            int saltos[32], ns = monta(q, n, saltos);
            long c[2];
            for (int e = 0; e < 2; e++) {
                memcpy(v, e ? sorteado : ruim, n * sizeof(int));
                comparacoes = 0;
                shell(v, n, saltos, ns);
                c[e] = comparacoes;
            }
            printf("  %-10s %10ld %10ld\n", nomes[q], c[0], c[1]);
        }
    }
    return 0;
}
