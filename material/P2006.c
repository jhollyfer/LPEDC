// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2006 · ★☆☆ · O barco de Parintins
//
// Um barco sai de Manaus para Parintins com 500 kg livres no porão. O dono
// pode levar qualquer quantidade (dá para fracionar) de cinco produtos:
//
//   produto     kg disponíveis   valor total (R$)
//   castanha         200              3000
//   farinha          300              1500
//   guaraná          100              2500
//   pirarucu         150              4200
//   cupuaçu          250              2000
//
// Escreva do zero a mochila fracionária: um struct Produto com nome, kg e
// valor; ordene com qsort pela razão valor/kg, da maior para a menor; leve
// inteiro enquanto couber e, no primeiro que não cabe, só a parte que
// cabe. Mostre o que vai e o valor total.
//
//   Saída esperada:
//   pirarucu: 150 kg, R$ 4200.00
//   guaraná: 100 kg, R$ 2500.00
//   castanha: 200 kg, R$ 3000.00
//   cupuaçu: 50 kg, R$ 400.00
//   Total: R$ 10100.00
//
// Dicas:
// 1. As razões são 15, 5, 25, 28 e 8 R$/kg.
// 2. Na comparação do qsort, compare as razões com < e > e devolva -1, 0
//    ou 1; subtrair doubles e converter para int estraga a ordem.
// 3. Resposta esperada: pirarucu, guaraná e castanha inteiros (450 kg) e
//    50 kg de cupuaçu: R$ 10100.00.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
