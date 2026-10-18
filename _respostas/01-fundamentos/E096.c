// 0016 · Juntando tudo
// Exercício E096 · ★★★

#include <stdio.h>

#define MINUTOS_POR_DIA 1440

int main(void) {
    int hora = 0, minuto = 0, espera = 0;

    printf("Agora (hh:mm): ");
    scanf("%d:%d", &hora, &minuto);
    printf("Espera (min): ");
    scanf("%d", &espera);

    int total = hora * 60 + minuto + espera;   // minutos desde a meia-noite de hoje
    int dias = total / MINUTOS_POR_DIA;
    int no_dia = total % MINUTOS_POR_DIA;

    printf("Chega às %02d:%02d, %d dia(s) depois\n", no_dia / 60, no_dia % 60, dias);
    return 0;
}
