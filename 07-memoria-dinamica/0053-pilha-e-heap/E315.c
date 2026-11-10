// 0053 · Pilha e heap
// Exercício E315 · ★★☆
//
// No Linux, "ulimit -s" mostra o tamanho da pilha em KiB (em geral, 8192,
// ou seja, 8 MiB). Uma função recursiva guarda o histórico de preços de uma
// ação num vetor local: int historico[2000]; e chama a si mesma.
//
// Escreva um programa que calcule e mostre quantos bytes esse vetor ocupa em
// cada chamada e quantas chamadas, no máximo, cabem numa pilha de 8 MiB.
// Depois faça a mesma conta para o vetor double historico[2000]; e mostre
// também. Use sizeof para o tamanho de cada tipo e divisão inteira.
//
//   Saída esperada:
//   int: cada chamada usa pelo menos 8000 bytes
//   int: cabem no máximo 1048 chamadas
//   double: cada chamada usa pelo menos 16000 bytes
//   double: cabem no máximo 524 chamadas
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
