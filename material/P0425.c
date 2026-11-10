// Lista · Módulo 04 · Funções e modularização
// Exercício P0425 · ★★★ · O prazo de 10 dias úteis
//
// O protocolo foi aberto numa quinta, 19/11/2026, e o prazo é de 10 dias úteis,
// contados a partir do dia seguinte. Não contam sábados, domingos nem os
// feriados nacionais fixos (01/01, 21/04, 01/05, 07/09, 12/10, 02/11, 15/11,
// 20/11 e 25/12). Sem vetor e sem struct, guarde cada data num int no formato
// aaaammdd (20261119). Escreva "int proximo_dia(int data)", "int
// dia_semana(int data)" (0 = domingo), "bool feriado(int data)" e mostre o
// prazo final e quantos dias foram pulados:
//
//   Saída esperada:
//   Protocolo: 19/11/2026
//   Prazo final: 04/12/2026
//   Pulados: 4 dia(s) de fim de semana e 1 feriado(s)
//
// Dicas:
// 1. Para desmontar: ano = data / 10000, mes = data / 100 % 100, dia = data %
//    100. Para montar: ano * 10000 + mes * 100 + dia.
// 2. proximo_dia precisa de "int dias_no_mes(int mes, int ano)", com
//    bissexto. Quando o dia passa do fim do mês, vira 1 e o mês avança (e o
//    ano, em dezembro).
// 3. Para o dia da semana: a = (14 − mês) / 12, y = ano − a, m = mês + 12a − 2
//    e (dia + y + y/4 − y/100 + y/400 + 31m/12) % 7.
// 4. O feriado só olha mes * 100 + dia: 1120 é 20/11.
// 5. Resposta esperada: Prazo final: 04/12/2026; 4 dias de fim de semana e 1
//    feriado.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
