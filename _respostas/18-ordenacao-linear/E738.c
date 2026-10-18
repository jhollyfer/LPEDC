// 0123 · Quickselect
// Exercício E738 · ★★★

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10001

static long comparacoes;

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int separa(int v[], int p, int r) {
    int pivo = v[r], j = p;
    for (int k = p; k < r; k++) {
        comparacoes++;
        if (v[k] <= pivo) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    return j;
}

// insertion sort em v[ini..fim], contando comparações
void insertion(int v[], int ini, int fim) {
    for (int i = ini + 1; i <= fim; i++) {
        int x = v[i];
        int j = i;
        while (j > ini) {
            comparacoes++;
            if (v[j - 1] <= x) {
                break;
            }
            v[j] = v[j - 1];
            j--;
        }
        v[j] = x;
    }
}

// devolve o valor da posição k (absoluta) de v[p..r]
int seleciona(int v[], int p, int r, int k, bool mediana_das_medianas) {
    while (p < r) {
        if (mediana_das_medianas) {
            // 1) grupos de 5: ordena cada um e leva a mediana para a frente
            int m = p;                          // medianas vão para v[p..m-1]
            for (int g = p; g <= r; g += 5) {
                int fim = g + 4 <= r ? g + 4 : r;
                insertion(v, g, fim);
                troca(&v[m], &v[g + (fim - g) / 2]);
                m++;
            }
            // 2) a mediana das medianas, com a própria seleção (recursão)
            int meio = p + (m - p - 1) / 2;
            seleciona(v, p, m - 1, meio, true);
            // 3) ela vira o pivô: vai para o fim e o separa de sempre resolve
            troca(&v[meio], &v[r]);
        }
        int j = separa(v, p, r);
        if (j == k) {
            return v[j];
        }
        if (k < j) {
            r = j - 1;
        } else {
            p = j + 1;
        }
    }
    return v[p];
}

void testa(const char *nome, bool mm, int tipo) {
    int *v = malloc(N * sizeof(int));
    if (v == NULL) {
        return;
    }
    for (int i = 0; i < N; i++) {
        v[i] = tipo == 0 ? i + 1 : (i * 7919) % N + 1; // em ordem ou embaralhado
    }
    comparacoes = 0;
    int m = seleciona(v, 0, N - 1, N / 2, mm);
    printf("%s mediana %d, %9ld comparações\n", nome, m, comparacoes);
    free(v);
}

int main(void) {
    printf("vetor em ordem:\n");
    testa("  pivô no fim:          ", false, 0);
    testa("  mediana das medianas: ", true, 0);
    printf("vetor embaralhado:\n");
    testa("  pivô no fim:          ", false, 1);
    testa("  mediana das medianas: ", true, 1);
    return 0;
}
