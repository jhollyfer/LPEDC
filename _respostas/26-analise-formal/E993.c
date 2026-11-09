// 0166 · O, Ω e Θ de verdade
// Exercício E993 · ★★☆

#include <stdio.h>
#include <stdbool.h>

int comparacoes = 0;
int menor, maior, total, quantas;

// insertion sort contando cada comparação entre elementos
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

// gera todas as ordens de 1..n (backtracking) e ordena cada uma
void permuta(int perm[], bool usado[], int pos, int n) {
    if (pos == n) {
        int copia[8];
        for (int i = 0; i < n; i++) {
            copia[i] = perm[i];
        }
        comparacoes = 0;
        insercao(copia, n);
        if (comparacoes < menor) menor = comparacoes;
        if (comparacoes > maior) maior = comparacoes;
        total += comparacoes;
        quantas++;
        return;
    }
    for (int k = 1; k <= n; k++) {
        if (!usado[k]) {
            usado[k] = true;
            perm[pos] = k;
            permuta(perm, usado, pos + 1, n);
            usado[k] = false;
        }
    }
}

int main(void) {
    for (int n = 3; n <= 7; n++) {
        int perm[8];
        bool usado[9] = {false};
        menor = 1000;
        maior = 0;
        total = 0;
        quantas = 0;
        permuta(perm, usado, 0, n);
        printf("n = %d: %4d ordens | melhor %d | pior %2d | média %.2f\n",
               n, quantas, menor, maior, (double)total / quantas);
    }
    return 0;
}
