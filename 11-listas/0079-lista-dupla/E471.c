// 0079 · Lista dupla
// Exercício E471 · ★★☆
//
// Um palíndromo se lê igual nos dois sentidos. Com uma lista dupla dá para
// conferir sem vetor nenhum: um ponteiro sai do início, outro sai do fim, e
// os dois andam em direção ao meio comparando. Guarde cada letra como int
// (char é número) e escreva:
//
//   void monta(Lista *l, const char *palavra)   uma letra por nó, no fim
//   bool eh_palindromo(const Lista *l)
//
// Teste com "radar", "trem", "arara" e "ab".
//
//   Saída esperada:
//   radar: sim
//   trem: não
//   arara: sim
//   ab: não
//
// Dicas:
// 1. monta: for (int i = 0; palavra[i] != '\0'; i++) lista_insere_fim(...).
// 2. eh_palindromo: e = l->inicio, d = l->fim, e repita l->tamanho / 2
//    vezes: compare, e = e->prox, d = d->ant.
// 3. Use a mesma Lista para todas as palavras, com lista_libera entre uma e
//    outra (ela deixa a lista vazia de novo).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>
#include "lista.h"

int main(void) {

    return 0;
}
