// Lista · Módulo 12 · Pilhas e filas
// Exercício P1216 · ★★☆ · Quantos dias até esquentar?
//
// As máximas da semana foram 28, 26, 27, 30, 25, 29 e 31 graus. Para cada
// dia, quantos dias você espera até uma máxima MAIOR que a dele? (0 se não
// vier nenhuma.) Com dois laços sai em O(n²). Com uma pilha de ÍNDICES sai
// em O(n): a pilha guarda os dias que ainda esperam por um dia mais quente.
// Escreva
//
//   void espera(const int t[], int n, int resposta[], int *operacoes)
//
// contando em *operacoes os empilha e desempilha.
//
//   Saída esperada:
//   28 26 27 30 25 29 31
//    3  1  1  3  1  1  0
//   operações na pilha: 13
//
// Dicas:
// 1. Para cada dia i: enquanto a pilha não estiver vazia e t[topo] < t[i],
//    desempilhe o topo j e anote resposta[j] = i - j. Depois empilhe i.
// 2. Quem sobrar na pilha no fim nunca viu um dia mais quente: resposta 0.
// 3. Cada índice é empilhado uma vez e desempilhado no máximo uma vez: até
//    2n operações, por isso O(n). Aqui: 7 empilha + 6 desempilha.
// 4. Resposta esperada: a saída acima (cada número com "%2d" e um espaço
//    entre eles).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
