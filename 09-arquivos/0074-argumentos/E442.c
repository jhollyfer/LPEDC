// 0074 · Argumentos da linha de comando
// Exercício E442 · ★★☆
//
// O programa deveria cumprimentar alguém um certo número de vezes:
//
//   $ rodar E442.c Ana 3
//   Olá, Ana!
//   Olá, Ana!
//   Olá, Ana!
//
// Mas, rodando assim, ele não mostra nada. E rodando sem argumentos
// ("rodar E442.c"), ele cai com SEGV no AddressSanitizer. São dois erros:
//
// a) um índice errado no argv;
// b) uma conferência que falta antes de usar o argv.
//
// Explique cada um e conserte. Sem argumentos (ou com um número de vezes que
// não é inteiro positivo), o programa deve mostrar uma mensagem de uso em
// stderr e devolver 1.
//
// Dicas:
// 1. Quem é argv[0]? O que atoi("Ana") devolve?
// 2. Sem argumentos, argc vale 1 e argv[1] é NULL. O que atoi(NULL) faz?
// 3. Resposta esperada: a) o nome está em argv[1] e as vezes em argv[2]; o
//    código usava argv[0] (o caminho do programa) e argv[1] ("Ana", que o
//    atoi vira 0, então o laço não roda); b) falta conferir argc != 3 antes
//    de tocar no argv. Consertado, "rodar E442.c Ana 3" mostra Olá, Ana! três
//    vezes.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    (void) argc;
    char *nome = argv[0];
    int vezes = atoi(argv[1]);

    for (int i = 0; i < vezes; i++) {
        printf("Olá, %s!\n", nome);
    }
    return 0;
}
