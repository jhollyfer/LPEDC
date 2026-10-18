// 0094 · Merge sort
// Exercício E560 · ★☆☆
//
// O programa abaixo não ordena nada: ele só mostra QUAIS chamadas o merge sort
// faria para um vetor de 5 elementos, com um recuo de dois espaços por nível
// de recursão. Estenda o programa:
//
// a) escreva " folha" ao lado dos pedaços com menos de 2 elementos (os que
//    não chamam ninguém);
// b) conte, em variáveis static, quantas chamadas aconteceram e quantas
//    foram folhas;
// c) no fim do main, mostre os dois totais e quantas intercalações o merge
//    sort faria (uma por chamada que não é folha).
//
//   Saída esperada:
//   [0, 5)
//     [0, 2)
//       [0, 1) folha
//       [1, 2) folha
//     [2, 5)
//       [2, 3) folha
//       [3, 5)
//         [3, 4) folha
//         [4, 5) folha
//   9 chamadas, 5 folhas, 4 intercalações
//
// Dicas:
// 1. static int chamadas = 0, folhas = 0; fora das funções.
// 2. Some 1 em chamadas logo na entrada de ordena; some em folhas dentro do
//    if que faz o return.
// 3. Troque o printf("[%d, %d)\n", ...) por um sem \n e decida depois se
//    escreve " folha\n" ou só "\n".
// 4. Resposta esperada: a saída acima. As folhas são os n elementos, e as
//    intercalações são sempre n - 1.
//
// Escreva sua resposta abaixo (modifique o código):

#include <stdio.h>

void ordena(int p, int r, int nivel) {
    for (int i = 0; i < nivel; i++) {
        printf("  ");
    }
    printf("[%d, %d)\n", p, r);
    if (r - p < 2) {
        return;
    }
    int q = p + (r - p) / 2;
    ordena(p, q, nivel + 1);
    ordena(q, r, nivel + 1);
}

int main(void) {
    ordena(0, 5, 0);
    return 0;
}
