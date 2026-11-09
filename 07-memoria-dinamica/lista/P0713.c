// Lista · Módulo 07 · Memória dinâmica
// Exercício P0713 · ★★☆ · Ler uma linha de qualquer tamanho
//
// O fgets precisa de um vetor de tamanho fixo. Escreva char *ler_linha(void),
// que lê uma linha inteira do teclado, de QUALQUER tamanho, com getchar: o
// buffer começa com capacidade 8 e dobra com realloc sempre que enche. O
// '\n' não entra. Devolve a linha no heap (quem chama faz o free), ou NULL se
// a entrada já tiver acabado. Para mostrar o crescimento, a função imprime
// uma linha a cada realloc. No main, leia uma linha e mostre o tamanho:
//
//   Exemplo de execução:
//   Rua Ramos Ferreira, 1200, Centro, Manaus
//   (cresceu para 16)
//   (cresceu para 32)
//   (cresceu para 64)
//   Lido: "Rua Ramos Ferreira, 1200, Centro, Manaus" (40 caracteres)
//
//   (a primeira linha é a que você digita)
//
// Dicas:
// 1. int c (não char!): o getchar devolve EOF, que não cabe num char.
// 2. Laço: while ((c = getchar()) != EOF && c != '\n'). Antes de guardar,
//    se n + 1 == cap (falta espaço para o caractere e o '\0'), dobre.
// 3. Se o primeiro getchar já der EOF, libere o buffer e devolva NULL.
// 4. Teste: printf 'Rua Ramos Ferreira, 1200, Centro, Manaus\n' | ./rodar ...
// 5. Resposta esperada: a execução acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
