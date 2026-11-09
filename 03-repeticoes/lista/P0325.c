// Lista · Módulo 03 · Laços
// Exercício P0325 · ★★★ · A rotina de Kaprekar
//
// Pegue um número de 4 dígitos que não tenha os quatro iguais. Ordene os
// dígitos do maior para o menor e do menor para o maior, e subtraia. Repita com
// o resultado (mantendo zeros à esquerda, como em 0378). Em no máximo 7 passos
// você chega em 6174 e fica lá para sempre. Escreva um programa que mostre os
// passos a partir de 3524. Ainda sem vetor, para ordenar os dígitos, ande pelos
// valores de 9 a 0 e, para cada valor, conte quantas vezes ele aparece:
//
//   Saída esperada:
//   5432 - 2345 = 3087
//   8730 - 0378 = 8352
//   8532 - 2358 = 6174
//   Chegou em 6174 em 3 passos
//
// Dicas:
// 1. Para montar o maior: para v de 9 a 0, para cada um dos 4 dígitos de n (n
//    % 10, n / 10 % 10, ...), se o dígito for v, maior = maior * 10 + v.
// 2. O menor é o mesmo laço com v de 0 a 9.
// 3. Mostre com %04d para manter os zeros à esquerda.
// 4. Resposta esperada: 3 passos até 6174.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
