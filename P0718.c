// Lista · Módulo 07 · Memória dinâmica
// Exercício P0718 · ★★☆ · Cópia rasa e cópia profunda
//
// A agenda da semana de um consultório é uma matriz dinâmica 2x3 (linhas:
// manhã e tarde; colunas: seg, ter, qua) com o número de consultas. Faça
// DUAS cópias dela:
// - rasa: um vetor novo de 2 ponteiros que recebe os MESMOS endereços das
//   linhas (m_rasa[i] = m[i]);
// - profunda: linhas novas, com os valores copiados.
//
// Depois mude m[0][1] (terça de manhã) de 4 para 9 e mostre as três. Mostre
// também se a linha 0 de cada cópia mora no mesmo endereço que a de m.
// Cuidado na hora de liberar: as linhas da rasa são as de m.
//
//   Saída esperada:
//   Original: manhã 3 9 2 | tarde 5 1 6
//   Rasa:     manhã 3 9 2 | tarde 5 1 6
//   Profunda: manhã 3 4 2 | tarde 5 1 6
//   Linha 0 da rasa é a de m? sim
//   Linha 0 da profunda é a de m? não
//
// Dicas:
// 1. Na rasa, só o vetor de ponteiros é novo: um malloc de 2 ponteiros e
//    um for com m_rasa[i] = m[i].
// 2. Na profunda, um malloc por linha e um for copiando os valores.
// 3. Liberar: as linhas de m e o vetor de m; o vetor da rasa (só ele!); as
//    linhas e o vetor da profunda. Liberar as linhas da rasa seria free
//    duplo.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
