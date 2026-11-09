// Lista · Módulo 07 · Memória dinâmica
// Exercício P0706 · ★☆☆ · O cartão mascarado
//
// O comprovante da maquininha mostra só os 4 últimos dígitos do cartão.
// Escreva char *mascarar(const char *num), que devolve uma string NOVA no
// heap, do mesmo tamanho de num, com cada dígito trocado por '*', menos os 4
// últimos dígitos (espaços continuam espaços). O original não muda. Teste:
//
//   const char *cartoes[3] = {"4539 1488 0343 6467", "5162 3001 9925", "1234"};
//
//   Saída esperada:
//   4539 1488 0343 6467  -> **** **** **** 6467
//   5162 3001 9925       -> **** **** 9925
//   1234                 -> 1234
//
// Dicas:
// 1. Primeiro conte os dígitos da string inteira (isdigit). Depois copie
//    caractere a caractere, contando de novo: o dígito número k (a partir
//    de 0) vira '*' se k < total - 4.
// 2. malloc(strlen(num) + 1) e não esqueça o '\0' no fim da cópia.
// 3. Quem chama recebe o bloco e é quem faz o free.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    const char *cartoes[3] = {"4539 1488 0343 6467", "5162 3001 9925", "1234"};
    (void) cartoes; // apague esta linha quando escrever

    return 0;
}
