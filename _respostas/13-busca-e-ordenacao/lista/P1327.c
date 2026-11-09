// Lista · Módulo 13 · Busca e ordenação
// Exercício P1327 · ★★★ · O relatório dos três quadráticos

#include <stdio.h>
#include <stdbool.h>

void bubble(int v[], int n, int *comp, int *mov) {
    *comp = *mov = 0;
    for (int p = 1; p < n; p++) {
        bool trocou = false;
        for (int j = 0; j < n - p; j++) {
            (*comp)++;
            if (v[j] > v[j + 1]) {
                int t = v[j];
                v[j] = v[j + 1];
                v[j + 1] = t;
                (*mov)++;
                trocou = true;
            }
        }
        if (!trocou) {
            break;
        }
    }
}

void selection(int v[], int n, int *comp, int *mov) {
    *comp = *mov = 0;
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            (*comp)++;
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        if (menor != i) {
            int t = v[i];
            v[i] = v[menor];
            v[menor] = t;
            (*mov)++;
        }
    }
}

void insertion(int v[], int n, int *comp, int *mov) {
    *comp = *mov = 0;
    for (int j = 1; j < n; j++) {
        int x = v[j];
        int i = j - 1;
        while (i >= 0) {
            (*comp)++;
            if (v[i] <= x) {
                break;
            }
            v[i + 1] = v[i];
            (*mov)++;
            i--;
        }
        v[i + 1] = x;
    }
}

void relatorio(const char *nome, const int orig[], int n) {
    void (*algoritmos[])(int[], int, int *, int *) = {bubble, selection, insertion};
    const char *nomes[] = {"bubble", "selection", "insertion"};
    printf("%s:\n", nome);
    for (int a = 0; a < 3; a++) {
        int v[10], c, m;
        for (int i = 0; i < n; i++) {
            v[i] = orig[i];
        }
        algoritmos[a](v, n, &c, &m);
        printf("  %-9s comparações %2d, movimentos %2d\n", nomes[a], c, m);
    }
}

int main(void) {
    int misturado[] = {5, 2, 8, 1, 9, 3, 7, 4};
    int crescente[] = {1, 2, 3, 4, 5, 7, 8, 9};
    int decrescente[] = {9, 8, 7, 5, 4, 3, 2, 1};

    relatorio("misturado", misturado, 8);
    relatorio("crescente", crescente, 8);
    relatorio("decrescente", decrescente, 8);
    return 0;
}
