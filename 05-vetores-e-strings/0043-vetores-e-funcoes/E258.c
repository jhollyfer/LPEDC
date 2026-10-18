// 0043 · Vetores e funções
// Exercício E258 · ★★★
//
// Uma playlist guarda os números das faixas: 11 22 33 44 55. Escreva:
//
//   void mostrar(const int v[], int n);
//   void inverter(int v[], int n);    inverte NO PRÓPRIO vetor, sem criar
//                                     outro: troca o 1º com o último, o 2º
//                                     com o penúltimo...
//   void rotacionar(int v[], int n);  a 1ª faixa vai para o fim e as outras
//                                     andam uma casa para a esquerda
//
// No main: mostre a playlist, inverta e mostre, depois rotacione DUAS vezes
// e mostre.
//
//   Saída esperada:
//   11 22 33 44 55
//   55 44 33 22 11
//   33 22 11 55 44
//
// Dicas:
// 1. Trocar duas gavetas pede uma variável auxiliar (aux = a; a = b; b = aux).
// 2. Em inverter, o laço vai só até a metade: i < n / 2, trocando v[i] com
//    v[n - 1 - i]. Se for até n, você inverte duas vezes e volta ao começo!
// 3. Em rotacionar, guarde v[0] antes de deslizar as outras e ponha no fim.
// 4. Teste com n ímpar e par: a do meio, quando existe, fica no lugar.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
