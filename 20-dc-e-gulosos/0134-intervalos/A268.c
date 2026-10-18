// A268 · Juntando horários: a agenda livre do consultório

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ini, fim; // minutos desde a meia-noite, [ini, fim)
} Bloco;

int por_inicio(const void *a, const void *b) {
    const Bloco *x = a;
    const Bloco *y = b;
    return (x->ini > y->ini) - (x->ini < y->ini);
}

void hora(int m) {
    printf("%02d:%02d", m / 60, m % 60);
}

int main(void) {
    // consultas marcadas por três atendentes, fora de ordem e encavaladas
    Bloco c[] = {
        {9 * 60, 10 * 60},       {14 * 60, 15 * 60 + 30}, {9 * 60 + 30, 11 * 60},
        {16 * 60, 17 * 60},      {11 * 60, 11 * 60 + 45}, {15 * 60, 15 * 60 + 45},
        {13 * 60, 13 * 60 + 30},
    };
    int n = 7;

    // ordena pelo início e vai "engolindo" quem começa antes do fim atual
    qsort(c, n, sizeof c[0], por_inicio);
    Bloco junto[7];
    int k = 0;
    junto[0] = c[0];
    for (int i = 1; i < n; i++) {
        if (c[i].ini <= junto[k].fim) {        // encosta ou sobrepõe: junta
            if (c[i].fim > junto[k].fim) {
                junto[k].fim = c[i].fim;
            }
        } else {
            junto[++k] = c[i];                 // buraco: começa outro bloco
        }
    }
    k++;

    printf("Ocupado:");
    for (int i = 0; i < k; i++) {
        printf("  ");
        hora(junto[i].ini);
        printf("-");
        hora(junto[i].fim);
    }
    // o que sobra entre 08:00 e 18:00 é horário livre
    printf("\nLivre:  ");
    int de = 8 * 60;
    for (int i = 0; i <= k; i++) {
        int ate = i < k ? junto[i].ini : 18 * 60;
        if (ate > de) {
            printf("  ");
            hora(de);
            printf("-");
            hora(ate);
        }
        if (i < k) {
            de = junto[i].fim;
        }
    }
    printf("\n");
    return 0;
}
// Saída:
// Ocupado:  09:00-11:45  13:00-13:30  14:00-15:45  16:00-17:00
// Livre:    08:00-09:00  11:45-13:00  13:30-14:00  15:45-16:00  17:00-18:00
