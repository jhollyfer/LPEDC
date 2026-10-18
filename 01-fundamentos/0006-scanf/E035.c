// 0006 · scanf
// Exercício E035 · ★★★
//
// Escreva um programa que comece com int a = 0, b = 0;, leia os dois com
// UM scanf("%d %d", &a, &b), guarde o retorno e mostre "lidos=? a=? b=?".
// Antes de testar, preveja o resultado para cada entrada:
//
//   printf '7 9\n'   | ~/LPEDC/rodar E035.c
//   printf '7 x\n'   | ~/LPEDC/rodar E035.c
//   printf 'x 7\n'   | ~/LPEDC/rodar E035.c
//   printf '7\n\n9\n' | ~/LPEDC/rodar E035.c
//   printf ''        | ~/LPEDC/rodar E035.c
//
// Dicas:
// 1. O retorno conta só os itens guardados com sucesso, na ordem. No primeiro
//    que falha, o scanf para.
// 2. %d pula espaços e Enters, quantos forem.
// 3. Entrada vazia é fim de arquivo: o scanf devolve EOF, que vale -1.
// 4. Resposta esperada: "lidos=2 a=7 b=9"; "lidos=1 a=7 b=0";
//    "lidos=0 a=0 b=0"; "lidos=2 a=7 b=9" (os Enters são pulados);
//    "lidos=-1 a=0 b=0".
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
