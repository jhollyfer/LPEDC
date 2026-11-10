// 0069 · Argumentos da linha de comando
// Exercício E411 · ★★☆
//
// As notas da prova chegam pela linha de comando. Mostre quantas notas
// válidas vieram, a média, a maior e a menor. Argumento que não é número (ou
// que está fora de 0 a 10) é ignorado com um aviso em stderr. Sem nenhuma
// nota válida, mostre "Nenhuma nota válida" e devolva 1.
//
//   Argumentos:
//   8.5 7 nove 9.25 6 11
//
//   Saída esperada:
//   Ignorando "nove"
//   Ignorando "11"
//   Notas: 4
//   Média: 7.69
//   Maior: 9.25
//   Menor: 6.00
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    (void) argc;
    (void) argv;

    return 0;
}
