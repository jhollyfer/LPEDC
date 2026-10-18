// 0133 · Algoritmos gulosos
// Exercício E793 · ★☆☆
//
// O caixa eletrônico tem notas de R$ 200, 100, 50, 20, 10, 5 e 2, e entrega
// o saque com o menor número de notas, pelo guloso: a maior nota que cabe,
// de novo e de novo. Escreva a função void saque(int valor), que mostra
// quantas notas de cada valor saem (só as que aparecem) e o total, e chame
// para R$ 380 e R$ 1270.
//
//   Saída esperada:
//   Saque de R$ 380:
//     1 de R$ 200
//     1 de R$ 100
//     1 de R$ 50
//     1 de R$ 20
//     1 de R$ 10
//     total: 5 notas
//   Saque de R$ 1270:
//     6 de R$ 200
//     1 de R$ 50
//     1 de R$ 20
//     total: 8 notas
//
// Dicas:
// 1. Guarde as notas num vetor em ordem decrescente e percorra com um for.
// 2. Para cada nota, um while tira a nota enquanto ela couber no valor,
//    contando quantas saíram.
// 3. Resposta esperada: a saída acima. (Tente um saque de R$ 8 depois: o
//    guloso dá uma nota de 5, uma de 2 e trava com R$ 1 sobrando, embora
//    quatro notas de 2 resolvam. Sem a nota de 1, o guloso nem sempre acha
//    uma resposta que existe.)
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
