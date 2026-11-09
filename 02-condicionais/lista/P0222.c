// Lista · Módulo 02 · Decisões
// Exercício P0222 · ★★★ · A data por extenso
//
// O sistema da secretaria quer a data por extenso, com o dia da semana. Escreva
// um programa que leia uma data no formato dd/mm/aaaa, confira se o scanf leu
// os três números e se o mês vai de 1 a 12, descubra o dia da semana com a
// fórmula (a = (14 − mês) / 12, y = ano − a, m = mês + 12a − 2, semana = (dia
// + y + y/4 − y/100 + y/400 + 31m/12) % 7, com 0 = domingo) e mostre tudo por
// extenso, com um switch para o mês e outro para o dia da semana:
//
//   Saída esperada:
//   Data (dd/mm/aaaa): 27/11/2026
//   27 de novembro de 2026, sexta-feira
//
// Dicas:
// 1. scanf("%d/%d/%d", &dia, &mes, &ano) devolve 3 quando deu tudo certo.
// 2. Cada switch só faz printf("janeiro"), printf("fevereiro")... e break.
// 3. Com 07/09/2026: 7 de setembro de 2026, segunda-feira.
// 4. Resposta esperada: 27 de novembro de 2026, sexta-feira.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
