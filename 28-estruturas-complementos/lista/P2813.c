// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2813 · ★★☆ · A lápide no meio do caminho
//
// Numa tabela de m = 7 com sondagem linear, cada posição tem um estado:
// LIVRE, OCUPADA ou LAPIDE. Escreva insere (reaproveita a primeira lápide do
// caminho), busca (para na LIVRE, passa reto pela LAPIDE) e remove (marca
// LAPIDE). Insira 10, 17, 24 e 5 (os três primeiros começam no 3), remova o
// 17, busque o 24, insira 31 e mostre a tabela depois de cada passo ("."
// livre, "x" lápide).
//
//   Saída esperada:
//   inseridos:   .  .  . 10 17 24  5
//   tira 17:     .  .  . 10  x 24  5
//   busca 24: posição 5
//   insere 31:   .  .  . 10 31 24  5
//
// Dicas:
// 1. Na inserção, guarde a posição da primeira lápide vista; se a chave não
//    estiver na tabela, use essa posição (ou a livre onde parou).
// 2. O 31 também começa no 3 e ocupa o lugar do 17 removido.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
