// Lista · Módulo 13 · Busca e ordenação
// Exercício P1302 · ★☆☆ · Quantas voltas a busca binária dá
//
// A tabela de preços da papelaria (em reais, em ordem crescente) tem 15
// itens. Complete a busca binária (intervalo fechado [ini, fim]) para que ela
// conte em *voltas quantas vezes o while rodou, e mostre o resultado para os
// preços 33, 28, 3, 89 e 50.
//
//   Saída esperada:
//   R$ 33: posição 7 (voltas: 1)
//   R$ 28: posição 6 (voltas: 4)
//   R$ 3: posição 0 (voltas: 4)
//   R$ 89: posição 14 (voltas: 4)
//   R$ 50: posição -1 (voltas: 4)
//
// Dicas:
// 1. Some 1 em *voltas logo no começo do corpo do while.
// 2. O meio é ini + (fim - ini) / 2.
// 3. Com 15 elementos, o pior caso é ⌊log₂ 15⌋ + 1 = 4 voltas, achando ou não.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

int busca_binaria(const int v[], int n, int x, int *voltas) {
    int ini = 0, fim = n - 1;
    *voltas = 0;
    // complete aqui
    (void)v;
    (void)x;
    (void)ini;
    (void)fim;
    return -1;
}

int main(void) {
    int precos[] = {3, 7, 12, 15, 19, 24, 28, 33, 41, 47, 52, 60, 68, 75, 89};
    int n = 15;
    int alvos[] = {33, 28, 3, 89, 50};
    int voltas;

    for (int k = 0; k < 5; k++) {
        int pos = busca_binaria(precos, n, alvos[k], &voltas);
        printf("R$ %d: posição %d (voltas: %d)\n", alvos[k], pos, voltas);
    }
    return 0;
}
