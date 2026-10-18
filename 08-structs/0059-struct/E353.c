// 0059 · Struct
// Exercício E353 · ★★★
//
// Crie uma struct data (dia, mes, ano) e escreva:
//
//   - struct data dia_seguinte(struct data d): devolve a data do dia seguinte,
//     tratando fim de mês, fim de ano e fevereiro em ano bissexto;
//   - int comparar(struct data a, struct data b): devolve -1 se a vem antes,
//     0 se são iguais e 1 se a vem depois.
//
// Teste com as datas abaixo:
//
//   Saída esperada:
//   28/02/2024 -> 29/02/2024
//   28/02/2025 -> 01/03/2025
//   31/12/2025 -> 01/01/2026
//   15/03/2025 vem antes de 02/11/2025
//
// Dicas:
// 1. Bissexto: divisível por 4 e não por 100, ou divisível por 400.
// 2. Uma função int dias_no_mes(int mes, int ano) com um vetor
//    {31, 28, 31, 30, ...} simplifica tudo; some 1 em fevereiro bissexto.
// 3. Uma função pode devolver struct: crie uma cópia, mude e return.
// 4. Para comparar, olhe o ano; se empatar, o mês; se empatar, o dia.
// 5. Resposta esperada: a saída acima (%02d mostra o zero à esquerda).
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
