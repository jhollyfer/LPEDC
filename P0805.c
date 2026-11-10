// Lista · Módulo 08 · Tipos compostos
// Exercício P0805 · ★☆☆ · Quantos dias tem o mês
//
// Crie typedef enum { JAN = 1, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT,
// NOV, DEZ } Mes; e escreva:
//
//   bool bissexto(int ano);
//   int dias_no_mes(Mes m, int ano);
//
// Use um switch no dias_no_mes (fevereiro depende do ano). Mostre os dias de
// fevereiro em 2024, 2026, 1900 e 2000, e o total de dias de 2026 somando os
// 12 meses num laço que anda pelo enum:
//
//   Saída esperada:
//   fev/2024: 29 dias
//   fev/2026: 28 dias
//   fev/1900: 28 dias
//   fev/2000: 29 dias
//   2026: 365 dias
//
// Dicas:
// 1. Bissexto: divisível por 4 e não por 100, ou divisível por 400. Por
//    isso 1900 não é e 2000 é.
// 2. No switch, vários case podem levar ao mesmo return: case ABR: case
//    JUN: case SET: case NOV: return 30;
// 3. Um enum é um int: for (Mes m = JAN; m <= DEZ; m++) funciona.
// 4. Para o nome do mês, um vetor de strings indexado por m - 1.
// 5. Resposta esperada: a saída acima (2026 tem 365 dias).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

int main(void) {

    return 0;
}
