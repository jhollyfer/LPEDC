// 0119 · Shell sort
// Exercício E714 · ★★★
//
// Uma INVERSÃO é um par de posições i < j com v[i] > v[j]: um par fora de
// ordem. Vetor ordenado tem 0 inversões. Estenda o programa abaixo para
// medir o que cada rodada do shell sort faz:
//
// a) escreva long inversoes(const int v[], int n) (dois laços, O(n²));
//
// b) conte os movimentos (v[j] = v[j - h]) de cada rodada;
//
// c) depois de cada rodada, mostre as inversões que sobraram e os
// movimentos da rodada; no fim, o total de movimentos comparado com as
// inversões do início.
//
//   Saída esperada:
//   início:  9775 inversões
//   h = 121:  7359 inversões,   12 movimentos
//   h =  40:  2602 inversões,  131 movimentos
//   h =  13:  1004 inversões,  172 movimentos
//   h =   4:   288 inversões,  234 movimentos
//   h =   1:     0 inversões,  288 movimentos
//   total: 837 movimentos (o insertion sort faria 9775)
//
// Repare na primeira rodada: 12 movimentos desfizeram 2416 inversões. E na
// última: os movimentos são exatamente as inversões que sobraram.
//
// Dicas:
// 1. Guarde as inversões do início numa variável: o insertion sort comum
//    faz um movimento por inversão, então esse é o custo dele.
// 2. Um pulo de h casas pode desfazer várias inversões de uma vez: todos os
//    elementos que ficavam entre as duas posições também entram na conta.
// 3. Formatos: "h = %3d: %5ld inversões, %4ld movimentos".
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (estenda o programa):

#include <stdio.h>

int main(void) {
    int v[200];
    int n = 200;
    for (int i = 0; i < n; i++) {
        v[i] = (i * 73 + 11) % 200; // os números de 0 a 199, embaralhados
    }

    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }
    for (; h >= 1; h /= 3) {
        for (int i = h; i < n; i++) {
            int x = v[i];
            int j = i;
            while (j >= h && v[j - h] > x) {
                v[j] = v[j - h];
                j -= h;
            }
            v[j] = x;
        }
    }
    return 0;
}
