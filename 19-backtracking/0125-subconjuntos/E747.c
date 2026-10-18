// 0125 · Subconjuntos
// Exercício E747 · ★★☆
//
// Você tem R$ 30 de crédito na barraca da feira e quer gastar o valor exato.
// Os produtos são:
//
//   queijo 12   café 7   carne 18   pão 5   frutas 9   frango 14
//
// Escreva um programa que teste TODOS os 64 subconjuntos (pelos bits, com
// m de 0 a 63, bit 0 = queijo) e mostre os que somam exatamente 30, um por
// linha, e no fim quantos são.
//
//   Saída esperada:
//   queijo carne
//   café carne pão
//   café frutas frango
//   3 combinações de 64
//
// Dicas:
// 1. Para cada m, some os preços dos itens cujo bit está ligado. Só depois
//    de somar decida se a linha aparece.
// 2. Guarde os nomes e os preços em dois vetores paralelos (ou num vetor de
//    structs, assunto 0061).
// 3. Repare que muitos subconjuntos passam de 30 logo nos primeiros itens e
//    mesmo assim são somados até o fim. No assunto 0127 você vai cortar
//    esse desperdício.
// 4. Resposta esperada: as 4 linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
