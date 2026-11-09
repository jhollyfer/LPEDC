// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1811 · ★★☆ · Quatro sequências de saltos no mesmo shell sort

#include <stdio.h>
#include <string.h>

#define MAXN 10000

unsigned semente = 77;
long comparacoes;

int sorteia(void) {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente >> 16) % 3600); // segundos
}

void shell(int v[], int n, const int saltos[], int ns) { // saltos em ordem crescente
    for (int s = ns - 1; s >= 0; s--) {
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

int monta(int qual, int n, int saltos[]) { // devolve quantos saltos (crescentes)
    int ns = 0;
    if (qual == 0) { // Shell: n/2, n/4, ..., 1
        int tmp[32], t = 0;
        for (int h = n / 2; h >= 1; h /= 2) tmp[t++] = h;
        for (int i = t - 1; i >= 0; i--) saltos[ns++] = tmp[i];
    } else if (qual == 1) { // Hibbard
        for (int h = 1; h < n; h = 2 * h + 1) saltos[ns++] = h;
    } else if (qual == 2) { // Knuth
        for (int h = 1; h <= n / 3 || h == 1; h = 3 * h + 1) saltos[ns++] = h;
    } else if (qual == 3) { // Sedgewick
        saltos[ns++] = 1;
        for (int k = 1;; k++) {
            int h = (1 << (2 * k)) + 3 * (1 << (k - 1)) + 1;
            if (h >= n) break;
            saltos[ns++] = h;
        }
    } else { // insertion sort: só o salto 1
        saltos[ns++] = 1;
    }
    return ns;
}

int main(void) {
    static int original[MAXN], v[MAXN];
    for (int i = 0; i < MAXN; i++) original[i] = sorteia();

    const char *nomes[] = {"Shell", "Hibbard", "Knuth", "Sedgewick", "insertion"};
    printf("%-10s %10s %10s\n", "", "n = 1000", "n = 10000");
    int tudo_ok = 1;
    for (int q = 0; q < 5; q++) {
        printf("%-10s", nomes[q]);
        for (int n = 1000; n <= MAXN; n *= 10) {
            int saltos[32];
            int ns = monta(q, n, saltos);
            memcpy(v, original, n * sizeof(int));
            comparacoes = 0;
            shell(v, n, saltos, ns);
            for (int i = 1; i < n; i++)
                if (v[i - 1] > v[i]) tudo_ok = 0;
            printf(" %10ld", comparacoes);
        }
        printf("\n");
    }
    printf("Todos ordenados: %s\n", tudo_ok ? "sim" : "não");
    return 0;
}
