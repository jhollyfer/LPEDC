// Lista · Módulo 06 · Ponteiros
// Exercício P0608 · ★☆☆ · Conserte os ponteiros soltos

#include <stdio.h>

int mais_cheia(int a, int b) {
    return a > b ? a : b; // o valor sobrevive ao return; o endereço não
}

int main(void) {
    int sessao_tarde = 87;
    int sessao_noite = 142;
    int publico;
    int *p = &publico; // agora p aponta para uma variável de verdade

    *p = sessao_tarde + sessao_noite;
    printf("Público do dia: %d\n", *p);
    printf("Sessão mais cheia: %d\n", mais_cheia(sessao_tarde, sessao_noite));
    return 0;
}
