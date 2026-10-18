// 0092 · Selection sort
// Exercício E550 · ★★☆

#include <stdio.h>

// faz só as k primeiras passadas do selection: v[0..k-1] fica com os k menores
int k_menores(int v[], int n, int k) {
    int comparacoes = 0;
    for (int i = 0; i < k; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        int aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
    return comparacoes;
}

int main(void) {
    int passagens[] = {420, 315, 689, 298, 512, 350, 275, 601};
    int n = 8;

    int c = k_menores(passagens, n, 3);
    printf("3 mais baratas: R$ %d, R$ %d, R$ %d\n", passagens[0], passagens[1], passagens[2]);
    printf("%d comparações (ordenar tudo custaria %d)\n", c, n * (n - 1) / 2);
    return 0;
}
