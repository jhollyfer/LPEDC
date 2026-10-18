// A010 · O pré-processador trocando texto

#include <stdio.h>

#define NOME_DO_CURSO "LPEDC"
#define ANO 2026

// O pré-processador troca NOME_DO_CURSO e ANO pelo texto antes de o
// compilador ver o código. __LINE__ vira o número da linha onde aparece.
int main(void) {
    printf("Curso: %s\n", NOME_DO_CURSO);
    printf("Ano: %d\n", ANO);
    printf("Esta frase está na linha %d do arquivo\n", __LINE__);
    return 0;
}
// Saída:
// Curso: LPEDC
// Ano: 2026
// Esta frase está na linha 13 do arquivo
//
// Veja a troca acontecendo: gcc -E A010.c | tail -8
