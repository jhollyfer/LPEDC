// 0034 · Parâmetros e passagem por valor
// Exercício E201 · ★★☆
//
// Resposta: ordenar recebe cópias de a e b. A troca acontece nas cópias, que
// somem quando a função termina; o a e o b do main nunca mudam. Sem ponteiros,
// a saída é ter funções que devolvem o valor certo.

#include <stdio.h>

int menor(int a, int b) {
    return a < b ? a : b;
}

int maior(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int a = 9;
    int b = 6;

    printf("Em ordem: %d e %d\n", menor(a, b), maior(a, b));
    return 0;
}
