// 0074 · Argumentos da linha de comando
// Exercício E439 · ★☆☆
//
// Faça o seu próprio "echo": o programa mostra os argumentos recebidos, na
// mesma linha, separados por um espaço (sem espaço sobrando no fim), e na
// linha de baixo quantos foram. Sem argumentos, mostra só "0 argumentos".
//
//   $ rodar E439.c bom dia Brasil
//   bom dia Brasil
//   3 argumentos
//
// Dicas:
// 1. Os seus argumentos vão de argv[1] até argv[argc - 1].
// 2. Imprima o espaço ANTES de cada argumento, menos do primeiro.
// 3. Resposta esperada: "bom dia Brasil" e "3 argumentos" (argc vale 4,
//    porque argv[0] também conta).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(int argc, char *argv[]) {
    (void) argc; // apague estas duas linhas quando usar argc e argv
    (void) argv;

    return 0;
}
