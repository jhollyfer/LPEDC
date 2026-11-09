// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1705 · ★☆☆ · A árvore de recursão do merge sort, nível por nível

#include <stdio.h>
#include <string.h>

int aux[16];
int nos[8], custo[8];

void intercala(int v[], int ini, int meio, int fim) {
    int i = ini, j = meio + 1, k = 0;
    while (i <= meio && j <= fim) aux[k++] = v[i] <= v[j] ? v[i++] : v[j++];
    while (i <= meio) aux[k++] = v[i++];
    while (j <= fim) aux[k++] = v[j++];
    memcpy(v + ini, aux, k * sizeof(int));
}

void merge_sort(int v[], int ini, int fim, int nivel) {
    nos[nivel]++;
    custo[nivel] += fim - ini + 1; // tamanho do pedaço
    if (ini >= fim) return;
    int meio = (ini + fim) / 2;
    merge_sort(v, ini, meio, nivel + 1);
    merge_sort(v, meio + 1, fim, nivel + 1);
    intercala(v, ini, meio, fim);
}

void arvore(int n) {
    int precos[16] = {12, 5, 30, 8, 22, 9, 15, 3, 40, 18, 7, 25, 11, 2, 33, 19};
    for (int i = 0; i < 8; i++) nos[i] = custo[i] = 0;
    merge_sort(precos, 0, n - 1, 0);
    printf("n = %d:", n);
    for (int i = 0; i < n; i++) printf(" %d", precos[i]);
    printf("\nnível  chamadas  custo\n");
    int total = 0;
    for (int i = 0; i < 8 && nos[i]; i++) {
        printf("%5d %9d %6d\n", i, nos[i], custo[i]);
        total += custo[i];
    }
    printf("Total: %d\n", total);
}

int main(void) {
    arvore(16);
    arvore(10);
    return 0;
}
