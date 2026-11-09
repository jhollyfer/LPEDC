// Lista · Módulo 25 · Estruturas especiais
// Exercício P2522 · ★★★ · A skip list perfeita
//
// A skip list sorteia andares para, NA MÉDIA, ficar parecida com uma
// estrutura perfeita: metade dos nós com 2 andares ou mais, um quarto com
// 3 ou mais... Quando as chaves já chegam em ordem, dá para montar a
// versão perfeita sem moeda: o nó da posição i (contando de 1) tem
// 1 + (quantos zeros há no fim de i em binário) andares. Escreva do zero,
// com as chaves 10, 20, ..., 150 e no máximo 5 andares:
// - monte a lista numa passada, ligando cada nó no fim de cada andar dele
//   (guarde o último nó de cada andar);
// - mostre os andares;
// - busque cada chave contando as comparações (cada olhada em x->prox[k])
//   e mostre a média e o pior caso.
//
//   Saída esperada:
//   andar 4:
//   andar 3: 80
//   andar 2: 40 80 120
//   andar 1: 20 40 60 80 100 120 140
//   andar 0: 10 20 30 40 50 60 70 80 90 100 110 120 130 140 150
//   comparações: 4 5 5 6 5 6 6 7 4 5 5 6 4 5 4
//   média 5.13, pior 7
//
// Dicas:
// 1. Os andares saem assim: andares = 1; para t = i, enquanto t é par,
//    andares++ e t /= 2.
// 2. É uma busca binária disfarçada: o nó 80 está no meio, 40 e 120 nos
//    quartos, e assim por diante.
// 3. Resposta esperada: o andar 3 só tem o 80; média 5.13, pior 7.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
