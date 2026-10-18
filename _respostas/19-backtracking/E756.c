// 0126 · Permutações
// Exercício E756 · ★★★

#include <stdbool.h>
#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

bool proxima(int v[], int n) {
    int i = n - 2;
    while (i >= 0 && v[i] >= v[i + 1]) {
        i--;                         // procura o pivô
    }
    if (i < 0) {
        return false;                // tudo decrescente: é a última
    }
    int j = n - 1;
    while (v[j] <= v[i]) {
        j--;                         // o menor maior que o pivô, à direita
    }
    troca(&v[i], &v[j]);
    for (int a = i + 1, b = n - 1; a < b; a++, b--) {
        troca(&v[a], &v[b]);         // inverte o final
    }
    return true;
}

void mostra(const int v[], int n) {
    for (int k = 0; k < n; k++) {
        printf(k == 0 ? "%d" : " %d", v[k]);
    }
}

int main(void) {
    int v[3] = {1, 2, 3};
    do {
        mostra(v, 3);
        printf("\n");
    } while (proxima(v, 3));

    int w[5] = {1, 3, 5, 4, 2};
    printf("depois de ");
    mostra(w, 5);
    proxima(w, 5);
    printf(" vem ");
    mostra(w, 5);
    printf("\n");

    int u[5] = {5, 4, 3, 2, 1};
    mostra(u, 5);
    printf(proxima(u, 5) ? " tem próxima\n" : " é a última\n");
    return 0;
}
