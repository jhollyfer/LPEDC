// Lista · Módulo 13 · Busca e ordenação
// Exercício P1307 · ★☆☆ · Uma partição de Lomuto

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Lomuto: pivô no fim; devolve a posição final do pivô
int particiona(int v[], int p, int r) {
    int pivo = v[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (v[j] <= pivo) {
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i + 1], &v[r]);
    return i + 1;
}

int main(void) {
    int andares[] = {12, 3, 17, 8, 21, 5, 10};
    int n = 7;

    int q = particiona(andares, 0, n - 1);
    printf("depois da partição:");
    for (int k = 0; k < n; k++) {
        printf(" %d", andares[k]);
    }
    printf("\npivô %d na posição %d\n", andares[q], q);
    return 0;
}
