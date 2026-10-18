// 0055 · calloc e realloc
// Exercício E326 · ★☆☆
//
// O programa abaixo funciona e mostra as notas do boletim. Mesmo assim, a
// linha do realloc tem um problema que só aparece quando falta memória.
// Refatore o trecho do realloc para ele não perder o bloco antigo se
// falhar, e rode de novo para conferir que a saída não mudou.
//
//   Saída esperada (antes e depois):
//   Notas: 7 8 10
//
// Dicas:
// 1. O que vale notas se o realloc devolver NULL? E o bloco antigo?
// 2. Use um ponteiro temporário e só troque se ele não for NULL.
// 3. Resposta esperada: com notas = realloc(notas, ...), uma falha joga
//    NULL em notas e o endereço do bloco antigo se perde: vazamento e perda
//    das notas já guardadas. Conserto:
//    int *maior = realloc(notas, 3 * sizeof *notas);
//    if (maior == NULL) { free(notas); return 1; }
//    notas = maior;
//
// Escreva sua resposta abaixo (refatore o código):

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *notas = malloc(2 * sizeof *notas);
    if (notas == NULL) {
        return 1;
    }
    notas[0] = 7;
    notas[1] = 8;

    notas = realloc(notas, 3 * sizeof *notas);
    if (notas == NULL) {
        return 1;
    }
    notas[2] = 10;

    printf("Notas: %d %d %d\n", notas[0], notas[1], notas[2]);
    free(notas);
    return 0;
}
