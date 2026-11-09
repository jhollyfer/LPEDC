// Lista · Módulo 06 · Ponteiros
// Exercício P0621 · ★★★ · O ranking do processo seletivo
//
// No resultado de um processo seletivo, cada candidato é uma linha de uma
// matriz de int com {inscrição, nota (de 0 a 100), idade}:
//
//   int cand[7][3] = {{1043, 82, 29}, {1007, 91, 33}, {1120, 82, 41},
//                     {1088, 75, 26}, {1015, 91, 33}, {1102, 82, 41},
//                     {1061, 68, 52}};
//
// Ordene com qsort, e cada ELEMENTO é uma linha inteira (int[3]). A ordem é:
// nota maior primeiro; no empate, o mais velho primeiro (como no edital do
// mestrado); persistindo o empate, a menor inscrição. Mostre a classificação:
//
//   Saída esperada:
//   Pos Inscr Nota Idade
//    1º  1007   91    33
//    2º  1015   91    33
//    3º  1102   82    41
//    4º  1120   82    41
//    5º  1043   82    29
//    6º  1088   75    26
//    7º  1061   68    52
//
// Dicas:
// 1. qsort(cand, 7, sizeof cand[0], compara); sizeof cand[0] é 12 bytes:
//    o qsort move a linha inteira a cada troca.
// 2. Na comparação, o void * aponta para o primeiro int da linha:
//    const int *x = a, *y = b; e x[1] é a nota, x[2] a idade.
// 3. Compare um critério de cada vez: if (x[1] != y[1]) return y[1] - x[1];
//    depois a idade (decrescente), depois a inscrição (crescente).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int cand[7][3] = {{1043, 82, 29}, {1007, 91, 33}, {1120, 82, 41},
                      {1088, 75, 26}, {1015, 91, 33}, {1102, 82, 41},
                      {1061, 68, 52}};
    (void) cand; // apague esta linha quando escrever

    return 0;
}
