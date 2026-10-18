// 0054 · malloc e free
// Exercício E319 · ★☆☆
//
// Escreva um programa que pergunte quantos dias de medição houve, aloque com
// malloc um vetor de int desse tamanho, leia as temperaturas e mostre a maior
// e a menor. Confira o NULL e libere o bloco no fim.
//
//   Exemplo de uso:
//   Quantos dias? 5
//   Temperatura 1: 31
//   Temperatura 2: 28
//   Temperatura 3: 33
//   Temperatura 4: 29
//   Temperatura 5: 30
//   Máxima: 33
//   Mínima: 28
//
// Para testar: printf '5\n31 28 33 29 30\n' | ~/LPEDC/rodar <este arquivo>
//
// Dicas:
// 1. int *temps = malloc(dias * sizeof(int)); e depois if (temps == NULL).
// 2. Comece maior e menor com temps[0] (padrão do assunto 0025).
// 3. Resposta esperada: Máxima: 33 e Mínima: 28, e nenhum aviso do
//    AddressSanitizer no fim (sinal de que o free está lá).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
