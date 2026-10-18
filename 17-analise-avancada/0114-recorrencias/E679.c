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
// Dicas:
// 1. Declare long chamadas = 0; fora das funções e faça chamadas++ na
//    primeira linha de busca, antes de qualquer return.
// 2. Zere o contador antes de cada busca. O laço de fora pode ser
//    for (int n = 1; n <= 1024; n *= 2), chamando busca(cpfs, 0, n, 5).
// 3. Resposta esperada: a tabela acima, chamadas = log2(n) + 2. Um nível
//    por divisão ao meio, mais a chamada com 1 elemento e a chamada com o
//    pedaço vazio, que é quem devolve -1.
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
