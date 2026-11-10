// A077 · O primeiro horário livre da agenda

#include <stdio.h>
#include <stdbool.h>

#define DIAS 5
#define HORARIOS 4

int main(void) {
    // linhas: segunda a sexta; colunas: 8h, 10h, 14h, 16h (1 = marcado)
    int agenda[DIAS][HORARIOS] = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 0, 1, 0},
        {0, 0, 1, 1},
    };
    int horas[HORARIOS] = {8, 10, 14, 16};

    // busca em duas dimensões: o laço de fora para assim que achar
    bool achou = false;
    int dia = 0, hora = 0;
    for (int l = 0; l < DIAS && !achou; l++) {
        for (int c = 0; c < HORARIOS && !achou; c++) {
            if (agenda[l][c] == 0) {
                achou = true;
                dia = l;
                hora = c;
            }
        }
    }

    if (achou) {
        printf("Primeiro livre: dia %d às %dh\n", dia + 1, horas[hora]);
        // na memória, as linhas vêm uma atrás da outra:
        // a casa [l][c] é a de número l * HORARIOS + c, contando do 0
        printf("É a casa %d das %d da matriz\n", dia * HORARIOS + hora, DIAS * HORARIOS);
    } else {
        printf("Agenda lotada.\n");
    }
    printf("A matriz ocupa %zu bytes: %d int seguidos\n", sizeof(agenda), DIAS * HORARIOS);
    return 0;
}
// Saída:
// Primeiro livre: dia 4 às 10h
// É a casa 13 das 20 da matriz
// A matriz ocupa 80 bytes: 20 int seguidos
