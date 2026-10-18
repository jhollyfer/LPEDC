// 0108 · Heapsort
// Exercício E648 · ★★★

#include <stdio.h>
#include <string.h>

// troca só os ponteiros: as letras ficam onde estão
void troca(const char **a, const char **b) {
    const char *t = *a;
    *a = *b;
    *b = t;
}

void desce(const char *v[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && strcmp(v[f + 1], v[f]) > 0) {
            f++;
        }
        if (strcmp(v[i], v[f]) >= 0) {
            break;
        }
        troca(&v[i], &v[f]);
        i = f;
    }
}

void heapsort(const char *v[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        desce(v, n, i);
    }
    for (int fim = n - 1; fim > 0; fim--) {
        troca(&v[0], &v[fim]);
        desce(v, fim, 0);
    }
}

int main(void) {
    const char *nomes[] = {"Paula", "Bruno", "Zeca", "Ana", "Marcos", "Carla", "Igor", "Beatriz"};
    int n = sizeof(nomes) / sizeof(nomes[0]);

    heapsort(nomes, n);
    for (int i = 0; i < n; i++) {
        printf("%s\n", nomes[i]);
    }
    return 0;
}
