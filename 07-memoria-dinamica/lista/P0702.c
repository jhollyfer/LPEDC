// Lista · Módulo 07 · Memória dinâmica
// Exercício P0702 · ★☆☆ · Juntar nome e sobrenome no heap
//
// Escreva
//
//   char *juntar(const char *a, const char *sep, const char *b, size_t *bytes);
//
// que devolve uma string NOVA no heap com a, sep e b em sequência, do tamanho
// exato (nem um byte a mais), e guarda em *bytes quanto pediu ao malloc. Junte
// "Francisca" e "Pereira" com " " e
// "Manaus" e "AM" com " - ". Mostre cada resultado, o strlen e quantos bytes
// foram pedidos ao malloc, e libere as duas:
//
//   Saída esperada:
//   "Francisca Pereira": strlen 17, malloc de 18 bytes
//   "Manaus - AM": strlen 11, malloc de 12 bytes
//
// Dicas:
// 1. Os bytes: strlen(a) + strlen(sep) + strlen(b) + 1. O + 1 é do '\0'.
// 2. Depois do malloc: strcpy(novo, a); strcat(novo, sep); strcat(novo, b);
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
