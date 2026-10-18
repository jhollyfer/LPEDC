// 0103 · Heapsort
// Exercício E615 · ★★☆
//
// Resposta: os dois vetores são heaps válidos (pai >= filhos em todo lugar).
// A regra não determina um vetor único. O método dos pais faz menos trabalho
// porque as folhas (metade do vetor) nem se mexem: O(n) contra O(n log n).

#include <stdio.h>
#include <stdbool.h>

void troca(int *a, int *b, int *trocas) {
    int t = *a;
    *a = *b;
    *b = t;
    (*trocas)++;
}

void mostra(const char *rotulo, const int v[], int n, int trocas) {
    printf("%s[", rotulo);
    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%d" : " %d", v[i]);
    }
    printf("], %d trocas\n", trocas);
}

// cada v[k] sobe dentro do heap v[0..k]
int por_insercoes(int v[], int n) {
    int trocas = 0;
    for (int k = 1; k < n; k++) {
        int i = k;
        while (i > 0 && v[(i - 1) / 2] < v[i]) {
            troca(&v[(i - 1) / 2], &v[i], &trocas);
            i = (i - 1) / 2;
        }
    }
    return trocas;
}

void desce(int v[], int n, int i, int *trocas) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && v[f + 1] > v[f]) {
            f++;
        }
        if (v[i] >= v[f]) {
            break;
        }
        troca(&v[i], &v[f], trocas);
        i = f;
    }
}

int descendo_pais(int v[], int n) {
    int trocas = 0;
    for (int i = n / 2 - 1; i >= 0; i--) {
        desce(v, n, i, &trocas);
    }
    return trocas;
}

// todo filho é menor ou igual ao pai
bool eh_heap(const int v[], int n) {
    for (int i = 1; i < n; i++) {
        if (v[i] > v[(i - 1) / 2]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int a[] = {52, 18, 73, 40, 91, 25, 66};
    int b[] = {52, 18, 73, 40, 91, 25, 66};

    int ta = por_insercoes(a, 7);
    mostra("Por inserções:    ", a, 7, ta);
    int tb = descendo_pais(b, 7);
    mostra("Descendo os pais: ", b, 7, tb);
    printf("Os dois são heaps? %s\n", eh_heap(a, 7) && eh_heap(b, 7) ? "sim" : "não");
    return 0;
}
