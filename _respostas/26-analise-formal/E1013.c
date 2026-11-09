// 0169 · Juntando tudo: passos e bytes conferidos
// Exercício E1013 · ★★★

#include <stdio.h>

long comparacoes = 0;

// insertion sort; agora conta cada comparação entre elementos (antes,
// o contador estava no laço de fora e contava só n - 1)
void insercao(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int x = v[i];
        int j = i - 1;
        while (j >= 0) {
            comparacoes++;
            if (v[j] <= x) {
                break;
            }
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

int main(void) {
    static int v[2000];
    for (int n = 500; n <= 2000; n *= 2) {
        for (int i = 0; i < n; i++) {
            v[i] = n - i;                // ao contrário: pior caso
        }
        comparacoes = 0;
        insercao(v, n);
        long formula = (long)n * (n - 1) / 2;
        printf("n = %4d: %7ld comparações, n(n-1)/2 = %7ld, confere: %s\n",
               n, comparacoes, formula, comparacoes == formula ? "sim" : "não");
    }
    return 0;
}
