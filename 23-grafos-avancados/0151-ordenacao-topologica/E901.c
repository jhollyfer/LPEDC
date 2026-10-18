// 0151 · Ordenação topológica
// Exercício E901 · ★☆☆
//
// A receita de bolo tem oito passos (índices 0 a 7): bater os ovos,
// desenformar, despejar na forma, misturar os secos, juntar tudo,
// preaquecer o forno, untar a forma e assar. As regras "a antes de b" são:
//
//   bater os ovos -> juntar tudo       misturar os secos -> juntar tudo
//   juntar tudo -> despejar na forma   untar a forma -> despejar na forma
//   despejar na forma -> assar         preaquecer o forno -> assar
//   assar -> desenformar
//
// Escreva do zero o algoritmo de Kahn (matriz, grau de entrada, fila) e
// mostre os passos numerados. Examine os vizinhos em ordem de índice.
//
//   Saída esperada:
//   1. bater os ovos
//   2. misturar os secos
//   3. preaquecer o forno
//   4. untar a forma
//   5. juntar tudo
//   6. despejar na forma
//   7. assar
//   8. desenformar
//
// Dicas:
// 1. O grau de entrada de b soma a coluna b da matriz: grau[b] += antes[a][b].
// 2. Comece a fila com todos de grau 0, em ordem de índice: bater os ovos,
//    misturar os secos, preaquecer o forno e untar a forma.
// 3. Resposta esperada: a saída acima. "Juntar tudo" só fica livre depois
//    dos ovos e dos secos, e entra na fila atrás dos quatro primeiros.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
