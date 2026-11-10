// 0070 · Juntando tudo
// Exercício E420 · ★★★
//
// Faça um "grep" simplificado que recebe [-c] <palavra> <arquivo>. Sem -c,
// mostra cada linha do arquivo que contém a palavra, com o número da linha, e
// no fim quantas linhas casaram. Com -c, mostra só a contagem. O código de
// saída é 0 se achou alguma linha e 1 se não achou. Argumentos errados mostram
// o uso em stderr; arquivo que não abre usa perror. Nos dois casos, devolva 2.
//
//   Arquivo /tmp/lista.txt: "arroz 5kg", "feijao", "arroz integral", "cafe".
//
//   Argumentos:
//   arroz /tmp/lista.txt
//
//   Saída esperada:
//   1: arroz 5kg
//   3: arroz integral
//   2 linhas
//
//   Argumentos:
//   -c arroz /tmp/lista.txt
//
//   Saída esperada:
//   2
//
//   Argumentos (código de saída 1):
//   leite /tmp/lista.txt
//
//   Saída esperada:
//   0 linhas
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    (void) argc;
    (void) argv;

    return 0;
}
