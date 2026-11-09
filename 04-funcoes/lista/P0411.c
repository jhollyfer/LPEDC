// Lista · Módulo 04 · Funções e modularização
// Exercício P0411 · ★★☆ · O número do pedido ao contrário
//
// Escreva a função recursiva "int inverte(int n, int acumulado)", que devolve
// n com os dígitos ao contrário, sem laço. A ideia é carregar o resultado
// parcial num parâmetro: a cada chamada, o último dígito de n passa para o fim
// de acumulado. O main chama inverte(n, 0). Teste com 12345, 1200 e 7:
//
//   Saída esperada:
//   12345 -> 54321
//   1200 -> 21
//   7 -> 7
//
// Dicas:
// 1. Caso base: if (n == 0) return acumulado;
// 2. Caso recursivo: return inverte(n / 10, acumulado * 10 + n % 10);
// 3. Os zeros do fim de 1200 viram zeros à esquerda, que não aparecem: 21.
// 4. Resposta esperada: 54321, 21 e 7.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
