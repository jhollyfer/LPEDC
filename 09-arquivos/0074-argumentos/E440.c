// 0074 · Argumentos da linha de comando
// Exercício E440 · ★☆☆
//
// Leia o código do E440.c e preveja a saída antes de rodar, para este comando:
//
//   $ rodar E440.c 7 + 3a
//
// Dicas:
// 1. Tudo no argv é string. argv[1][0] é o primeiro CARACTERE do primeiro
//    argumento.
// 2. '7' - '0' vale 7: é o truque do assunto 0045 para transformar um dígito
//    em número.
// 3. atoi lê enquanto encontra dígitos e para no primeiro que não é: não
//    avisa nada.
// 4. Resposta esperada: "argc = 4"; "argv[2] = +"; "tamanho de argv[3] = 2";
//    "7 + 3 = 10"; "atoi("3a") = 3"; "atoi("+") = 0".
//
// Escreva sua resposta abaixo (um comentário com a saída prevista) e depois
// rode para conferir:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Rode com: rodar E440.c 7 + 3a\n");
        return 1;
    }
    printf("argc = %d\n", argc);
    printf("argv[2] = %s\n", argv[2]);
    printf("tamanho de argv[3] = %zu\n", strlen(argv[3]));
    printf("%c + %c = %d\n", argv[1][0], argv[3][0], (argv[1][0] - '0') + (argv[3][0] - '0'));
    printf("atoi(\"%s\") = %d\n", argv[3], atoi(argv[3]));
    printf("atoi(\"%s\") = %d\n", argv[2], atoi(argv[2]));
    return 0;
}
