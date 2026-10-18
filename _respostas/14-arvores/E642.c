// 0107 · Heap e fila de prioridade
// Exercício E642 · ★★★
//
// Resposta: a descida trocava com o primeiro filho maior que o pai, e não
// com o maior dos dois. Na segunda remoção o vetor era [30 40 50 20]: o 30
// trocou com o 40, e o 40 foi para a raiz acima do 50. Daí em diante o
// atendimento sai fora de ordem.

#include <stdio.h>

#define CAP 10

int v[CAP];
int n = 0;

void troca(int a, int b) {
    int t = v[a];
    v[a] = v[b];
    v[b] = t;
}

void chega(int x) {
    int i = n++;
    v[i] = x;
    while (i > 0 && v[(i - 1) / 2] < v[i]) {
        troca((i - 1) / 2, i);
        i = (i - 1) / 2;
    }
}

int atende(void) {
    int max = v[0];
    v[0] = v[--n];
    int i = 0;
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && v[f + 1] > v[f]) {
            f++; // escolhe o MAIOR dos dois filhos
        }
        if (v[i] >= v[f]) {
            break;
        }
        troca(i, f);
        i = f;
    }
    return max;
}

int main(void) {
    int chegada[] = {40, 70, 20, 90, 30, 50};
    for (int k = 0; k < 6; k++) {
        chega(chegada[k]);
    }
    printf("Atendimento:");
    while (n > 0) {
        printf(" %d", atende());
    }
    printf("\n");
    return 0;
}
