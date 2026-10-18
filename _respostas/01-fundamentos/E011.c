// 0002 · Variáveis
// Exercício E011 · ★★★
//
// Resposta: (1) gols_fora era usada sem valor ("'gols_fora' is used
// uninitialized"): mostraria lixo. (2) "V" é um texto (aspas duplas), e o
// gcc reclama que está guardando um endereço num char ("makes integer from
// pointer without a cast"): o caractere é 'V'. (3) %d com um double ("format
// '%d' expects argument of type 'int'"): o printf leria os bytes errados.
// Público é contagem de pessoas, então o tipo certo é int.

#include <stdio.h>

int main(void) {
    int gols_casa = 2;
    int gols_fora = 1;
    char resultado = 'V';
    int publico = 45000;

    printf("Placar: %d x %d\n", gols_casa, gols_fora);
    printf("Resultado: %c\n", resultado);
    printf("Público: %d\n", publico);
    return 0;
}
