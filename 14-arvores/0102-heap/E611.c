// 0102 · Heap e fila de prioridade
// Exercício E611 · ★★★
//
// O professor quer o pódio: as 3 maiores notas da turma (de 0 a 100). Em vez
// de ordenar o vetor inteiro, use um heap de MÍNIMO com espaço para 3: ele
// guarda as 3 maiores vistas até agora, com a menor delas na raiz. Para cada
// nota nova: se o heap tem menos de 3, insira; senão, se a nota for maior
// que a raiz, a raiz sai e a nota entra. Escreva tudo do zero (o heap.h é
// de máximo; aqui você precisa do contrário).
//
//   Notas: 72 95 60 88 91 45 98 83 77 90 66 85
//
//   Saída esperada:
//   Pódio: 98 95 91
//
// Dicas:
// 1. Um min-heap é o heap do texto com os sinais das comparações trocados:
//    sobe enquanto for MENOR que o pai; desce trocando com o MENOR filho.
// 2. "A raiz sai e a nota entra" pode ser feito numa operação só:
//    v[0] = nota e depois desce a partir do 0.
// 3. Resposta esperada: Pódio: 98 95 91. Para imprimir do maior para o
//    menor, tire os 3 do min-heap (saem 91, 95, 98) guardando num vetor e
//    mostre de trás para frente. Com n notas e pódio de k, o custo é
//    O(n log k), e não O(n log n).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
