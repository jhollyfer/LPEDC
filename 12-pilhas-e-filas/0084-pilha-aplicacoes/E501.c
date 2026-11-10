// 0084 · Pilha na prática: parênteses e notação pós-fixa
// Exercício E501 · ★★☆
//
// Escreva void diagnostico(const char *s), que confere os parênteses (), [] e {}
// de s com uma pilha do pilha.h e diz onde está o problema. Empilhe a POSIÇÃO de
// cada abertura na string (o caractere é s[pos]); a primeira posição é 0. As
// mensagens possíveis estão na saída esperada: ok, fecha sem abrir, fechamento
// trocado (dizendo onde a abertura estava) e abertura sem fechar (dizendo
// quantas faltam e qual o de cima). No main, teste "[1, (2, 3)]", "{a: [1, 2}]",
// "f(x))" e "if (a[0] {".
//
//   Saída esperada:
//   [1, (2, 3)]: ok
//   {a: [1, 2}]: esperava ] e veio } na posição 9 (o [ abriu na posição 4)
//   f(x)): fecha sem abrir na posição 4
//   if (a[0] {: faltou fechar 2; o de cima é o { da posição 9
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "pilha.h"

int main(void) {

    return 0;
}
