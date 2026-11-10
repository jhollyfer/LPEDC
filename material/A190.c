// A190 · O pior caso: vetor que já chega em ordem

#include <stdio.h>
#include <stdbool.h>

static int comparacoes, profundidade, maior_profundidade;

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

void quick_sort(int v[], int p, int r, bool pivo_do_meio) {
    if (p >= r) {
        return;
    }
    profundidade++;
    if (profundidade > maior_profundidade) {
        maior_profundidade = profundidade;
    }
    if (pivo_do_meio) {
        troca(&v[p + (r - p) / 2], &v[r]); // o do meio vira o pivô
    }
    int j = separa(v, p, r);
    quick_sort(v, p, j - 1, pivo_do_meio);
    quick_sort(v, j + 1, r, pivo_do_meio);
    profundidade--;
}

void testa(const char *nome, bool pivo_do_meio) {
    int v[16];
    for (int i = 0; i < 16; i++) {
        v[i] = (i + 1) * 5;             // 5, 10, ..., 80: já em ordem
    }
    comparacoes = profundidade = maior_profundidade = 0;
    quick_sort(v, 0, 15, pivo_do_meio);
    printf("%-14s %3d comparações, recursão com %2d níveis\n",
           nome, comparacoes, maior_profundidade);
}

int main(void) {
    testa("pivô no fim:", false);
    testa("pivô do meio:", true);
    return 0;
}
// Saída:
// pivô no fim:  120 comparações, recursão com 15 níveis
// pivô do meio:  38 comparações, recursão com  4 níveis
