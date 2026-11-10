// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0915 · ★★☆ · A média com modo detalhado
//
// As notas chegam pela linha de comando. Se o PRIMEIRO argumento for "-v"
// (de verboso), o programa mostra cada nota antes da média; sem "-v", mostra
// só a média. Sem nenhuma nota (inclusive quando só veio o "-v"), ele mostra
// "uso: P0915 [-v] nota1 nota2 ..." e termina com return 1.
//
//   $ ./rodar P0915.c -v 7 8 9.5
//
//   Saída esperada:
//   nota 1: 7.0
//   nota 2: 8.0
//   nota 3: 9.5
//   Média: 8.17
//
// Com ./rodar P0915.c 7 8 9.5 sai só a linha "Média: 8.17".
//
// Dicas:
// 1. Compare com strcmp(argv[1], "-v") == 0, mas só se argc >= 2.
// 2. Use uma variável "primeira" com o índice da primeira nota: 2 com o
//    "-v", 1 sem ele. O número de notas é argc - primeira.
// 3. Resposta esperada: com -v, as três notas e Média: 8.17 (24.5 / 3).
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
