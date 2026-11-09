// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2708 · ★☆☆ · Dia útil ou fim de semana

#include <stdio.h>

typedef enum { DOM, SEG, TER, QUA, QUI, SEX, SAB } Dia;

const char *nomes[] = {"DOM", "SEG", "TER", "QUA", "QUI", "SEX", "SAB"};

const char *tipo(Dia d) {
    switch (d) {
    case DOM:
    case SAB:
        return "fim de semana";
    default:
        return "dia útil";
    }
}

int main(void) {
    Dia testes[] = {DOM, QUA, SAB};
    for (int i = 0; i < 3; i++) {
        printf("%s: %s\n", nomes[testes[i]], tipo(testes[i]));
    }
    Dia d = QUA + 2;
    printf("QUA + 2 = %s (%d)\n", nomes[d], d);
    return 0;
}
