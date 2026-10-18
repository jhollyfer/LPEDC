// 0114 · Recorrências e árvore de recursão
// Exercício E679 · ★☆☆

#include <stdio.h>

long chamadas = 0;

// procura x em v[ini..fim-1], ordenado: T(n) = T(n/2) + 1
int busca(const int v[], int ini, int fim, int x) {
    chamadas++;
    if (ini >= fim) {
        return -1;                       // pedaço vazio: não achou
    }
    int meio = ini + (fim - ini) / 2;
    if (v[meio] == x) {
        return meio;
    }
    if (x < v[meio]) {
        return busca(v, ini, meio, x);
    }
    return busca(v, meio + 1, fim, x);
}

int main(void) {
    int cpfs[1024];
    for (int i = 0; i < 1024; i++) {
        cpfs[i] = 10 * (i + 1);          // 10, 20, 30, ... (ordenado)
    }

    printf("   n  chamadas\n");
    for (int n = 1; n <= 1024; n *= 2) {
        chamadas = 0;
        busca(cpfs, 0, n, 5);            // 5 é menor que todos: pior caso
        printf("%4d  %ld\n", n, chamadas);
    }
    return 0;
}
