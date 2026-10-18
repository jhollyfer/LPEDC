// 0136 · Código de Huffman
// Exercício E814 · ★★☆

#include <stdio.h>

#define CAP 16

int v[CAP];
int n = 0;

void troca(int a, int b) {
    int t = v[a];
    v[a] = v[b];
    v[b] = t;
}

// heap de MÍNIMO: o pai é sempre menor ou igual aos filhos
void poe(int x) {
    int i = n++;
    v[i] = x;
    while (i > 0 && v[i] < v[(i - 1) / 2]) {
        troca(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

int tira(void) {
    int topo = v[0];
    v[0] = v[--n];
    int i = 0;
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && v[f + 1] < v[f]) {
            f++;                  // o MENOR dos filhos
        }
        if (v[i] <= v[f]) {
            break;
        }
        troca(i, f);
        i = f;
    }
    return topo;
}

int main(void) {
    int mb[] = {8, 3, 15, 6, 10}; // tamanho de cada arquivo de log, em MB
    for (int i = 0; i < 5; i++) {
        poe(mb[i]);
    }
    int custo = 0;
    while (n > 1) {
        int a = tira();
        int b = tira();
        printf("junta %d + %d\n", a, b);
        custo += a + b;
        poe(a + b);
    }
    printf("Custo: %d MB lidos\n", custo);
    return 0;
}
