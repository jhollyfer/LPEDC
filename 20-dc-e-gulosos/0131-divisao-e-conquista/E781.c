// 0131 · Divisão e conquista
// Exercício E781 · ★☆☆
//
// A barraca de pastel anotou as vendas de 8 dias, em reais:
//
//   320 415 280 510 390 605 720 460
//
// Escreva a função int soma(const int v[], int ini, int fim), que soma
// v[ini..fim] por divisão e conquista: se o pedaço tem um elemento só, a
// soma é ele; senão, divida ao meio, some cada metade com a própria função e
// junte as duas respostas. Conte as chamadas numa variável global e mostre:
//
//   Saída esperada:
//   Total: R$ 3700
//   Chamadas: 15
//
// Dicas:
// 1. O meio de ini e fim é ini + (fim - ini) / 2. A metade esquerda vai de
//    ini a meio; a direita, de meio + 1 a fim.
// 2. Incremente o contador logo na primeira linha da função, antes do if.
// 3. Resposta esperada: a saída acima. Com n elementos são sempre 2n - 1
//    chamadas: n folhas (os dias) e n - 1 junções. O laço simples faria o
//    mesmo trabalho; aqui o objetivo é treinar o formato da técnica.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
