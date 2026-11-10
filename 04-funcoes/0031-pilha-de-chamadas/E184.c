// 0031 · A pilha de chamadas
// Exercício E184 · ★★☆
//
// Cada quadro da pilha tem as suas variáveis, mesmo com nomes iguais. Escreva:
//
//   int dobro_mais_um(int n)  r = n * 2; n = r + 1; devolve n
//   int processa(int n)       r = dobro_mais_um(n); devolve r + n
//   main                      n = 5; r = processa(n)
//
// Cada função mostra n e r como na saída (dobro_mais_um na entrada e na saída;
// processa antes e depois de devolver; main no fim).
//
//   Saída esperada:
//   dobro_mais_um entra: n = 5
//   dobro_mais_um sai: n = 11, r = 10
//   processa: n = 5, r = 11
//   processa devolve 16
//   main: n = 5, r = 16
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int dobro_mais_um(int n);
int processa(int n);

int main(void) {

    return 0;
}
