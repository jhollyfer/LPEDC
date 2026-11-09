// Lista · Módulo 01 · Fundamentos de C
// Exercício P0103 · ★☆☆ · Minutos do plano de celular
//
// A fatura do celular diz que você falou 437 minutos no mês. Complete o
// programa: troque os dois zeros pelas contas certas, usando só / e %, para
// mostrar o tempo em horas e minutos:
//
//   Saída esperada:
//   437 minutos = 7 h e 17 min
//
// Dicas:
// 1. Uma hora tem 60 minutos. A divisão inteira diz quantas horas cabem.
// 2. O resto da divisão (%) diz quantos minutos sobram.
// 3. Resposta esperada: 7 h e 17 min.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int total = 437;
    int horas = 0;    // troque o 0 pela conta das horas
    int minutos = 0;  // troque o 0 pela conta dos minutos

    printf("%d minutos = %d h e %d min\n", total, horas, minutos);
    return 0;
}
