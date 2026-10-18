// 0032 · Recursão
// Exercício E188 · ★☆☆
//
// Complete a função potencia, recursiva, sem laço e sem pow. Hoje ela só
// devolve 0 para o programa compilar. Use: base elevado a 0 é 1; base elevado
// a e é base vezes base elevado a (e - 1).
//
//   Saída esperada:
//   2^10 = 1024
//   3^4 = 81
//   7^0 = 1
//
// Dicas:
// 1. O caso base é expoente == 0.
// 2. O caso recursivo devolve base * potencia(base, expoente - 1).
// 3. Resposta esperada: 1024, 81 e 1. Para 2^10, a pilha chega a 11 quadros
//    de potencia (expoentes de 10 até 0).
//
// Escreva sua resposta abaixo (complete o código):

#include <stdio.h>

int potencia(int base, int expoente) {
    // complete aqui
    (void)base;     // tire estas duas linhas quando usar os parâmetros
    (void)expoente;
    return 0;
}

int main(void) {
    printf("2^10 = %d\n", potencia(2, 10));
    printf("3^4 = %d\n", potencia(3, 4));
    printf("7^0 = %d\n", potencia(7, 0));
    return 0;
}
