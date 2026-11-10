// 0171 · Com sinal e sem sinal
// Exercício E1023 · ★★☆
//
// Este laço, que deveria mostrar a fila de trás para a frente, nunca
// termina (e o gcc avisa que "i >= 0" é sempre verdadeiro):
//
//   for (size_t i = n - 1; i >= 0; i--) printf(" %s", fila[i]);
//
// Escreva, com índices size_t que descem sem cair do zero:
//
//   - void mostrar_ao_contrario(const char *fila[], size_t n): mostra os
//     nomes do último ao primeiro, ou "(nada)" se n for 0;
//   - size_t ultimo_par(const int *v, size_t n): procura de trás para a
//     frente e devolve o índice do último número par, ou n se não houver.
//
// Teste com a fila {"Ana", "Bia", "Caio"}, com uma fila vazia, e com os
// vetores {3, 8, 5, 4, 7} e {1, 3}.
//
//   Saída esperada:
//   fila: Caio Bia Ana
//   fila vazia: (nada)
//   ultimo par em {3, 8, 5, 4, 7}: indice 3
//   ultimo par em {1, 3}: nenhum
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
