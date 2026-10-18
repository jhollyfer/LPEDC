// 0021 · Do-while
// Exercício E126 · ★★★
//
// O app da clínica pede a data da consulta em 2026. Escreva um programa que lê
// o mês (repete até ser de 1 a 12) e depois o dia (repete até ser válido
// PARA AQUELE MÊS; 2026 não é bissexto, então fevereiro tem 28 dias):
//
//   Mês: 13
//   Mês: 2
//   Dia (1 a 28): 30
//   Dia (1 a 28): 29
//   Dia (1 a 28): 28
//   Consulta em 28/02/2026
//
// Dicas:
// 1. São dois do-while, um depois do outro. Entre eles, descubra quantos dias
//    tem o mês (um switch com fall-through resolve: assunto 0018).
// 2. Meses de 30 dias: 4, 6, 9 e 11. Fevereiro: 28. Os outros: 31.
// 3. Resposta esperada: com 13, 2, 30, 29, 28 mostra "Consulta em
//    28/02/2026". Use %02d para o zero na frente. Com mês 4, o dia 31 é
//    recusado.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
