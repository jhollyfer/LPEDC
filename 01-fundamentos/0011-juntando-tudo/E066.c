// 0011 · Juntando tudo
// Exercício E066 · ★★★
//
// O app de entregas diz "chega em 135 minutos". Leia a hora atual (hh:mm) e
// os minutos de espera e mostre a hora da chegada, no formato hh:mm, e
// quantos dias depois de hoje ela cai. Sem if: só aritmética.
//
//   Exemplo de execução:
//   Agora (hh:mm): 22:45
//   Espera (min): 135
//   Chega às 01:00, 1 dia(s) depois
//
// Teste também 08:10 com 50 minutos (09:00, 0 dias) e 23:59 com 2881
// minutos (00:00, 3 dias).
//
// Dicas:
// 1. Converta tudo para minutos desde a meia-noite: hora * 60 + minuto.
// 2. Some a espera. Um dia tem 1440 minutos: total / 1440 são os dias, e
//    total % 1440 é a hora do dia em minutos.
// 3. Mostre com %02d:%02d.
// 4. Resposta esperada: 22:45 + 135 = 1365 + 135 = 1500 minutos; 1500 /
//    1440 = 1 dia; 1500 % 1440 = 60 minutos = 01:00.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
