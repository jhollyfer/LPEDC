// 0039 · Módulos: .h, .c e compilação separada
// Exercício E230 · ★☆☆
//
// Use o módulo conversao.h, que está nesta pasta, para mostrar uma tabela de
// temperaturas de 0 °C a 40 °C, de 10 em 10. Não escreva nenhuma fórmula: use
// celsius_para_fahrenheit. No fim, mostre quantas conversões o módulo contou.
// O rodar compila o conversao.c junto, sozinho.
//
//   Saída esperada:
//   0 °C = 32.0 °F
//   10 °C = 50.0 °F
//   20 °C = 68.0 °F
//   30 °C = 86.0 °F
//   40 °C = 104.0 °F
//   Conversões: 5
//
// Dicas:
// 1. O include já está aí embaixo. Um for de 0 a 40, somando 10.
// 2. conversoes_feitas() devolve o contador que mora escondido no conversao.c.
// 3. Resposta esperada: a tabela acima e "Conversões: 5". À mão, o comando
//    seria: gcc -std=c17 -Wall -Wextra E230.c conversao.c -o tabela
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#include "conversao.h"

int main(void) {

    return 0;
}
