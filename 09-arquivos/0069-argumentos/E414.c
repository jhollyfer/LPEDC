// 0069 · Argumentos da linha de comando
// Exercício E414 · ★★★
//
// Calculadora de linha de comando: número, operador, número.
//
//   $ rodar E414.c 12.5 + 7.5
//   12.50 + 7.50 = 20.00
//   $ rodar E414.c 9 x 3
//   9.00 x 3.00 = 27.00
//   $ rodar E414.c 10 / 0
//   Erro: divisão por zero
//   $ rodar E414.c 2 ^ 3
//   Erro: operador "^" desconhecido (use + - x /)
//
// Regras: exatamente 3 argumentos (senão, uso em stderr); os dois números
// validados com strtod; o operador tem que ter exatamente 1 caractere. Todo
// erro vai para stderr e o programa devolve 1. Use um switch no operador.
//
// Por que "x" e não "*"? Teste "rodar E414.c 9 * 3" sem aspas e descubra:
// o shell troca o * pelos nomes dos arquivos da pasta ANTES de o programa
// rodar. Com aspas ('*') funciona.
//
// Dicas:
// 1. O operador é argv[2]. Confira strlen(argv[2]) == 1 e use argv[2][0] no
//    switch.
// 2. Aceite também '*' no case do 'x' (para quem usar aspas).
// 3. Resposta esperada: as quatro saídas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    (void) argc; // apague estas duas linhas quando usar argc e argv
    (void) argv;

    return 0;
}
