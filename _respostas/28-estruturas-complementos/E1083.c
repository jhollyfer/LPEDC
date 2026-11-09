// 0181 · Juntando tudo
// Exercício E1083 · ★★☆

#include <stdio.h>
#include "agenda.h"

int main(void) {
    Agenda *a = ag_cria();
    if (a == NULL) {
        return 1;
    }
    int horarios[] = {730, 1115, 1200, 1945, 900, 1400, 1830, 1159, 1600, 2100};
    for (int i = 0; i < 10; i++) {
        int cpf = 500000001 + i;
        char nome[24];
        snprintf(nome, sizeof nome, "P%d", i + 1);
        ag_cadastra(a, cpf, nome);
        ag_marca(a, horarios[i], cpf);
    }
    const char *turnos[] = {"manhã", "tarde", "noite"};
    int de[] = {0, 1200, 1800}, ate[] = {1159, 1759, 2359};
    int h[20];
    for (int t = 0; t < 3; t++) {
        int k = ag_intervalo(a, de[t], ate[t], h, 20);
        printf("%s (%d):", turnos[t], k);
        for (int i = 0; i < k; i++) {
            printf(" %02d:%02d", h[i] / 100, h[i] % 100);
        }
        printf("\n");
    }
    ag_libera(a);
    return 0;
}
