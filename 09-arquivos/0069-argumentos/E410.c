// 0069 · Argumentos da linha de comando
// Exercício E410 · ★☆☆
//
// Escreva um programa que mostre, para cada argumento recebido, o texto, o
// tamanho, o primeiro caractere e o que o atoi faz com ele. No começo,
// mostre o argc; no fim, a soma de todos os atoi. Teste com:
//
//   $ rodar E410.c 7 + 3a
//   argc = 4
//   argv[1] = "7": 1 caractere(s), começa com '7', atoi = 7
//   argv[2] = "+": 1 caractere(s), começa com '+', atoi = 0
//   argv[3] = "3a": 2 caractere(s), começa com '3', atoi = 3
//   Soma dos atoi: 10
//
// Dicas:
// 1. Tudo no argv é string. argv[i][0] é o primeiro CARACTERE do argumento
//    i, e strlen(argv[i]) dá o tamanho.
// 2. atoi lê enquanto encontra dígitos e para no primeiro que não é. Sem
//    nenhum dígito, devolve 0. Ele não avisa nada em nenhum dos casos.
// 3. Resposta esperada: a saída acima. Repare que "+" e "3a" passaram sem
//    nenhum aviso: é por isso que entrada de usuário pede strtol.
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
