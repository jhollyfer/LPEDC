// 0043 · Juntando tudo
// Exercício E258 · ★★★
//
// Compressão RLE (run-length encoding): cada sequência de letras repetidas
// vira a letra seguida de quantas vezes ela aparece. "aaabccdddd" vira
// "a3b1c2d4". Para simplificar, a contagem é sempre um dígito só: uma
// sequência de mais de 9 vira pedaços de 9 ("zzzzzzzzzzzz", 12 z, vira
// "z9z3").
//
// Leia uma linha com fgets, tire o '\n', comprima numa string saida[] e
// mostre o resultado e os tamanhos. Se a versão comprimida não for menor,
// avise que não compensa.
//
//   Entrada:
//   aaabccdddd
//
//   Saída esperada:
//   a3b1c2d4 (10 -> 8)
//
//   Entrada:
//   abc
//
//   Saída esperada:
//   a1b1c1 (3 -> 6): não compensa
//
//   Entrada:
//   zzzzzzzzzzzz
//
//   Saída esperada:
//   z9z3 (12 -> 4)
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define TAM_TEXTO 100

int main(void) {

    return 0;
}
