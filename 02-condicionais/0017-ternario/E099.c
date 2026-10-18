// 0017 · Ternário: condição ? a : b
// Exercício E099 · ★★☆
//
// Leia dois inteiros, a e b, e mostre quatro linhas, cada resultado saído
// de UM ternário (nada de if): a distância entre os dois (o maior menos o
// menor); se a soma é "par" ou "ímpar"; o menor dos dois; e se a é
// divisível por b. Com b igual a 0, a última linha mostra "não dá para
// dividir por zero", sem calcular o resto.
//
//   Dois números: 2 5
//   Distância: 3
//   Soma: ímpar
//   Menor: 2
//   2 por 5: não divisível
//
// Dicas:
// 1. Distância: a > b ? a - b : b - a. Soma: (a + b) % 2 ? "ímpar" : "par".
// 2. Na última linha, um ternário dentro do "senão" do outro:
//    b == 0 ? "não dá para dividir por zero" : a % b == 0 ? ... : ...
//    Como o ternário só calcula um lado, a % 0 nunca acontece.
// 3. Resposta esperada: 2 5 → 3, ímpar, 2, não divisível;
//    12 4 → 8, par, 4, divisível; 7 0 → 7, ímpar, 0,
//    não dá para dividir por zero.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
