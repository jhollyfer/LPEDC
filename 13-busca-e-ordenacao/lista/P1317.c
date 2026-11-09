// Lista · Módulo 13 · Busca e ordenação
// Exercício P1317 · ★★☆ · O merge sort mostrando cada intercalação
//
// Ordene os tempos de espera 38, 27, 43, 3, 9, 82, 10 (em minutos) com merge
// sort, dividindo em q = (p + r) / 2. Instrumente a intercalação: no fim de
// cada intercala(p, q, r), mostre o trecho v[p..r] já intercalado. Use um
// vetor auxiliar global int aux[7].
//
//   Saída esperada:
//   intercala [0..1]: 27 38
//   intercala [2..3]: 3 43
//   intercala [0..3]: 3 27 38 43
//   intercala [4..5]: 9 82
//   intercala [4..6]: 9 10 82
//   intercala [0..6]: 3 9 10 27 38 43 82
//
// Dicas:
// 1. merge_sort(p, r): se p < r, ordena [p..q], ordena [q+1..r] e intercala.
// 2. A ordem das linhas é a ordem em que as chamadas TERMINAM: a metade
//    esquerda inteira antes da direita. Repare que o trecho [6..6] (só o 10)
//    não intercala nada.
// 3. São n - 1 = 6 intercalações para 7 elementos.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int v[] = {38, 27, 43, 3, 9, 82, 10};
int aux[7];

int main(void) {

    return 0;
}
