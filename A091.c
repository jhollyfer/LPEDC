// A091 · O plantão que vira o relógio

#include <stdio.h>

// parâmetro de ida E volta: lê os valores do main e escreve de volta
void normaliza(int *horas, int *minutos) {
    *horas += *minutos / 60; // cada 60 minutos viram uma hora
    *minutos %= 60;
    *horas %= 24;            // passou da meia-noite, recomeça do 0
}

// horas e minutos já SÃO endereços: repassa para normaliza sem &
void soma_minutos(int *horas, int *minutos, int extra) {
    *minutos += extra;
    normaliza(horas, minutos);
}

int main(void) {
    int h = 22, m = 40; // começo do plantão no hospital

    soma_minutos(&h, &m, 95); // o primeiro atendimento durou 95 minutos
    printf("Fim do 1º atendimento: %02d:%02d\n", h, m);

    soma_minutos(&h, &m, 50);
    printf("Fim do 2º atendimento: %02d:%02d\n", h, m);

    // normaliza sozinha também arruma um horário anotado errado
    int h2 = 9, m2 = 135; // alguém anotou 9h135
    normaliza(&h2, &m2);
    printf("9h135 arrumado: %02d:%02d\n", h2, m2);
    return 0;
}
// Saída:
// Fim do 1º atendimento: 00:15
// Fim do 2º atendimento: 01:05
// 9h135 arrumado: 11:15
