// A001 · Quem separa as instruções é o ponto e vírgula

/*
   Para o compilador, quebra de linha, espaço e recuo são só enfeite.
   O que termina uma instrução é o ; e o que agrupa é o par de chaves.
*/
#include <stdio.h>

int main(void) {
    // duas instruções na mesma linha: o ; separa uma da outra
    printf("Banca do Seu Zé\n"); printf("Frutas e verduras\n");

    // uma instrução espalhada em três linhas: ela só acaba no ;
    printf(
        "Abacaxi: R$ 7,00\n"
    );

    printf("\n"); // um printf só com \n deixa uma linha em branco

    printf("Banana: R$ 5,50 a dúzia\n"); /* comentário de bloco no fim */
    printf(/* comentário até no meio */ "Laranja: R$ 4,00 o kg\n");
    return 0;
}
// Saída:
// Banca do Seu Zé
// Frutas e verduras
// Abacaxi: R$ 7,00
//
// Banana: R$ 5,50 a dúzia
// Laranja: R$ 4,00 o kg
//
// O recuo de 4 espaços também é só para quem lê: apague todos e rode de
// novo. A saída é a mesma. Agora apague o ; do primeiro printf e veja o gcc
// reclamar do printf seguinte, que está na mesma linha.
