// 0069 · Argumentos da linha de comando
// Exercício E413 · ★★★
//
// Faça um "wc" de verdade: o nome do arquivo vem pela linha de comando. O
// programa abre o arquivo, conta linhas, palavras e bytes e mostra no
// formato abaixo. Se não vier exatamente um argumento, mostre o uso em
// stderr e devolva 1. Se o arquivo não abrir, use perror com o nome dele e
// devolva 1.
//
// Para testar, crie um arquivo no terminal e passe o caminho:
//
//   $ printf 'Oi, Ana\ntudo certo?\n\nAté amanhã\n' > /tmp/recado.txt
//   $ rodar E413.c /tmp/recado.txt
//   4 linhas, 6 palavras, 34 bytes em /tmp/recado.txt
//
//   $ rodar E413.c /tmp/nao-existe.txt
//   /tmp/nao-existe.txt: No such file or directory
//
// Dicas:
// 1. Aproveite a lógica do E399: fgetc com int, uma flag dentro_palavra e
//    isspace.
// 2. "bytes", e não "letras": cada 'ã' e 'é' em UTF-8 ocupa 2 bytes. Por isso
//    dá 34, e não 32. Confira com: wc /tmp/recado.txt
// 3. Resposta esperada: "4 linhas, 6 palavras, 34 bytes em /tmp/recado.txt"
//    (a linha vazia conta como linha).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    (void) argc; // apague estas duas linhas quando usar argc e argv
    (void) argv;

    return 0;
}
