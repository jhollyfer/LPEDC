// 0041 · Juntando tudo: o caixa da lanchonete
// Exercício E243 · ★★☆
//
// O app de hábitos mostra "dia 291 de 365". Escreva três funções que se
// apoiam umas nas outras:
//
//   bool eh_bissexto(int ano)
//   int dias_no_mes(int mes, int ano)          usa eh_bissexto para fevereiro
//   int dia_do_ano(int dia, int mes, int ano)  soma os meses anteriores
//
//   Saída esperada:
//   18/10/2026: dia 291 de 365
//   01/03/2024: dia 61 de 366
//   31/12/2024: dia 366 de 366
//   29/02/2023: data inválida
//
// Dicas:
// 1. dias_no_mes com switch: 4, 6, 9 e 11 têm 30; 2 tem 28 ou 29; o resto, 31.
// 2. dia_do_ano: um for de 1 até mes - 1 somando dias_no_mes, mais o dia.
//    Para "data inválida", confira dia <= dias_no_mes(mes, ano) antes.
// 3. Resposta esperada: 291, 61, 366 e inválida (2023 não é bissexto).
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
