// 0090 · Busca binária
// Exercício E536 · ★☆☆

#include <stdio.h>

// procura x em v[ini..fim] (fechado); devolve o índice ou -1
int busca_rec(const int v[], int ini, int fim, int x) {
    if (ini > fim) {
        return -1;                              // caso base: intervalo vazio
    }
    int meio = ini + (fim - ini) / 2;
    if (v[meio] == x) {
        return meio;                            // caso base: achou
    }
    if (v[meio] < x) {
        return busca_rec(v, meio + 1, fim, x);  // o return é obrigatório
    }
    return busca_rec(v, ini, meio - 1, x);
}

int main(void) {
    int ceps[] = {1310100, 4538132, 20040002, 30130010, 40020000,
                  50030230, 60060440, 70040010, 80010000, 90010150};
    int n = 10;
    int procurados[] = {40020000, 22222222};

    for (int k = 0; k < 2; k++) {
        printf("CEP %08d: posição %d\n", procurados[k],
               busca_rec(ceps, 0, n - 1, procurados[k]));
    }
    return 0;
}
