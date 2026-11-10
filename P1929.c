// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1929 · ★★★ · A balança de dois pratos
//
// O feirante tem uma balança de dois pratos e só três pesos: 1, 3 e 9 kg.
// Cada peso pode ficar no prato oposto ao da mercadoria (soma), no MESMO
// prato da mercadoria (subtrai) ou fora da balança. Assim, 2 kg de farinha
// se pesam com o 3 de um lado e o 1 junto da farinha: 2 = 3 - 1. Escreva
// do zero um gerador de todas as 3^3 = 27 escolhas (permutação com
// repetição de -1, 0 e +1 em cada peso) e, para cada peso de 1 a 13 kg,
// mostre a primeira escolha que dá certo, no formato da saída.
//
//   Saída esperada:
//    1 = 1
//    2 = 3 - 1
//    3 = 3
//    4 = 3 + 1
//    5 = 9 - 3 - 1
//    6 = 9 - 3
//    7 = 9 - 3 + 1
//    8 = 9 - 1
//    9 = 9
//   10 = 9 + 1
//   11 = 9 + 3 - 1
//   12 = 9 + 3
//   13 = 9 + 3 + 1
//
// Dicas:
// 1. gera(i, soma) tenta lado[i] = +1, -1 e 0, nesta ordem; quando i == 3
//    e a soma é positiva e ainda sem resposta, guarde as escolhas em
//    resp[soma][].
// 2. Para mostrar, percorra os pesos do maior (9) para o menor: o primeiro
//    +1 sai sem sinal e os outros com " + " ou " - ".
// 3. Resposta esperada: todos os pesos de 1 a 13 kg saem (é a base 3
//    balanceada). Por exemplo, 5 = 9 - 3 - 1 e 13 = 9 + 3 + 1.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
