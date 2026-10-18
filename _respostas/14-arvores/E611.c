// 0102 · Heap e fila de prioridade
// Exercício E611 · ★★★

#include <stdio.h>

#define K 3

int v[K]; // min-heap: o menor dos três fica em v[0]
int n = 0;

void troca(int a, int b) {
    int t = v[a];
    v[a] = v[b];
    v[b] = t;
}

void sobe(int i) {
    while (i > 0 && v[(i - 1) / 2] > v[i]) { // MENOR que o pai sobe
        troca((i - 1) / 2, i);
        i = (i - 1) / 2;
    }
}

void desce(int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && v[f + 1] < v[f]) {
            f++; // o MENOR dos filhos
        }
        if (v[i] <= v[f]) {
            break;
        }
        troca(i, f);
        i = f;
    }
}

int tira_menor(void) {
    int menor = v[0];
    v[0] = v[--n];
    desce(0);
    return menor;
}

int main(void) {
    int notas[] = {72, 95, 60, 88, 91, 45, 98, 83, 77, 90, 66, 85};
    int total = sizeof(notas) / sizeof(notas[0]);

    for (int i = 0; i < total; i++) {
        if (n < K) {
            v[n] = notas[i];
            sobe(n);
            n++;
        } else if (notas[i] > v[0]) {
            v[0] = notas[i]; // a menor do pódio sai, a nova entra
            desce(0);
        }
    }

    int podio[K];
    int qtd = n;
    for (int i = 0; i < qtd; i++) {
        podio[i] = tira_menor(); // sai em ordem crescente
    }
    printf("Pódio:");
    for (int i = qtd - 1; i >= 0; i--) {
        printf(" %d", podio[i]);
    }
    printf("\n");
    return 0;
}
