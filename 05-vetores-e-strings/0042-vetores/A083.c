// A083 · Os passos da semana

#include <stdio.h>

#define DIAS 7

int main(void) {
    // 7 gavetas de int, uma por dia; o índice vai de 0 a 6
    int passos[DIAS] = {8200, 10450, 6300, 12000, 9100, 15300, 7400};

    int total = 0;
    int maior = passos[0]; // começa pelo primeiro, não por 0
    int dia_maior = 0;

    for (int i = 0; i < DIAS; i++) { // i < DIAS: o último índice é 6
        total += passos[i];
        if (passos[i] > maior) {
            maior = passos[i];
            dia_maior = i;
        }
    }

    printf("Total: %d passos\n", total);
    printf("Média: %.1f por dia\n", (double) total / DIAS);
    printf("Recorde: %d passos no dia %d\n", maior, dia_maior + 1);
    return 0;
}
// Saída:
// Total: 68750 passos
// Média: 9821.4 por dia
// Recorde: 15300 passos no dia 6
