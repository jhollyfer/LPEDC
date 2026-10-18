// 0095 · Quick sort
// Exercício E565 · ★☆☆

#include <stdio.h>

static int comparacoes = 0;

void troca(int v[], int a, int b) {
    printf("troca v[%d] e v[%d]\n", a, b);
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

int separa(int v[], int p, int r) {
    int pivo = v[r], j = p;
    for (int k = p; k < r; k++) {
        comparacoes++;
        if (v[k] <= pivo) {
            troca(v, j, k);
            j++;
        }
    }
    troca(v, j, r);
    return j;
}

void mostra(const int v[], int n) {
    printf("vetor:");
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
}

int main(void) {
    int senhas[] = {9, 2, 6, 4, 8, 5};
    int j = separa(senhas, 0, 5);
    mostra(senhas, 6);
    printf("pivô na posição %d\n", j);

    int j2 = separa(senhas, j + 1, 5);       // agora só o lado direito
    mostra(senhas, 6);
    printf("pivô na posição %d\n", j2);
    printf("comparações: %d\n", comparacoes);
    return 0;
}
