// 0003 · Tipos e limites
// Exercício E014 · ★☆☆
//
// Resposta: idade e temperatura cabem em int8_t (signed char, -128 a 127);
// população cabe em int (até 2147483647); o arquivo de 5 GB passa de 4,2
// bilhões e precisa de long long (ou int64_t); o ano cabe em short.

#include <stdio.h>
#include <stdint.h>

int main(void) {
    int8_t idade = 34;
    int8_t temperatura = -8;
    int populacao = 203080756;
    long long arquivo = 5368709120;
    short ano = 1991;

    printf("idade: %d\n", idade);
    printf("temperatura: %d\n", temperatura);
    printf("população: %d\n", populacao);
    printf("arquivo: %lld bytes\n", arquivo);
    printf("ano: %d\n", ano);
    return 0;
}
