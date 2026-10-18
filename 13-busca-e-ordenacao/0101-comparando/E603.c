// 0101 · Comparando: estabilidade, custo e qsort
// Exercício E603 · ★★☆
//
// A playlist tem as bandas const char *bandas[] = {"Skank", "Titas",
// "Legiao", "Raimundos", "Pitty", "Cazuza"} (sem acentos, para o strcmp não
// se perder). Ordene com qsort duas vezes e mostre cada resultado numa linha:
//
//   1) em ordem alfabética;
//   2) do nome mais curto para o mais comprido; empatou no tamanho, ordem
//      alfabética.
//
//   Saída esperada:
//   Cazuza Legiao Pitty Raimundos Skank Titas
//   Pitty Skank Titas Cazuza Legiao Raimundos
//
// Dicas:
// 1. Cada elemento do vetor é um const char *. O qsort passa para a compara
//    o ENDEREÇO do elemento, ou seja, um ponteiro para ponteiro.
// 2. Leia assim: const char *x = *(const char *const *) a;
// 3. O erro clássico é fazer strcmp(a, b) direto: compara os bytes dos
//    ponteiros, não as letras.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
