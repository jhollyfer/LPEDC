// 0114 · Recorrências e árvore de recursão
// Exercício E679 · ★☆☆
//
// A busca binária recursiva abaixo segue a recorrência T(n) = T(n/2) + 1.
// Confira isso no computador: acrescente um contador global de chamadas e
// troque o main para buscar o valor 5 (menor que todos os CPFs, o pior caso
// quando n é potência de 2) em pedaços de tamanho n = 1, 2, 4, ..., 1024 do
// vetor, sempre a partir do índice 0, mostrando quantas chamadas cada busca
// fez:
//
//   Saída esperada:
//      n  chamadas
//      1  2
//      2  3
//      4  4
//    ...
//    512  11
//   1024  12
//
// Escreva sua resposta abaixo (mude o programa):

#include <stdio.h>

// procura x em v[ini..fim-1], ordenado
int busca(const int v[], int ini, int fim, int x) {
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

    printf("posição do 300: %d\n", busca(cpfs, 0, 1024, 300));
    return 0;
}
