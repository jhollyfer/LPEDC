// Lista · Módulo 02 · Decisões
// Exercício P0221 · ★★★ · Que dia do ano é a prova
//
// A prova do PPGI é em 27/11/2026. Escreva um programa que descubra que dia do
// ano é essa data (1º de janeiro é o dia 1) com um switch no mês que usa o
// fall-through de propósito: comece no case do mês anterior ao da data e vá
// somando os dias de cada mês até janeiro. Mostre também quantos dias faltam
// para o ano acabar:
//
//   Saída esperada:
//   27/11/2026 é o dia 331 do ano
//   Faltam 34 dias para o ano acabar
//
// Dicas:
// 1. Comece com total = dia. Faça switch (mes - 1): case 11: total += 30;
//    case 10: total += 31; ... case 1: total += 31; sem break, com o
//    comentário // fall through para o gcc não avisar.
// 2. Fevereiro soma 28, ou 29 se o ano for bissexto (ano % 4 == 0 && ano % 100
//    != 0) || ano % 400 == 0.
// 3. Faltam (dias do ano) - total, e o ano tem 365 ou 366 dias.
// 4. Resposta esperada: dia 331, faltam 34 dias.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
