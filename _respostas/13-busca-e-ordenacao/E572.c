// 0096 · Comparando: estabilidade, custo e qsort
// Exercício E572 · ★☆☆

#include <stdio.h>
#include <string.h>

int selection(int v[], int n) {
    int comparacoes = 0;
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        int aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
    return comparacoes;
}

int insertion(int v[], int n) {
    int comparacoes = 0;
    for (int j = 1; j < n; j++) {
        int x = v[j];
        int i = j - 1;
        while (i >= 0) {
            comparacoes++;
            if (v[i] <= x) {
                break;
            }
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = x;
    }
    return comparacoes;
}

int main(void) {
    // pontos do placar, quase em ordem: só o 58 está fora do lugar
    int placar[] = {10, 14, 19, 23, 27, 31, 36, 40, 45, 58, 49, 52};
    int n = 12;
    int a[12], b[12];
    memcpy(a, placar, sizeof placar);
    memcpy(b, placar, sizeof placar);

    int cs = selection(a, n);
    int ci = insertion(b, n);
    printf("selection: %d comparações\n", cs);
    printf("insertion: %d comparações\n", ci);
    printf("melhor para o placar: %s\n", ci < cs ? "insertion" : "selection");
    return 0;
}
