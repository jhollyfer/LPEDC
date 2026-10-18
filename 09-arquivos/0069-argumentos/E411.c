// 0069 · Argumentos da linha de comando
// Exercício E411 · ★★☆
//
// As notas da prova chegam pela linha de comando. Mostre quantas notas
// válidas vieram, a média, a maior e a menor. Argumento que não é número
// (ou que está fora de 0 a 10) é ignorado com um aviso em stderr. Sem
// nenhuma nota válida, mostre "Nenhuma nota válida" e devolva 1.
//
//   $ rodar E411.c 8.5 7 nove 9.25 6 11
//   Ignorando "nove"
//   Ignorando "11"
//   Notas: 4
//   Média: 7.69
//   Maior: 9.25
//   Menor: 6.00
//
// Dicas:
// 1. Use strtod(argv[i], &fim) e confira *fim == '\0' (e que fim andou: um
//    argumento vazio "" também deixa *fim == '\0').
// 2. Comece maior e menor com a primeira nota válida, não com 0.
// 3. Resposta esperada: 4 notas, média 7.69 (30.75 / 4 = 7.6875), maior 9.25
//    e menor 6.00.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    (void) argc; // apague estas duas linhas quando usar argc e argv
    (void) argv;

    return 0;
}
