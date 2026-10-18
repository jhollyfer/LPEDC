// 0060 · Typedef
// Exercício E356 · ★☆☆
//
// Escreva um programa que crie três apelidos:
//
//   typedef int Metros;
//   typedef int Segundos;
//   typedef char Nome[12];
//
// Declare distancia (Metros) com 100, tempo (Segundos) com 20 e atleta
// (Nome) com "Rayssa". Mostre o nome, a velocidade, o sizeof(Nome) e o strlen
// do nome. Por último, mostre distancia + tempo: somar metros com segundos
// não faz sentido, e mesmo assim o programa tem que compilar sem aviso.
//
//   Saída esperada:
//   Atleta: Rayssa
//   Velocidade: 5 m/s
//   sizeof(Nome) = 12, strlen = 6
//   distancia + tempo = 120
//
// Dicas:
// 1. typedef não cria tipo novo: Metros e Segundos são int, e %d mostra os
//    dois.
// 2. Nome é um apelido para "vetor de 12 char": Nome atleta = "Rayssa";
//    funciona como char atleta[12] = "Rayssa";
// 3. sizeof e strlen devolvem size_t: mostre com %zu.
// 4. Resposta esperada: a saída acima. O vetor tem 12 bytes; o texto, 6
//    letras.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
