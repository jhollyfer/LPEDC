// Lista · Módulo 08 · Tipos compostos
// Exercício P0802 · ★☆☆ · A que horas o voo chega
//
// Crie typedef struct { int h, m; } Horario; e escreva
//
//   Horario somar(Horario ini, int minutos, int *dias);
//
// que devolve o horário depois de passar minutos, sempre normalizado (m de 0
// a 59, h de 0 a 23), e guarda em *dias quantas vezes passou da meia-noite.
// Teste os três voos:
//
//   Manaus 22:45 + 230 min (3h50)
//   Belém 06:10 + 95 min
//   Rio Branco 23:30 + 1500 min (uma viagem com conexões)
//
//   Saída esperada:
//   Manaus 22:45 + 230 min = 02:35 (+1 dia)
//   Belém 06:10 + 95 min = 07:45
//   Rio Branco 23:30 + 1500 min = 00:30 (+2 dias)
//
// Dicas:
// 1. Converta tudo para minutos desde 00:00: total = ini.h * 60 + ini.m +
//    minutos.
// 2. *dias = total / (24 * 60); o resto da divisão por 1440 dá os minutos
//    do dia, que viram h e m com / 60 e % 60.
// 3. Mostre com %02d para sair 02:35 e não 2:35.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
