// Lista · Módulo 01 · Fundamentos de C
// Exercício P0124 · ★★★ · O dígito do código de barras
//
// O código de barras dos produtos (EAN-13) tem 12 dígitos e um verificador.
// Multiplique os dígitos, da esquerda para a direita, alternando os pesos 1 e 3;
// o verificador é (10 − soma % 10) % 10. Escreva um programa que guarde
// 789123456789 num long long, calcule o verificador sem if e mostre o código
// completo:
//
//   Saída esperada:
//   Soma ponderada: 135
//   Verificador: 5
//   Código: 7891234567895
//
// Dicas:
// 1. 12 dígitos não cabem num int: use long long e o sufixo LL.
// 2. O 1º dígito é n / 100000000000 % 10, o último é n % 10. Pesos: 1, 3, 1,
//    3, ... (o 1º dígito tem peso 1).
// 3. O código completo é n * 10 + verificador, mostrado com %lld.
// 4. Resposta esperada: Código: 7891234567895.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
