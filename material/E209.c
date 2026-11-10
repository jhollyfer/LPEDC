// 0035 · Pré-processador: macros e #ifdef
// Exercício E209 · ★★★
//
// A macro avalia o argumento cada vez que ele aparece. Escreva a macro
// MAIOR(a, b), à prova de precedência, a função "int maior(int a, int b)", a
// função "int maior3(int a, int b, int c)" (usa maior) e "int pontos(int p)",
// que soma 1 na global chamadas e devolve p. No main, mostre (x = 5, y = 3):
// MAIOR(x++, y) e maior(x++, y); MAIOR e maior com pontos(40) e pontos(25);
// MAIOR aninhada e maior3 com pontos(7), pontos(19) e pontos(12). Cada linha
// mostra m e (x ou chamadas).
//
//   Saída esperada:
//   macro:  m = 6, x = 7
//   função: m = 5, x = 6
//   macro:  m = 40, chamadas = 3
//   função: m = 40, chamadas = 2
//   macro aninhada: m = 19, chamadas = 7
//   maior3: m = 19, chamadas = 3
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int chamadas = 0;

int main(void) {

    return 0;
}
