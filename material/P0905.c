// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0905 · ★☆☆ · A cidade de nome mais comprido
//
// Escreva um programa que recebe nomes de cidades pela linha de comando e
// mostra quantos vieram e qual é o mais comprido (no empate, vale o
// primeiro). Sem nenhum argumento, ele mostra como usar e termina com
// return 1.
//
//   $ ./rodar P0905.c manaus belem parintins tefe
//
//   Saída esperada:
//   4 cidades
//   Maior nome: parintins (9 letras)
//
// Sem argumentos, a saída é "uso: P0905 cidade1 cidade2 ...".
//
// Dicas:
// 1. argc conta também o argv[0] (o nome do programa): as cidades são
//    argv[1] até argv[argc - 1].
// 2. Guarde o ÍNDICE da maior e compare com strlen. Use > (e não >=) para
//    o empate ficar com a primeira.
// 3. Resposta esperada: 4 cidades, maior nome parintins com 9 letras.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    (void) argc; // apague estas duas linhas quando usar argc e argv
    (void) argv;

    return 0;
}
