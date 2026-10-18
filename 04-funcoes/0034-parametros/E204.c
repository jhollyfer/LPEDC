// 0034 · Parâmetros e passagem por valor
// Exercício E204 · ★★★
//
// Um número é capicua (palíndromo) quando se lê igual de trás para frente:
// 1221, 343. Escreva:
//
//   int inverter(int n)        devolve n com os dígitos invertidos (123 -> 321);
//                              use o próprio n como variável de trabalho
//   bool eh_capicua(int n)     usa inverter
//
// No main, mostre inverter(12345), prove que a variável do main não mudou e
// conte as capicuas de 100 a 999.
//
//   Saída esperada:
//   inverter(12345) = 54321
//   No main, numero continua 12345
//   Capicuas de 100 a 999: 90
//
// Dicas:
// 1. Para inverter: enquanto n > 0, invertido = invertido * 10 + n % 10 e
//    n = n / 10.
// 2. eh_capicua cabe numa linha: return inverter(n) == n;
// 3. Resposta esperada: 54321, 12345 e 90 capicuas (9 escolhas para o primeiro
//    dígito, que também é o último, vezes 10 para o do meio).
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
