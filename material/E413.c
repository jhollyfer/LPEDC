// 0069 · Argumentos da linha de comando
// Exercício E413 · ★★★
//
// Faça um "wc" de verdade: o nome do arquivo vem pela linha de comando. O
// programa abre o arquivo, conta linhas, palavras e bytes e mostra no formato
// abaixo. Se não vier exatamente um argumento, mostre o uso em stderr e
// devolva 1. Se o arquivo não abrir, use perror com o nome dele e devolva 1.
//
//   Argumentos (o arquivo tem 4 linhas: "Oi, Ana", "tudo certo?", uma vazia
//   e "Até amanhã"):
//   /tmp/recado.txt
//
//   Saída esperada:
//   4 linhas, 6 palavras, 34 bytes em /tmp/recado.txt
//
//   Argumentos (arquivo que não existe):
//   /tmp/nao-existe.txt
//
//   Saída esperada (em stderr):
//   /tmp/nao-existe.txt: No such file or directory
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    (void) argc;
    (void) argv;

    return 0;
}
