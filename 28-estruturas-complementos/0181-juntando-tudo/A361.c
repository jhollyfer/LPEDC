// A361 · Um dia cheio, marcado em ordem

#include <stdio.h>
#include "agenda.h"

int main(void) {
    Agenda *a = ag_cria();
    if (a == NULL) {
        return 1;
    }
    // 44 consultas de 15 em 15 minutos, das 07:00 às 17:45, marcadas em
    // ordem de horário: o pior caso para uma BST comum
    int n = 0;
    unsigned semente = 2026; // gerador simples: CPFs inventados, sempre os mesmos
    for (int hora = 7; hora <= 17; hora++) {
        for (int min = 0; min < 60; min += 15) {
            semente = semente * 1103515245u + 12345u;
            int cpf = 100000000 + (int)((semente >> 4) % 800000000u);
            char nome[24];
            snprintf(nome, sizeof nome, "Paciente %02d", n + 1);
            if (ag_cadastra(a, cpf, nome)) {
                ag_marca(a, hora * 100 + min, cpf);
            }
            n++;
        }
    }
    ag_estatisticas(a);
    printf("(uma BST comum, com os horários em ordem, teria altura %d)\n", n - 1);

    int tarde[50];
    int k = ag_intervalo(a, 1600, 1759, tarde, 50);
    printf("Depois das 16h: %d consultas:", k);
    for (int i = 0; i < k; i++) {
        printf(" %02d:%02d", tarde[i] / 100, tarde[i] % 100);
    }
    printf("\n");
    ag_libera(a);
    return 0;
}
// Saída:
// Horários na árvore: 44 (44 com consulta) | altura 7 | altura negra 4
// Pacientes: 44 em 101 posições | média de sondagens: 1.36
// Na fila de espera: 0
// (uma BST comum, com os horários em ordem, teria altura 43)
// Depois das 16h: 8 consultas: 16:00 16:15 16:30 16:45 17:00 17:15 17:30 17:45
