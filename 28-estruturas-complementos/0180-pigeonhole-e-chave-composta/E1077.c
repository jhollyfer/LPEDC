// 0180 · Pigeonhole e chave composta
// Exercício E1077 · ★★☆
//
// Teste a estabilidade de três ordenações do pombal.h. Monte 10 alunos com
// nomes a0 a a9, as notas 4, 8, 4, 2, 8, 4, 6, 2, 8, 6 e, no campo turma, a
// posição original (0 a 9). Escreva eh_estavel(v, n): depois de ordenar,
// entre vizinhos de nota igual, a posição original tem que crescer. Ordene
// uma cópia com pb_selecao, outra com pb_insercao e outra com pb_pigeonhole
// e mostre o veredito e o resultado de cada uma.
//
//   Saída esperada:
//   seleção:    não estável | a3(2) a7(2) a2(4) a0(4) a5(4) a6(6) a9(6) a1(8) a8(8) a4(8)
//   inserção:   estável     | a3(2) a7(2) a0(4) a2(4) a5(4) a6(6) a9(6) a1(8) a4(8) a8(8)
//   pigeonhole: estável     | a3(2) a7(2) a0(4) a2(4) a5(4) a6(6) a9(6) a1(8) a4(8) a8(8)
//
// Dicas:
// 1. Escreva prepara(v, n), que preenche o vetor (snprintf para o nome), e
//    chame antes de cada ordenação.
// 2. Basta comparar vizinhos: se v[i].nota == v[i-1].nota e v[i].turma <
//    v[i-1].turma, não é estável.
// 3. Resposta esperada: a saída acima. Um teste só prova a instabilidade;
//    passar no teste não prova que um método é estável.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include "pombal.h"

int main(void) {

    return 0;
}
